#include "Multiplex.hpp"

Multiplex::Multiplex(std::map<int, FileDescriptor>& fdList) : _fdList(fdList) { }

Multiplex::~Multiplex(void)
{
	close(_serverSocket);
	close(_kq);
}

std::string Multiplex::init(int ac, char *av[])
{
	std::string pass = setPortPass(ac, av);
	initServerSocket(_port);
	_kq = kqueue();

	if (_kq == -1)
	{
		std::cout << "kqueue fail" << std::endl;
		exit(1);
	}

	addReadEvent(_serverSocket);
	std::cout << "Server Ready to Start" << std::endl;

	return pass;
}

recvData Multiplex::sequence(void)
{
	struct kevent newEvents;
	int cnt = 0;

	if (kevent(_kq, &_events[0], _events.size(), &newEvents, 1, NULL) == -1)
	{
		cnt++;
		std::cout << "kevent fail : " << cnt << std::endl;

		if (cnt == 5)
		{
			std::cout << "kevent fail : close server" << std::endl;
			exit(1);
		}
	}

	cnt = 0;
	if (!_events.empty()) _events.clear();

	return eventHandling(&newEvents);
}

void Multiplex::initServerSocket(int port)
{
	struct sockaddr_in server_addr;

	if ((_serverSocket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	{
		std::cout << "fail to get server socket" << std::endl;
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);

	if (bind(_serverSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		std::cout << "fail to bind server socket" << std::endl;
		exit(1);
	}

	if (listen(_serverSocket, 5) == -1)
	{
		std::cout << "fail to listen server socket" << std::endl;
		exit(1);
	}
	fcntl(_serverSocket, F_SETFL, O_NONBLOCK);
}

std::string Multiplex::setPortPass(int ac, char *av[])
{
	if (ac != 3)
	{
		std::cout << "Worng Argument" << std::endl;
		exit(1);
	}

	std::string port, pass;
	port = std::string(av[1]);
	pass = std::string(av[2]);

	if (!isAllDigit(port))
	{
		std::cout << "Worng port number" << std::endl;
		exit(1);
	}

	_port = std::atoi(port.c_str());

	return pass;
}

void Multiplex::eventSet(uintptr_t ident, int16_t filter,
						uint16_t flags, uint32_t fflags,
						intptr_t data, void *udata)
{
	struct kevent temp_event;

	EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
	_events.push_back(temp_event);
}

void Multiplex::addReadEvent(int fd)
{
	eventSet(fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
}

void Multiplex::delReadEvent(int fd)
{
	eventSet(fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
}

void Multiplex::addWriteEvent(int fd)
{
	eventSet(fd, EVFILT_WRITE, EV_ADD, 0, 0, NULL);
}

void Multiplex::delWriteEvent(int fd)
{
	eventSet(fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
}

recvData Multiplex::eventHandling(struct kevent* cur)
{
	if (cur->flags & EV_ERROR)
	{
		std::cerr << "error form client" << std::endl;
		recvData res;
		res.fdFrom = cur->ident;
		res.msg = "\3";
		return res;
	}
	else if (cur->filter == EVFILT_READ)
	{
		if (cur->ident == static_cast<uintptr_t>(_serverSocket))
			return acceptClient();
		else
			return readFromClient(cur->ident);
	}
	else if (cur->filter == EVFILT_WRITE)
	{
		return writeToClient(cur->ident);
	}
	return recvData();
}

recvData Multiplex::acceptClient(void)
{
	int clientSocket;

	if ((clientSocket = accept(_serverSocket, NULL, NULL)) == -1)
	{
		recvData res;
		res.fdFrom = -1;
		res.msg = "";
		return res;
	}

	std::cout << "accept new client: " << clientSocket << std::endl;
	fcntl(clientSocket, F_SETFL, O_NONBLOCK);

	addReadEvent(clientSocket);
	addWriteEvent(clientSocket);
	_fdList.insert(std::make_pair(clientSocket, FileDescriptor(clientSocket)));

	recvData res;
	res.fdFrom = clientSocket;
	res.msg = "";

	return res;
}

recvData Multiplex::readFromClient(int fd)
{
	char buf[1024];
	std::string str;
	recvData res;
	int n;

	n = recv(fd, buf, 1023, 0);
	if (n <= 0)
	{
		if (n < 0) std::cerr << "client read error!" << std::endl;
		res.fdFrom = fd;
		res.msg = "\3";

		return res;
	}

	while (n > 0)
	{
		buf[n] = '\0';
		res.msg.append(buf);
		n = recv(fd, buf, 1023, 0);
	}

	std::cout << "received data from " << fd << ": " << res.msg << std::endl;
	res.fdFrom = fd;

	return res;
}

recvData Multiplex::writeToClient(int fd)
{
	recvData res;
	res.fdFrom = fd;
	res.msg = "";

	std::map<int, FileDescriptor>::iterator it = _fdList.find(fd);
	if (it == _fdList.end())
	{
		recvData res;
		res.fdFrom = -1;
		res.msg = "";
		return res;
	}

	if (it->second.getSendMsg() == "") return res;

	if (send(fd, it->second.getSendMsg().c_str(),
		it->second.getSendMsg().size(), 0) < 0)
	{
		recvData res;
		res.fdFrom = -1;
		res.msg = "";
		return res;
	}
	std::cout << "\n===MESSAGE==========================================\nfd : " << it->first << "\n" << it->second.getSendMsg() << "====================================================\n\n" << std::endl;
	it->second.clearSendMsg();

	return res;
}
