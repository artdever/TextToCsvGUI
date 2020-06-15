#pragma once
#include <string>

struct Warning
{
	Warning(std::string s) 
		: warning(s) {};
	std::string warning;
};