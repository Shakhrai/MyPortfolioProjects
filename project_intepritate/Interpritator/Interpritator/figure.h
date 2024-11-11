#pragma once
#include <string>
#include "enums.h"
class eFigure
{
public:
	eFigure(const/* GameBoard&, fRobotSpeach _f = nullptr)*/;
	void Do_Command();
	std::string Dump()const;
	int X() const { return x; }
	int Y() const { return y; }
	bool Your_Side();
protected:	
	void Switch_Color_Figure();
	void eType_figure_own();
	void Figure_Possition();
	
	
	
	int					x = 0;
	int					y = 0;
	//fRobotSpeach		fRobotSays = nullptr;
	//const GameBoard& desk;

};