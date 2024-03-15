#include "Bot.hpp"

Bot::Bot(std::string msg, std::string& port) : _msg(msg), _port(port) { }

Bot::~Bot(void) { }

std::vector<std::string> Bot::process(void)
{
	int	command = checkCommand();

	switch (command)
	{
	case HELP:
		return help();
		break;
	case INFO:
		return info();
		break;
	default:
		return std::vector<std::string>();
		break;
	}
}

int Bot::checkCommand(void) 
{
	if (_msg.empty()) return NOT_COMMAND;
	else if (_msg[0] != '@') return NOT_COMMAND;

	std::size_t pos = _msg.find(' ');
	_command = _msg.substr(1, pos);
	_msg.erase(_msg.begin(), _msg.begin() + pos);

	while (_msg[0] == ' ')
		_msg.erase(_msg.begin(), _msg.begin() + 1);

	pos = _msg.find(' ');
	_argument = _msg.substr(0, pos);

	if (_command == "help") return HELP;
	else if (_command == "info") return INFO;

	return NOT_COMMAND;
}

std::vector<std::string> Bot::help(void)
{
	std::vector<std::string>	response;

	response.push_back("help: Show a list of command.");
	response.push_back("info: Show server IP addr and port number.");

	return response;
}

std::vector<std::string> Bot::info(void)
{
	int							hostname;
	char						host[256];
	struct hostent				*hostEntry;
	std::string					IP;
	std::vector<std::string>	response;

	hostname = gethostname(host, sizeof(host));
	if (hostname == -1)
	{
		response.push_back("Error: hostname");
		return response;
	}

	hostEntry = gethostbyname(host);
	if (!hostEntry)
	{
		response.push_back("Error: HostIp");
		return response;
	}

	IP = inet_ntoa(*((struct in_addr*) hostEntry->h_addr_list[0]));
	response.push_back(host);
	response.push_back("InternetRelayChat.net");
	response.push_back(IP);
	response.push_back(_port);

	return response;
}