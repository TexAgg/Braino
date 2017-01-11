#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>

namespace braino
{

// I used VARCHAR(191) in the database.
const int DB_STRING_LENGTH = 191;

class Message
{
	// http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
	// Garbage collection for driver is handled by con, no need for unique_ptr.
	sql::mysql::MySQL_Driver* driver = NULL;
	std::unique_ptr<sql::Connection> con;	
	
	// The message that was sent.
	std::string message;
	// A vector of replies, retrieved from the database.
	std::vector<std::string> replies;

	// Populate the replies vector.
	void get_replies();
	// Strip whitespace and resize the message if needed.
	void clean_message();

public:
	// Pass to the constructor the message you want to send.
	Message(std::string message);
	~Message();
	
	// Return a random response from the replies vector.
	std::string respond();

	// Sets the current message for the object. This resets the replies vector.
	void set_message(std::string new_message);
	// Getter function for message;
	std::string get_message();
	// Return the size of the replies vector.
	int replies_size();
	
}; // !Message

} // !braino

#endif // !MESSAGE_HPP