#include "Server.hpp"

Server::Server(int ac, char *av[]) :_multiplex(_fdList)
{
	_pass = _multiplex.init(ac, av);
	_port = av[1];
}

Server::~Server(void)
{
	for (std::map<int, FileDescriptor>::iterator it = _fdList.begin();
		it != _fdList.end(); it++)
		close(it->first);
}

void Server::start(void)
{
	while (1)
	{
		recvData res = _multiplex.sequence();

		if (res.fdFrom == -1 && res.msg == "") continue;
		else if (res.msg == "\3")
		{
			closeClient(res.fdFrom);
			deleteBuffer();
			continue;
		}
		else if (res.msg == "") continue;

		std::vector<recvData>::iterator it;

		for (it = _recvBuffer.begin(); it != _recvBuffer.end(); it++)
		{
			if (it->fdFrom == res.fdFrom)
			{
				it->msg.append(res.msg);
				break;
			}
		}

		if (it == _recvBuffer.end())
		{
			_recvBuffer.push_back(res);
			it = _recvBuffer.begin();
			it += _recvBuffer.size() - 1;
		}

		if (it->msg[it->msg.size() - 1] == '\n')
		{
			EventHandler ev(*it, _fdList, _channelList, _pass, _port);
			_recvBuffer.erase(it);
		}

		deleteBuffer();
	}
}

void Server::closeClient(int fd)
{
	std::map<int, FileDescriptor>::iterator it = _fdList.find(fd);

	if (it == _fdList.end()) return ;

	std::map<std::string, Channel>::iterator channelIter = _channelList.begin();

	while (channelIter != _channelList.end())
	{
		std::vector<int>channelFd = channelIter->second.getList();
		if (std::count(channelFd.begin(), channelFd.end(), fd))
		{
			std::map<std::string, Channel>::iterator tmpIter = channelIter;
			channelIter->second.leave(fd);
			channelIter++;

			if (tmpIter->second.getList().size() == 0) _channelList.erase(tmpIter);
		}
		else
			channelIter++;
	}
	_fdList.erase(it);
	close(fd);
}

void Server::deleteBuffer(void)
{
	for (std::vector<recvData>::iterator it = _recvBuffer.begin();
			it != _recvBuffer.end(); it++)
	{
		if (_fdList.find(it->fdFrom) == _fdList.end())
		{
			_recvBuffer.erase(it);
			return;
		}
	}
}
