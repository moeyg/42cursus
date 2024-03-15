#include "EventHandler.hpp"

void	EventHandler::pushChannel(std::string channel)
{
	std::map<std::string, Channel>::iterator it;

	it = _channelList.find(channel);
	if (it == _channelList.end()) return;

	std::vector<int> fds = it->second.getList();
	for(std::vector<int>::iterator it = fds.begin(); it != fds.end(); it++)
		_fdTo.insert(*it);

	return;
}

int	 EventHandler::getFd(std::string nick)
{
	for (std::map<int, FileDescriptor>::iterator it =_fdList.begin(); it != _fdList.end(); it++)
	{
		if (it->second.getNick() == nick)
			return it->first;
	}

	return -1;
}

bool	EventHandler::checkNick(std::string nick)
{
	if (!isalpha(nick[0])) return false;

	for (size_t i = 1; i < nick.size(); i++)
	{
		if (!isalnum(nick[i]) && nick[i] != '_' && nick[i] != '-' && nick[i] != '['
			&& nick[i] != ']' && nick[i] != '\\' && nick[i] != '`'
			&& nick[i] != '^' && nick[i] != '{' && nick[i] != '}')
			return false;
	}
	return true;
}

void EventHandler::connectServer(void)
{
	FileDescriptor& tmp = _fdList.find(_fdFrom)->second;
	if (tmp.isConnection() && !tmp.getWelcome())
	{
		tmp.setWelcome();
		_sendMsg = RPL_WELCOME + tmp.getNick() + " :Welcome to the Internet Relay Network\n" + tmp.getNick() + "!" + tmp.getUser() + "@" +tmp.getHostname() + "\r\n";
		sendMessage(_sendMsg);
		_sendMsg = RPL_YOURHOST;
		sendMessage(_sendMsg);
		_sendMsg = RPL_CREATED;
		sendMessage(_sendMsg);
		_sendMsg = RPL_MYINFO;
		sendMessage(_sendMsg);
	}
}

void EventHandler::cmdPass(void)
{
	_fdTo.insert(_fdFrom);
	if (_fdList.find(_fdFrom)->second.isSuccessPass())
	{
		_sendMsg.append(ERR_ALREADYREGISTRED);
		sendMessage(_sendMsg);
		return;
	}

	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end())
	{
		if (it->first == MIDDLE) break;
		it++;
	}

	if (it == _parse.end())
	{
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return;
	}
	else if (_pass == it->second)
	{
		_fdList.find(_fdFrom)->second.successPass();
		connectServer();
	}
	else
	{
		_sendMsg.append(ERR_PASSWDMISMATCH);
		sendMessage(_sendMsg);
	}
}
void EventHandler::cmdNick(void)
{
	_fdTo.insert(_fdFrom);

	std::map<int, FileDescriptor>::iterator fditer = _fdList.find(_fdFrom);

	if (fditer == _fdList.end()) return;

	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end())
	{
		if (it->first == MIDDLE) break;
		it++;
	}

	if (it == _parse.end())
	{
		_sendMsg = ERR_NONICKNAMEGIVEN;
		sendMessage(_sendMsg);
		return;
	}
	else if (getFd(it->second) != -1)
	{
		if ("" != fditer->second.getNick())
			_sendMsg = ERR_NICKNAMEINUSE + fditer->second.getNick() + " " + it->second + " :Nickname is already in use\r\n";
		else
		{
			_sendMsg = ERR_NICKNAMEINUSE;
			_sendMsg.append("* " + it->second + " :Nickname is already in use\r\n");
		}
		sendMessage(_sendMsg);
		return;
	}
	else if (checkNick(it->second) == false)
	{
		_sendMsg = ERR_ERRONEUSNICKNAME + _parse.begin()->second + " :Erroneous nickname\r\n";
		sendMessage(_sendMsg);
		return;
	}

	std::vector<Channel> channels = fditer->second.getChannel();

	for(std::vector<Channel>::iterator iter = channels.begin(); iter != channels.end(); iter++)
		pushChannel(iter->getChannelName());

	if (!fditer->second.getWelcome())
	{
		fditer->second.setNick(it->second);
		fditer->second.successNick();
		connectServer();
	}
	else
	{
		_sendMsg = ":"  + fditer->second.getNick() + "!" + fditer->second.getUser() + "@" + fditer->second.getHostname() + " " + _parse.begin()->second + " :" + it->second + "\r\n";
		fditer->second.setNick(it->second);
		sendMessage(_sendMsg);
	}
}

