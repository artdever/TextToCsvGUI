#pragma once
#include <vector>
#include <string>
#include "Warning.h"

class IRow
{
public:
	virtual const std::vector<std::string>& getRowValues() const = 0;
	virtual const std::vector<Warning>& getWarnings() const = 0;
};
