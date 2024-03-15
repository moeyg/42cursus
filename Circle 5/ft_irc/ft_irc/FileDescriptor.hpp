#ifndef __FILEDESCRIPTOR_HPP__
#define __FILEDESCRIPTOR_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Channel.hpp"

#define ISOPER	bool
#define SucNick	0
#define SucPass	1
#define SucUser	2
#define Welcome	3

class Channel;

class FileDescriptor
{
public:
	FileDescriptor(int fd = -1, std::string nick = "",
					std::string name = "", std::string hostname = "");
	~FileDescriptor(void);
	FileDescriptor(const FileDescriptor& other);
	FileDescriptor& operator= (const FileDescriptor& other);

public:
	const int& getFd(void) const;
	const std::string& getNick(void) const;
	const std::string& getUser(void) const;
	const std::string& getHostname(void) const;
	const std::vector<Channel>& getChannel(void) const;

	bool isConnection(void) const;
	bool isSuccessNick(void) const;
	bool isSuccessPass(void) const;
	bool isSuccessUser(void) const;
	bool getWelcome(void) const;

	void setFd(int fd);
	void setNick(std::string nick);
	void setName(std::string name);
	void setHostname(std::string hostname);

	void successNick(void);
	void successPass(void);
	void successUser(void);
	void setWelcome(void);

	void joinChannel(Channel channel);
	void partChannel(std::string channelName);

	const std::string& getSendMsg(void) const;
	void addSendMsg(std::string msg);
	void clearSendMsg(void);

private:
	int			_fd;
	std::string	_nick;
	std::string	_name;
	std::string	_hostname;
	std::vector<Channel> _channel;
	std::string _sendMsg;

	bool _isConnected[4];
};

#endif
