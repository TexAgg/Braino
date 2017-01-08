#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

namespace braino
{

class Message
{
	std::string message;
	std::vector<std::string> replies;

public:
	Message(std::string message);
	~Message();

	std::string respond();
};

} // !braino

#endif // !MESSAGE_HPP