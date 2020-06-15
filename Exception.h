#pragma once
#include <exception>
#include <string>

class Exception
{
public:
	Exception(const std::string& what) : what_(what) {};
	const std::string what() const noexcept { return what_; }
protected:
	const std::string what_;
};


class FormatException : public Exception
{
public:
	FormatException() : Exception("Unknown format exception") {};
	FormatException(const std::string& what) : Exception(what_) {};
	const std::string what() const noexcept { return "Format exception: " + Exception::what(); }
};