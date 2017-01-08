#include "Message.hpp"

namespace braino
{

Message::Message(std::string message):
message(message)
{
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "apple");
}

Message::~Message()
{
	delete con;
}

}