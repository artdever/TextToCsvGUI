#pragma once
#include "IRow.h"

class Row : public IRow
{
public:
	const std::vector<std::string>& getRowValues() const;
	const std::vector<Warning>& getWarnings() const;
	void addRowValue(std::string);
	void addWarning(Warning);
private:
	std::vector<std::string> values;
	std::vector<Warning> warnings;
};

