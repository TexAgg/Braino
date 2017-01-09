#include "Message.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <boost/algorithm/string.hpp>
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
	// Trim leading and trailing whitespace.
	boost::trim(message);
	if (message.size() > DB_STRING_LENGTH)
		message.resize(DB_STRING_LENGTH);

	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-prepared-statements.html
	sql::PreparedStatement* prep_stmt = NULL;
	sql::ResultSet *res = NULL;
	
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "apple");
	con->setSchema("braino");

	std::string query = "SELECT `response` FROM `responses` WHERE (SELECT `parent` FROM `phrases` WHERE `phrase` LIKE (?))";
	// Create prepared statement.
	prep_stmt = con->prepareStatement(query);
	// Set variables.
	prep_stmt->setString(1, message);
	// Execute statement.
  	res = prep_stmt->executeQuery();

	while (res->next())
	{
		// http://stackoverflow.com/a/31135869/5415895
		replies.push_back(res->getString("response").c_str());
	}

	delete res;
	delete prep_stmt;
	delete con;
}

Message::~Message()
{
}

std::string Message::respond()
{
	if (replies.empty())
		return "I don't understand.";

	// Seed the random thing.
	srand(time(NULL));
	// Get a random position in the replies vector.
	int rank = rand() % replies.size();
	return replies[rank];
}

} // !braino