void EventHandler::cmdUser(void)
{
	_fdTo.insert(_fdFrom);

	std::string info[4];

	int i = 0;
	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end() && it->first != CRLF)
	{
		if (it->first == MIDDLE)
		{
			info[i] = it->second;
			i++;
			if (i == 4) break;
		}
		else if (it->first == TRAILING && i > 2)
		{
			info[3] += it->second;
			i++;
		}
		it++;
	}

	if (it == _parse.end() || i < 4)
	{
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return;
	}

	std::map<int, FileDescriptor>::iterator iter = _fdList.find(_fdFrom);

	if (!iter->second.getWelcome())
	{
		iter->second.setName(info[0]);
		iter->second.setHostname(info[1]);
		iter->second.successUser();
		connectServer();
	}
	else
	{
		_sendMsg = ERR_ALREADYREGISTRED;
		sendMessage(_sendMsg);
	}
}

void EventHandler::cmdQuit(void) 
{
	std::map<int, FileDescriptor>::iterator it = _fdList.find(_fdFrom);
	if (it == _fdList.end()) return;

	std::map<std::string, Channel>::iterator channelIter = _channelList.begin();

	while (channelIter != _channelList.end())
	{
		std::vector<int>channelFd = channelIter->second.getList();

		if (std::count(channelFd.begin(), channelFd.end(), _fdFrom))
		{
			pushChannel(channelIter->first);
			std::map<std::string, Channel>::iterator tmpIter = channelIter;
			channelIter->second.leave(_fdFrom);
			channelIter++;

			if (tmpIter->second.getList().size() == 0)
				_channelList.erase(tmpIter);
		}
		else
			channelIter++;
	}

	_fdTo.erase(_fdFrom);
	_sendMsg = ":" + it->second.getNick() + "!" + it->second.getUser() + "@" + it->second.getHostname() + " " + _parse.begin()->second + " Quit: leaving\r\n";
	sendMessage(_sendMsg);
	_fdTo.erase(_fdTo.begin(), _fdTo.end());
	_fdList.erase(it);
	close(_fdFrom);
}

void EventHandler::cmdJoin(void)
{
	if (!_fdList.find(_fdFrom)->second.getWelcome()) return;

	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end())
	{
		if (it->first == MIDDLE) break;
		it++;
	}

	if (it == _parse.end())
	{
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return;
	}

	std::string channel = it->second;
	size_t start = 0;
	for (size_t i = 0; i < channel.size(); i++)
	{
		if (channel[i] == ',' && channel[start] != '#')
		{
			start = i + 1;
			continue;
		}
		else if ((channel[i] == ',' || i == channel.size() - 1) && channel[start] == '#')
		{
			std::string channelName = channel.substr(start + 1, i - start - (channel[i] == ','));

			if (_channelList.count(channelName) && _channelList.find(channelName)->second.isInChannel(_fdFrom)) continue;

			_fdTo = joinChannel(channelName, _fdFrom);
			start = i + 1;

			FileDescriptor &tmpfd = _fdList.find(_fdFrom)->second;
			_sendMsg = ":" + tmpfd.getNick() + "!" + tmpfd.getUser() + "@" + tmpfd.getHostname() + " " + _parse.begin()->second + " #" + channelName + "\r\n";

			sendMessage(_sendMsg);
			_fdTo.erase(_fdTo.begin(), _fdTo.end());
			_fdTo.insert(_fdFrom);
			_sendMsg = RPL_NAMREPLY + tmpfd.getNick() + " = #" + channelName;

			std::vector<std::string> tmp = _channelList.find(channelName)->second.getNick();
			int operFd = _channelList.find(channelName)->second.getOperator();
			std::string nick;

			if (operFd != -1)
			{
				nick = _fdList.find(operFd)->second.getNick();
				_sendMsg.append(" :@");
				_sendMsg.append(nick);
			}
			else
				_sendMsg.append(" :");

			_sendMsg.append(" ");

			for (size_t i = 0; i < tmp.size(); i++)
			{
				if (operFd != -1 && tmp[i] == nick) continue;
				_sendMsg.append(tmp[i]);
				_sendMsg.append(" ");
				std::cout << tmp[i] << " ";
			}
			std::cout << std::endl;
			_sendMsg.append("\r\n");
			sendMessage(_sendMsg);
			_sendMsg = RPL_ENDOFNAMES + tmpfd.getNick() + " #" + channelName + " :End of NAMES list\r\n";
			sendMessage(_sendMsg);
		}
	}
}

