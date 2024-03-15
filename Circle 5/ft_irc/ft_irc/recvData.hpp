#ifndef __RECVDATA_HPP__
#define __RECVDATA_HPP__

#include <string>

typedef struct recvData
{
	std::string msg;
	int fdFrom;
} recvData;

#endif
