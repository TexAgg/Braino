#include "Message.hpp"
#include <memory>
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

Message::Message(std::string message): message(message)
{
	clean_message();
	get_replies();
}

Message::~Message()
{
}

void Message::get_replies()
{
	// Reset the replies.
	replies.clear();
	
	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
	// Garbage collection for driver is handled by con, no need for unique_ptr.
	sql::mysql::MySQL_Driver* driver = NULL;
	std::unique_ptr<sql::Connection> con;
	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-prepared-statements.html
	std::unique_ptr<sql::PreparedStatement> prep_stmt;
	std::unique_ptr<sql::ResultSet> res;
	
	driver = sql::mysql::get_mysql_driver_instance();
	con.reset(driver->connect("tcp://127.0.0.1:3306", "root", "apple"));
	// Select the database to use.
	con->setSchema("braino");

	std::string query = "SELECT `response` FROM `responses` WHERE `parent` IN (SELECT `id` FROM `phrases` WHERE `phrase` LIKE (?))";
	// Create prepared statement.
	prep_stmt.reset(con->prepareStatement(query));
	// Set variables.
	std::string phrase = "%" + message + "%";
	prep_stmt->setString(1, phrase);
	// Execute statement.
	res.reset(prep_stmt->executeQuery());

	while (res->next())
	{
		// http://stackoverflow.com/a/31135869/5415895
		std::string response = res->getString("response").c_str();
		// No empty strings in the response.
		if (!response.empty())
			replies.push_back(response);
	}
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

void Message::clean_message()
{
	// Trim leading and trailing whitespace.
	boost::trim(message);
	// Fit the message to database specifications.
	if (message.size() > DB_STRING_LENGTH)
		message.resize(DB_STRING_LENGTH);
}

std::string Message::get_message()
{
	return message;
}

int Message::replies_size()
{
	return replies.size();
}

} // !braino