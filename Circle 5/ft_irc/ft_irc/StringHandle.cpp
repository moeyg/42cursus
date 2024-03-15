#include "StringHandle.hpp"

bool isAllDigit(std::string str)
{
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}