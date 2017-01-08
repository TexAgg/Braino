#include "Message.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace braino
{

Message::Message(std::string message):
	message(message)
{
	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	sql::ResultSet *res = NULL;
	
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "apple");
	con->setSchema("braino");

	// pls dont sql inject.
	std::string query = "SELECT `response` FROM `responses` WHERE (SELECT `parent` FROM `phrases` WHERE `phrase` LIKE \"" + message + "\")";
	stmt = con->createStatement();
  	res = stmt->executeQuery(query);

	while (res->next())
	{
		// http://stackoverflow.com/a/31135869/5415895
		replies.push_back(res->getString("response").c_str());
	}

	delete res;
	delete stmt;
	delete con;
}

Message::~Message()
{
}

std::string Message::respond()
{
	if (replies.empty())
		return "I don't understand.";

	srand(time(NULL));
	int rank = rand() % replies.size();
	return replies[rank];
}

}