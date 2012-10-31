#include "exceptions.h"

error::error(const std::string& m)
	: message(m)
{
}

const std::string& error::getMessage() const
{
	return message;
}