void EventHandler::cmdPart(void)
{
	if (!_fdList.find(_fdFrom)->second.getWelcome()) return;

	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end())
	{
		if (it->first == MIDDLE) break;
		it++;
	}

	if (it == _parse.end())
	{
		_fdTo.insert(_fdFrom);
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return;
	}

	std::string channel = it->second;
	size_t start = 0;

	for (size_t i = 0; i < channel.size(); i++)
	{
		if (channel[i] == ',' && channel[start] != '#')
		{
			start = i + 1;
			continue;
		}
		else if ((channel[i] == ',' || i == channel.size() - 1) && channel[start] == '#')
		{
			std::string channelName = channel.substr(start + 1, i - start - (channel[i] == ','));
			std::map<std::string, Channel>::iterator iter = _channelList.find(channelName);

			start = i + 1;
			if (iter == _channelList.end())
			{
				_fdTo.insert(_fdFrom);
				_sendMsg = ERR_NOSUCHCHANNEL + channelName + " :No such channel\r\n";
				sendMessage(_sendMsg);
				continue;
			}
			else if (!iter->second.isInChannel(_fdFrom))
			{
				_fdTo.insert(_fdFrom);
				_sendMsg = ERR_NOTONCHANNEL + channelName + " :Cannot send to channel\r\n";
				sendMessage(_sendMsg);
				continue;
			}
			else
			{
				pushChannel(channelName);
				FileDescriptor& tmpfd = _fdList.find(_fdFrom)->second;
				_sendMsg = ":" + tmpfd.getNick() + "!" + tmpfd.getUser() + "@" + tmpfd.getHostname() + " " + _parse.begin()->second + " #" + channelName + "\r\n";
				sendMessage(_sendMsg);
				tmpfd.partChannel(channelName);
				iter->second.leave(_fdFrom);
				if (iter->second.getList().empty()) _channelList.erase(iter);
			}

			_fdTo.erase(_fdTo.begin(), _fdTo.end());
		}
	}
}

void EventHandler::cmdNames(void)
{
	if (!_fdList.find(_fdFrom)->second.getWelcome()) return;

	_fdTo.insert(_fdFrom);
	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end())
	{
		if (it->first == MIDDLE) break;
		it++;
	}

	if (it == _parse.end())
	{
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return;
	}

	std::string channel = it->second;
	size_t start = 0;

	for (size_t i = 0; i < channel.size(); i++)
	{
		if (channel[i] == ',' && channel[start] != '#')
		{
			start = i + 1;
			continue;
		}
		else if ((channel[i] == ',' || i == channel.size() - 1) && channel[start] == '#')
		{
			std::string channelName = channel.substr(start + 1, i - start - (channel[i] == ','));
			std::map<std::string, Channel>::iterator iter = _channelList.find(channelName);
			start = i + 1;

			if (iter == _channelList.end()) continue;
			else
			{
				_fdTo.insert(_fdFrom);
				FileDescriptor& tmpfd = _fdList.find(_fdFrom)->second;
				_sendMsg = ":" + tmpfd.getNick() + "!" + tmpfd.getUser() + "@" + tmpfd.getHostname() + " " + _parse.begin()->second + " #" + channelName + "\r\n";
				sendMessage(_sendMsg);
				_sendMsg = RPL_NAMREPLY + tmpfd.getNick() + " = #" + channelName;

				std::vector<std::string> tmp = _channelList.find(channelName)->second.getNick();
				int operFd = _channelList.find(channelName)->second.getOperator();
				std::string nick;

				if (operFd != -1)
				{
					nick = _fdList.find(operFd)->second.getNick();
					_sendMsg.append(" :@");
					_sendMsg.append(nick);
				}
				else
					_sendMsg.append(" :");
				_sendMsg.append(" ");

				for (size_t i = 0; i < tmp.size(); i++)
				{
					if (operFd != -1 && tmp[i] == nick) continue;

					_sendMsg.append(tmp[i]);
					_sendMsg.append(" ");
					std::cout << tmp[i] << " ";
				}
				std::cout << std::endl;
				_sendMsg.append("\r\n");
				sendMessage(_sendMsg);
				_sendMsg = RPL_ENDOFNAMES + tmpfd.getNick() + " #" + channelName + " :End of NAMES list\r\n";
				sendMessage(_sendMsg);
			}
		}
	}
	return;
}

