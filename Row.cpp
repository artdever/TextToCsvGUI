#include "Row.h"

const std::vector<std::string>& Row::getRowValues() const
{
	return values;
}

const std::vector<Warning>& Row::getWarnings() const
{
	return warnings;
}

void Row::addRowValue(std::string s)
{
	values.push_back(s);
}

void Row::addWarning(Warning w)
{
	warnings.push_back(w);
}