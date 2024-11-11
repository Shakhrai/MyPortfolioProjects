#include "robot.h"
#include <sstream>


eRobot::eRobot(const GameBoard& _desk, fRobotSpeach _f)
: desk(_desk)
, fRobotSays(_f)
{}
//-------------------------------------------------------------------------
bool eRobot::Init(eAngle _angle)
{
	angle = _angle;
	for (int i = 0; i < desk.size(); i++)
	{
		for (int j = 0; j < desk[i].size(); j++)
		{
			if (eCellType::START == desk[i][j])
			{
				x = j;
				y = i;
				return true;
			}
		}
	}
	return false;
}
//-------------------------------------------------------------------------
void eRobot::Do(const eToken& token)
{
	if (repeatCounter <= 0)
		repeatCounter = 1;
	while (repeatCounter != 0)
	{
		if (token.type == eTokenType::COMMAND)
		{
			DoCommand(FromString(token.value));
		}
		if (token.type == eTokenType::NUMBER) //not sence use loop
		{
			repeatCounter = stoi(token.value);
			if (repeatCounter <= 0)
				repeatCounter = 1;
			break;
		}
		if (token.type == eTokenType::STRING && fRobotSays)
		{
			fRobotSays("[Robot Says] : " + token.value);
		}
		repeatCounter--;
	}
}
//-------------------------------------------------------------------------
void eRobot::Move()
{
	int newX = x;
	int newY = y;
	switch (angle)
	{
	case eAngle::BOTTOM:	++newY;	break;
	case eAngle::LEFT:		--newX;	break;
	case eAngle::TOP:		--newY;	break;
	case eAngle::RIGHT:		++newX;	break;
	}
	if(CanMove(newX, newY))
	{
		x = newX;
		y = newY;
	}
	else
	{
		std::stringstream ss;
		ss << "Cannot move to coord [" << newX << ";" << newY << "]" << endl;
		throw std::logic_error(ss.str());
	}
}
//-------------------------------------------------------------------------
void eRobot::RotateRight()
{
	switch (angle)
	{
	case eAngle::BOTTOM:	angle = eAngle::LEFT;	break;
	case eAngle::LEFT:		angle = eAngle::TOP;	break;
	case eAngle::TOP:		angle = eAngle::RIGHT;	break;
	case eAngle::RIGHT:		angle = eAngle::BOTTOM;	break;
	}
}
//-------------------------------------------------------------------------
void eRobot::RotateLeft()
{
	switch (angle)
	{
	case eAngle::BOTTOM:	angle = eAngle::RIGHT;	break;
	case eAngle::LEFT:		angle = eAngle::BOTTOM;	break;
	case eAngle::TOP:		angle = eAngle::LEFT;	break;
	case eAngle::RIGHT:		angle = eAngle::TOP;	break;
	}
}
bool eRobot::CanMove(int _newX, int _newY) const
{
	if (_newX < 0
		|| _newY < 0
		|| _newX > desk[0].size()
		|| _newY > desk.size()
		|| desk[_newY][_newX] == eCellType::WALL)
	{
		return false;
	}
	return true;
}
//-------------------------------------------------------------------------
string eRobot::Dump() const
{
	std::stringstream ss;
	ss << "angle = " << (int)angle << " x = " << x << " y = " << y << std::endl;
	return ss.str();
}
//-------------------------------------------------------------------------
void eRobot::DoCommand(eCommands command)
{
	switch (command)
	{
	case eCommands::MOVE:	Move();			break;//$todo:
	case eCommands::RIGHT:	RotateRight();	break;//$todo:
	case eCommands::LEFT:	RotateLeft(); 	break;//$todo:
	}
}