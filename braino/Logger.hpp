#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

namespace braino
{

class Logger
{
	std::ofstream outfile;

public:
	Logger(std::string filename);
	~Logger();
	
};

}

#endif // !LOGGER_HPP