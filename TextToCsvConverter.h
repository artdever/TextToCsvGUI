#pragma once
#include <fstream>
#include "IConverter.h"
#include "Tokenize.h"

class TextToCsvConverter : public IConverter
{
public:
	void convert(std::string input, bool printWarnings = false);
	void write(std::string output);
	void convertAndWrite(std::string input, std::string output, bool printWarnings = false);
	std::vector<Warning> getWarnings();
private:
	Tokenize tokenizer;
	
	void printWarnings();
};

