#pragma once

#include "enums.h"

struct eToken
{
	eToken() = default;
	eToken(eTokenType		_type,
		   std::string		_value)
		: type(_type)
		, value(_value)
	{}

	eTokenType	type	= eTokenType::UNKNOWN;
	std::string	value	= "";
};