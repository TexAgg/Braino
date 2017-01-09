#include "Logger.hpp"

namespace braino
{

Logger::Logger(std::string filename):
	outfile(filename)
{

}

Logger::~Logger()
{
	outfile.close();
}

}