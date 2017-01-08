#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

namespace braino
{

class Message
{
	// The message that was sent.
	std::string message;
	// A vector of replies, retrieved from the database.
	std::vector<std::string> replies;

public:
	// Pass to the constructor the message you want to send.
	Message(std::string message);
	~Message();
	
	// Return a random response from the replies vector.
	std::string respond();
	
}; // !Message

} // !braino

#endif // !MESSAGE_HPP