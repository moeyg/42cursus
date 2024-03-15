#ifndef __MULTIPLEX_HPP__
#define __MULTIPLEX_HPP__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/event.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <map>
#include <vector>

#include "StringHandle.hpp"
#include "recvData.hpp"
#include "FileDescriptor.hpp"

class Multiplex
{
public:
	Multiplex(std::map<int, FileDescriptor>& fdList);
	~Multiplex(void);

	std::string init(int ac, char** av);
	recvData sequence(void);

private:
	void initServerSocket(int port);
	std::string setPortPass(int ac, char *av[]);

	void eventSet(uintptr_t ident, int16_t filter,
					uint16_t flags, uint32_t fflags,
					intptr_t data, void *udata);
	void addReadEvent(int fd);
	void delReadEvent(int fd);
	void addWriteEvent(int fd);
	void delWriteEvent(int fd);

	recvData eventHandling(struct kevent* cur);
	recvData acceptClient();
	recvData readFromClient(int fd);
	recvData writeToClient(int fd);

	int _port;
	int _serverSocket;
	int _kq;

	std::vector<struct kevent> _events;
	std::map<int, FileDescriptor>& _fdList;
};

#endif
