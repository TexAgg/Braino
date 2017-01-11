#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

namespace braino
{

// I used VARCHAR(191) in the database.
const int DB_STRING_LENGTH = 191;

class Message
{
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

	// Getter function for message;
	std::string get_message();
	// Return the size of the replies vector.
	int replies_size();
	
}; // !Message

} // !braino

#endif // !MESSAGE_HPP