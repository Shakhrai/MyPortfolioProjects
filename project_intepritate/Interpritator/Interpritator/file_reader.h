#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class eFileReader
{
public:
	eFileReader(const std::string& fileNameFull)
	{
		fileName = fileNameFull;
	}
	void ReadFile();
	std::string GetLine(size_t line);
	std::string GetTextFull();
protected:
	std::string fileName;
	std::vector<std::string>text;
};