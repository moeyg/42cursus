#ifndef __CHANNEL_HPP__
#define __CHANNEL_HPP__

#include <map>
#include <string>

#include "FileDescriptor.hpp"

class FileDescriptor;

class Channel
{
public:
	Channel(std::string channelName, std::map<int, FileDescriptor>& fds);
	Channel(const Channel& obj);
	~Channel(void);
	Channel& operator=(const Channel& obj);

	bool	join(int fd);
	bool	isInChannel(int fd);
	void	leave(int fd);
	void	setOperator(int fd);

	std::vector<int>			getList(void);
	std::vector<std::string>	getNick(void);
	std::string					getChannelName(void) const;
	int							getOperator(void) const;

private:
	std::string						_channelName;
	std::map<int, FileDescriptor>	_connectList;
	std::map<int, FileDescriptor>&	_fds;
	int								_operatorFd;
};

#endif
