/*
	Main.cpp
	Main interface for Braino.
*/

#include <iostream>
#include <string>
#include "Message.hpp"
#include "Logger.hpp"

int main()
{
	braino::Logger logger("log.txt");
	
	const std::string greeting = "Hey";
	std::cout << "Braino: " << greeting << std::endl;
	logger.write_entry("Braino", greeting);

	// The only way to leave the conversation is to kill Braino.
	while (true)
	{
		std::string response;
		std::getline(std::cin, response);
		logger.write_entry("User", response);
		braino::Message message(response);
		std::string braino_response = message.respond();
		std::cout << "Braino: " << braino_response << std::endl;
		logger.write_entry("Braino", braino_response);
	}

	return 0;
}