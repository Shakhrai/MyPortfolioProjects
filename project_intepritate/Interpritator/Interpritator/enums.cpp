#include "enums.h"

//-------------------------------------------------------------------------
std::string ToString(eTokenType type)
{
	switch (type)
	{
	case eTokenType::POSSITION: return "POSSITION";
	case eTokenType::COMMAND: return "COMMAND";
	}
	return "ERROR";
}
//-------------------------------------------------------------------------
std::string ToString(eCommands type)
{
	switch (type)
	{
	case eCommands::MOVE: return "!move";
	case eCommands::KILL: return "!kill";
	}
	return "Go wrong";
}

eCommands FromString(const std::string& command)
{
	if (command == "!move")
	{
		return eCommands::MOVE;
	}
	if (command == "!kill")
	{
		return eCommands::KILL;
	}
}
//-------------------------------------------------------------------------
std::string ToString(eColor color)
{
	switch (color)
	{
	case eColor::BLACK: return "black";
	case eColor::WHITE: return "white";
	}
	return "INVALID";
}
eColor FromString(const std::string& _color)
{
	if (_color == "black")
	{
		return eColor::BLACK;
	}
	if (_color == "white")
	{
		return eColor::WHITE;
	}
}
std::string ToString(eFieldType f_type)
{
	switch (f_type)
	{
	case eFieldType::EMPTY_BLACK: return "black";
	case eFieldType::EMPTY_WHITE: return "white";
	case eFieldType::KING: return "white";
	case eFieldType::HORSE: return "white";
	case eFieldType::PAWN: return "white";
	case eFieldType::QUEEN: return "white";
	case eFieldType::BISHOP: return "white";
	case eFieldType::ROCK: return "white";
	}
	return "INVALID";
}
std::string ToString(eType_Figure figure_type)
{
	switch (figure_type)
	{
	case eType_Figure::KING: return "white";
	case eType_Figure::HORSE: return "white";
	case eType_Figure::PAWN: return "white";
	case eType_Figure::QUEEN: return "white";
	case eType_Figure::BISHOP: return "white";
	case eType_Figure::ROCK: return "white";
	}
	return "INVALID";
}