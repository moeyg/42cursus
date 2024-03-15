#ifndef __MESSAGEHANDLER_HPP__
#define __MESSAGEHANDLER_HPP__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>

#include "Bot.hpp"
#include "Channel.hpp"
#include "CommandResponses.hpp"
#include "FileDescriptor.hpp"
#include "recvData.hpp"

#define MESSAGE		91
#define PREFIX		92
#define COMMAND		93
#define SPACE		94
#define PARAMS		95
#define MIDDLE		96
#define TRAILING	97
#define CRLF		98
#define COLON		922
#define BROADCAST 	-1

enum cmd {PASS_, NICK_, USER_, QUIT_, JOIN_, KICK_, PART_, NAMES_, PRIVMSG_};

class EventHandler
{
public:
	EventHandler(recvData rec, std::map<int, FileDescriptor>& fdList,
				std::map<std::string, Channel>& channelList,
				std::string& pass, std::string& port);

	std::set<int>	getFdTo() const;
	std::string		getSendMsg() const;
	bool			isInFd(int fd);

private:
	EventHandler(const EventHandler& other);
	EventHandler& operator=(const EventHandler& other);

	std::size_t findPos(std::string str, std::string del);

	void tokenize(void);
	void messageF(void);
	void paramsF(void);
	void cmdPass(void);
	void cmdNick(void);
	void cmdUser(void);
	void cmdQuit(void);
	void cmdJoin(void);
	void cmdKick(void);
	void cmdPart(void);
	void cmdNames(void);
	void cmdPrivmsg(void);
	void pushChannel(std::string channel);
	void cmdHandler(void);
	void sendMessage(std::string msg);
	void connectServer(void);

	int  getFd(std::string nick);
	bool checkNick(std::string nick);

	std::set<int> joinChannel(std::string channelName, int fd);

	std::string		_msg;
	std::string		_sendMsg;
	int				_fdFrom;
	std::set<int>	_fdTo;

	std::vector<std::pair<int, std::string> >	_parse;

	std::map<int, FileDescriptor>&	_fdList;
	std::map<std::string, Channel>&	_channelList;

	std::string&	_pass;
	std::string&	_port;
};

#endif
