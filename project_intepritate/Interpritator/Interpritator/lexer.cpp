#include "lexer.h"
#include <sstream>

void eLexer::FindAllLexems(const string& text)
{
	size_t i = 0; 
	while(i < text.length())
	{
		if(text[i] == ' ' 
		   || text[i] == '\t' 
		   || text[i] == '\n'
		   || text[i] == '\0'
		)
		{
			i++;
			continue;
		}
		if (FindCommandLex(text, i))
		{
			i++;
			continue;
		}
		if (FindStringLex(text, i))
		{
			i++;
			continue;
		}
		if (FindDigitLex(text, i))
		{
			i++;
			continue;
		}
	}

}

eToken eLexer::Next()
{
	if(!IsEnd())
	{
		return tokens[tokenId++];
	}
	return eToken(eTokenType::UNKNOWN,"");
}
	
string eLexer::Dump() const
{
	stringstream ss;
	for(const eToken& token: tokens)
	{
		ss<<ToString(token.type)<<"\t"<<token.value<<endl;
	}
	return ss.str();
}

bool eLexer::FindStringLex(const string& text, size_t& index)
{
	if(text[index] == '\'')
	{
		index++;
			//"Oh nO hElp mE"
		eToken token;
		token.type = eTokenType::STRING;
		token.value = text[index];
		while(index < text.length())
		{
			index++;
			if(text[index] != '\'')
			{
				token.value += text[index];
			}
			else
			{
				tokens.push_back(token);
				return true;
			}
		}
		throw "not closed \"";
	}
	//index++;
	return false;
}

bool eLexer::FindDigitLex(const string& text, size_t& index)
{
	if (text[index] >= '0' && text[index] <= '9')
	{
		//"123.456,23"
		eToken token;
		token.type = eTokenType::NUMBER;
		bool hasDot = false;
		token.value = text[index];
		while (index < text.length())
		{
			index++;
			if (text[index] >= '0' && text[index] <= '9')
			{
				token.value += text[index];
			}
			else if (text[index] == '.' || text[index] == ',')
			{
				if (hasDot)
				{
					throw "BigAss Have more one dot";
				}
				token.value += '.';
				hasDot = true;
			}
			else
			{
				tokens.push_back(token);
				return true;
			}
		}
		tokens.push_back(token);
		return true;
	}
	//index++;
	return false;
}

bool eLexer::FindCommandLex(const string& text, size_t& index)
{
	if (text[index] == '!')
	{
		//"!help !wow"
		eToken token;
		token.type = eTokenType::COMMAND;
		token.value = text[index];
		while (index < text.length())
		{
			index++;
			if ((text[index] >= 'a' && text[index] <= 'z') || text[index] == '_')
			{
				token.value += text[index];
			}
			else
			{
				tokens.push_back(token);
				return true;
			}
		}
		tokens.push_back(token);
		return true;
	}
	//index++;
	return false;
}