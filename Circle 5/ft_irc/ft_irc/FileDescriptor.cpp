#include "FileDescriptor.hpp"

FileDescriptor::FileDescriptor(int fd, std::string nick, std::string name, std::string hostname)
: _fd(fd), _nick(nick), _name(name), _hostname(hostname), _sendMsg("")
{
	for (int i = 0; i < 4; i++)
		_isConnected[i] = false;
}

FileDescriptor::FileDescriptor(const FileDescriptor& other)
: _fd(other._fd), _nick(other._nick), _name(other._name),
_hostname(other._hostname), _channel(other._channel), _sendMsg(other._sendMsg)
{
	for (int i = 0; i < 4; i++)
		_isConnected[i] = other._isConnected[i];
}

FileDescriptor::~FileDescriptor(void) { }

FileDescriptor& FileDescriptor::operator= (const FileDescriptor& other)
{
	_fd = other._fd;
	_nick = other._nick;
	_name = other._name;
	_hostname = other._hostname;
	_channel = other._channel;

	for (int i = 0; i < 4; i++)
		_isConnected[i] = other._isConnected[i];

	_sendMsg = other._sendMsg;

	return *this;
}

const int& FileDescriptor::getFd(void) const
{
	return _fd;
}

const std::string& FileDescriptor::getNick(void) const
{
	return _nick;
}

const std::string& FileDescriptor::getUser(void) const
{
	return _name;
}

const std::string& FileDescriptor::getHostname(void) const
{
	return _hostname;
}

const std::vector<Channel>& FileDescriptor::getChannel(void) const
{
	return _channel;
}

bool FileDescriptor::isConnection(void) const
{
	for (int i = 0; i < 3; i++)
		if (!_isConnected[i])
			return false;

	return true;
}

bool FileDescriptor::isSuccessNick(void) const
{
	return _isConnected[SucNick];
}

bool FileDescriptor::isSuccessPass(void) const
{
	return _isConnected[SucPass];
}

bool FileDescriptor::isSuccessUser(void) const
{
	return _isConnected[SucUser];
}

bool FileDescriptor::getWelcome(void) const
{
	return _isConnected[Welcome];
}

void FileDescriptor::setFd(int fd)
{
	_fd = fd;
}

void FileDescriptor::setNick(std::string nick)
{
	_nick = nick;
}

void FileDescriptor::setName(std::string name)
{
	_name = name;
}

void FileDescriptor::setHostname(std::string hostname)
{
	_hostname = hostname;
}

void FileDescriptor::successNick(void)
{
	_isConnected[SucNick] = true;
}

void FileDescriptor::successPass(void)
{
	_isConnected[SucPass] = true;
}

void FileDescriptor::successUser(void)
{
	_isConnected[SucUser] = true;
}

void FileDescriptor::setWelcome(void)
{
	_isConnected[Welcome] = true;
}

void FileDescriptor::joinChannel(Channel channel)
{
	_channel.push_back(channel);
}

void FileDescriptor::partChannel(std::string channelName)
{
	std::vector<Channel>::iterator it;

	for (it = _channel.begin(); it != _channel.end(); it++)
	{
		if (it->getChannelName() == channelName) break;
	}

	if (it == _channel.end()) return ;

	_channel.erase(it);
}

const std::string& FileDescriptor::getSendMsg(void) const
{
	return _sendMsg;
}

void FileDescriptor::addSendMsg(std::string msg)
{
	_sendMsg.append(msg);
}

void FileDescriptor::clearSendMsg(void)
{
	_sendMsg.clear();
}