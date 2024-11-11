#pragma once

#include <vector>
#include "token.h"

using namespace std;

class eLexer
{
public:
	eLexer() = default;

	void FindAllLexems(const string& text);

	eToken Next();

	bool IsEnd() const	 { return tokenId >= tokens.size(); }

	bool IsValid() const { return false; }

	string Dump() const;
protected:
	bool FindStringLex(const string& text, size_t& index);

	bool FindDigitLex(const string& text, size_t& index);

	bool FindCommandLex(const string& text, size_t& index);

	size_t			tokenId = 0;
	vector<eToken>	tokens;
};