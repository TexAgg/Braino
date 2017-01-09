#include "Logger.hpp"
#include <time.h>

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

void Logger::write_entry(std::string sender, std::string message)
{
	// https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
	time_t now = time(0);
	std::string dt = ctime(&now);
	// Remove newline at the end.
	dt.resize(dt.size()-1);
	outfile << sender << " (" << dt << "): " << message << std::endl;
}

}