void EventHandler::cmdPrivmsg(void)
{
	if (!_fdList.find(_fdFrom)->second.getWelcome()) return;
	int	i = 0;

	std::string target, msg;
	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end() && it->first != CRLF)
	{
		if (it->first == MIDDLE)
		{
			if (target.empty()) target = it->second;
			else msg = it->second;
			i++;

			if (i == 2) break;
		}
		else if (it->first == TRAILING && i > 0)
		{
			msg += it->second;
			i++;
		}
		it++;
	}

	if (it == _parse.end() && i < 2)
	{
		_fdTo.insert(_fdFrom);
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return ;
	}

	FileDescriptor &from = _fdList.find(_fdFrom)->second;

	if (target[0] == '#')
	{
		std::string channelName = target.substr(1);
		std::map<std::string, Channel>::iterator iter = _channelList.find(channelName);

		if (iter == _channelList.end())
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_NOSUCHCHANNEL + channelName + " :No such channel\r\n";
			sendMessage(_sendMsg);
			return ;
		}
		else if (!iter->second.isInChannel(_fdFrom))
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_CANNOTSENDTOCHAN + channelName + " :Cannot send to channel\r\n";
			sendMessage(_sendMsg);
			return ;
		}

		pushChannel(channelName);
		_fdTo.erase(_fdFrom);
 		_sendMsg = ":" + from.getNick() + "!" + from.getUser() + "@" + from.getHostname() + " PRIVMSG " + target + " :" + msg + "\r\n";
 		sendMessage(_sendMsg);

		if (msg[0] == '@')
		{
			_fdTo.insert(_fdFrom);
			Bot bot(msg, _port);
			std::vector<std::string> botMessage = bot.process();
			for (size_t i = 0; i < botMessage.size(); i++)
			{
				_sendMsg = ":BOT!BOT@BOT PRIVMSG " + target + " :" + botMessage[i] + "\r\n";
				sendMessage(_sendMsg);
			}
		}
	}
	else
	{
		if (getFd(target) == -1)
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_NOSUCHNICK + target + " :No such nick\r\n";
			sendMessage(_sendMsg);
		}
		else
		{
			_fdTo.insert(getFd(target));
			_sendMsg = ":" + from.getNick() + "!" + from.getUser() + "@" + from.getHostname() + " PRIVMSG " + target + " :" + msg + "\r\n";
			sendMessage(_sendMsg);
		}
	}
}

void	EventHandler::cmdKick(void)
{
	if (!_fdList.find(_fdFrom)->second.getWelcome()) return;

	std::string channel, target;
	int i = 0;
	std::vector<std::pair<int, std::string> >::iterator it = _parse.begin();

	while (it != _parse.end() && i < 2)
	{
		if (it->first == MIDDLE)
		{
			if (channel == "") channel = it->second;
			else target = it->second;
			i++;
		}
		it++;
	}

	if (it == _parse.end() || i < 2)
	{
		_sendMsg = ERR_NEEDMOREPARAMS + _parse.begin()->second + " :Not enough parameters\r\n";
		sendMessage(_sendMsg);
		return ;
	}

	std::string nick = _fdList.find(_fdFrom)->second.getNick();

	if (channel[0] == '#')
	{
		std::string channelName = channel.substr(1);
		std::map<std::string, Channel>::iterator iter = _channelList.find(channelName);

		if (iter == _channelList.end())
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_NOSUCHCHANNEL + channelName + " :No such channel\r\n";
			sendMessage(_sendMsg);
			return;
		}

		std::string operNick = _fdList.find(_channelList.find(channelName)->second.getOperator())->second.getNick();

		if (operNick != nick)
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_CHANOPRIVSNEEDED + channelName + " :You're not channel operator\r\n";
			sendMessage(_sendMsg);
			return;
		}

		int fd = getFd(target);

		if (!iter->second.isInChannel(fd))
		{
			_fdTo.insert(_fdFrom);
			_sendMsg = ERR_NOTONCHANNEL + channelName + " :Cannot send to channel\r\n";
			sendMessage(_sendMsg);
			return;
		}

		pushChannel(channelName);
		iter->second.leave(fd);
		_fdList.find(fd)->second.partChannel(channelName);
		_sendMsg = ":" + nick + " " + _parse.begin()->second + " #" + channelName + " " + target + "\r\n";
		sendMessage(_sendMsg);
	}
}

void	EventHandler::cmdHandler(void)
{
	switch (_parse.begin()->first)
	{
	case PASS_:
		cmdPass();
		break;
	case NICK_:
		cmdNick();
		break;
	case USER_:
		cmdUser();
		break;
	case QUIT_:
		cmdQuit();
		break;
	case JOIN_:
		cmdJoin();
		break;
	case KICK_:
		cmdKick();
		break;
	case PART_:
		cmdPart();
		break;
	case NAMES_:
		cmdNames();
		break;
	case PRIVMSG_:
		cmdPrivmsg();
		break;
	};
	_fdTo.erase(_fdTo.begin(), _fdTo.end());
}

std::set<int> EventHandler::joinChannel(std::string channelName, int fd)
{
	std::map<std::string, Channel>::iterator it;
	std::map<int, FileDescriptor>::iterator iter = _fdList.find(fd);
	it = _channelList.find(channelName);

	if (it == _channelList.end())
	{
		_channelList.insert(std::pair<std::string, Channel>(channelName, Channel(channelName, _fdList)));
		it = _channelList.find(channelName);
		it->second.setOperator(_fdFrom);
	}
	iter->second.joinChannel(it->second);
	it->second.join(fd);

	std::vector<int> fds = it->second.getList();
	std::set<int> ret;
	for(std::vector<int>::iterator fdit = fds.begin(); fdit != fds.end(); fdit++) {
		ret.insert(*fdit);
	}
	return ret;
}
