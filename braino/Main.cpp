/*
	Main.cpp
	Main interface for Braino.
*/

#include <iostream>
#include <string>
#include "Message.hpp"

int main()
{
	std::cout << "Braino: Hey" << std::endl;

	// The only way to leave the conversation is to kill Braino.
	while (true)
	{
		std::string response;
		std::getline(std::cin, response);
		braino::Message message(response);
		std::cout << "Braino: " << message.respond() << std::endl;
	}

	return 0;
}