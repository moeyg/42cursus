#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <iostream>
#include <map>
#include <vector>

#include "Multiplex.hpp"
#include "recvData.hpp"
#include "FileDescriptor.hpp"
#include "StringHandle.hpp"
#include "CommandResponses.hpp"
#include "EventHandler.hpp"
#include "Channel.hpp"

class Server
{
public:
	Server(int ac, char**av);
	~Server(void);
	void start(void);
	void closeClient(int fd);
	void deleteBuffer(void);

private:
	std::string _pass;
	std::string _port;
	Multiplex _multiplex;
	std::map<int, FileDescriptor> _fdList;
	std::map<std::string, Channel> _channelList;
	std::vector<recvData> _recvBuffer;
};

#endif
