#include "Channel.hpp"

Channel::Channel(std::string channelName, std::map<int, FileDescriptor>& fds)
: _channelName(channelName), _fds(fds) { }

Channel::Channel(const Channel& obj)
: _channelName(obj._channelName), _connectList(obj._connectList), _fds(obj._fds) { }

Channel::~Channel(void) { }

Channel& Channel::operator=(const Channel& channel)
{
	_channelName = channel._channelName;
	_connectList = channel._connectList;
	_fds = channel._fds;
	return *this;
}

bool	Channel::join(int fd)
{
	_connectList.insert(std::pair<int, FileDescriptor>(_fds.find(fd)->first, _fds.find(fd)->second));
	_fds.find(fd)->second.joinChannel(*this);

	return true;
}

bool	Channel::isInChannel(int fd)
{
	std::map<int, FileDescriptor>::iterator	it;

	it = _connectList.find(fd);
	if (it == _connectList.end())
		return false;

	return true;
}

void	Channel::leave(int fd)
{
	std::map<int, FileDescriptor>::iterator	it;

	it = _connectList.find(fd);
	if (it == _connectList.end()) return;
	if (_operatorFd == fd) _operatorFd = -1;

	_connectList.erase(it);
	_fds.find(fd)->second.partChannel(_channelName);
}

std::vector<int>	Channel::getList(void)
{
	std::vector<int>	response;
	std::map<int, FileDescriptor>::iterator	it = _connectList.begin();

	for (; it != _connectList.end(); it++)
		response.push_back(it->first);

	return response;
}

std::vector<std::string>	Channel::getNick(void)
{
	std::vector<std::string>	response;
	std::map<int, FileDescriptor>::iterator it = _connectList.begin();

	for (; it != _connectList.end(); it++)
		response.push_back(it->second.getNick());

	return response;
}

std::string	Channel::getChannelName(void) const
{
	return _channelName;
}

int	Channel::getOperator() const
{
	return _operatorFd;
}

void	Channel::setOperator(int fd)
{
	_operatorFd = fd;
}
