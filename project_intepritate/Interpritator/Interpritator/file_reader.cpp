#include "file_reader.h"
#include <fstream>
//!hey
using namespace std;


void eFileReader::ReadFile()
{
	ifstream is;
	is.open(fileName);
	if (is.is_open())
	{
		string s;
		s.reserve(1000);
		while (!is.eof())
		{
			is.getline((char*)s.c_str(), 1000);
			text.push_back(s.c_str());
		}
	}
	is.close();
}

string eFileReader::GetLine(size_t line)
{
	return text[line];
}

string eFileReader::GetTextFull()
{
	string store;
	for (size_t i = 0; i < text.size(); i++)
	{
		store += text[i];
	}
	return store;
}