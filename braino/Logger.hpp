#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

namespace braino
{

/*
	Class for the chat to a log file.
	The file is overwritten each time.
*/
class Logger
{
	std::ofstream outfile;

public:
	Logger(std::string filename);
	~Logger();

	void write_entry(std::string sender, std::string message);
	
};

}

#endif // !LOGGER_HPP