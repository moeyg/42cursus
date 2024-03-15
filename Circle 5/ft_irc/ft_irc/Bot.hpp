#ifndef __BOT_HPP__
#define __BOT_HPP__

#include <arpa/inet.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <vector>

#define NOT_COMMAND 0
#define HELP 1
#define INFO 2

class Bot
{
public:
	Bot(std::string msg, std::string& port);
	~Bot(void);

	std::vector<std::string> process(void);
	int checkCommand(void);
	std::vector<std::string> help(void);
	std::vector<std::string> info(void);

private:
	std::string		_msg;
	std::string		_command;
	std::string		_argument;
	std::string&	_port;
};

#endif
