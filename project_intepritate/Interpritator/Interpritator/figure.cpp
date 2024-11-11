#pragma once
#include <sstream>
#include "figure.h"

eFigure::eFigure(//const GameBoard& _desk, fRobotSpeach _f)
//	: desk(_desk)
	//, fRobotSays(_f)
	{}

	void Switch_Color_figure()
	{
		switch (color)
		{
		case eColor::WHITE:	White();			break;//$todo:
		case eColor::BLACK:	Black();			break;//$todo:
		}
	}
	void eType_figure_own()
	{
		switch (figure_type)
		{
		case eType_Figure::KING:	King();			break;//$todo:
		case eType_Figure::HORSE:	Horse();			break;//$todo:
		case eType_Figure::PAWN:	Pawn();			break;//$todo:
		case eType_Figure::QUEEN:	Queen();			break;//$todo:
		case eType_Figure::BISHOP:	Bishop();			break;//$todo:
		case eType_Figure::ROCK:	Rock();			break;//$todo:
		}
	}
	void eFigure::Do_Command(eCommands command)
	{
		int newX = x;
		int newY = y;
		switch (command)
		{
		case eCommands::MOVE:	Move();			break;//$todo:
		case eCommands::KILL:	Kill();			break;//$todo:
		}
		if (Your_Side(newX, newY) && Figure_Move())
		{
			x = newX;
			y = newY;
		}
		else
		{
			std::stringstream ss;
			ss << "Cannot move to coord" << std::endl;
			throw std::logic_error(ss.str());
		}
	}
	void Figure_Move(eType_Figure& figure_type)
	{
		if (figure_type = eType_Figure::KING)
		{

		}
		if (figure_type = eType_Figure::QUEEN)
		{

		}
		if (figure_type = eType_Figure::PAWN)
		{

		}
		if (figure_type = eType_Figure::ROCK)
		{

		}
		if (figure_type = eType_Figure::HORSE)
		{

		}
		if (figure_type = eType_Figure::BISHOP)
		{

		}
		
	}
	void PawnMove()
	{

	}
	bool Your_Side()
	{

	}
	
