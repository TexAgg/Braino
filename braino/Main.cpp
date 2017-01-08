#include <iostream>
#include <string>
#include "Message.hpp"

int main()
{
	std::cout << "Hey" << std::endl;

	// The only way to leave the conversation is to kill Braino.
	while (true)
	{
		std::string response;
		std::getline(std::cin, response);
		braino::Message message(response);
		std::cout << message.respond() << std::endl;
	}
}