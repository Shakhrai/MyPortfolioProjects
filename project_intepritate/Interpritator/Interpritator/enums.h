#pragma once
#include <string>
using namespace std;

enum class eTokenType
{
	COMMAND,
	POSSITION
};

std::string ToString(eTokenType type);

enum class eCommands
{
	MOVE,
	KILL
};

std::string ToString(eCommands type);

eCommands FromString(const std::string& command);




enum class eColor
{
	WHITE,
	BLACK
};
std::string ToString(eColor color);

eColor FromString(const std::string& color);


enum class eFieldType
{
	EMPTY_BLACK,
	EMPTY_WHITE,
	KING, //korol
	HORSE, //kon
	PAWN, //peshka
	QUEEN,//koroleva
	BISHOP,//slon
	ROCK //ladia

};
std::string ToString(eFieldType f_type);



enum class  eType_Figure
{
	KING, //korol
	HORSE, //kon
	PAWN, //peshka
	QUEEN,//koroleva
	BISHOP,//slon
	ROCK //ladia
};
std::string ToString(eType_Figure figure_type);
