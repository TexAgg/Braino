#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace braino
{

class Message
{
	std::string message;
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;

public:
	Message(std::string message);
	~Message();
};

} // !braino

#endif // !MESSAGE_HPP