#pragma once

#include "token.h"
#include "enums.h"
#include <vector>
#include <functional>

using GameBoard = std::vector<std::vector<eCellType>>;

class eRobot
{
public:
	enum class eAngle
	{
		RIGHT = 0,
		TOP = 1,
		LEFT = 2,
		BOTTOM = 3,
	};

	using fRobotSpeach = std::function<void(const std::string&)>;
public:
	eRobot(const GameBoard&, fRobotSpeach _f = nullptr);

	bool Init(eAngle = eAngle::RIGHT);

	void Do(const eToken& token);
	string Dump () const;

	int X() const { return x; }
	int Y() const { return y; }

protected:
	void DoCommand(eCommands command);
	void Move();
	void RotateRight();
	void RotateLeft();
	bool CanMove(int newX, int newY)	const;

	int					repeatCounter			= 0;
	eAngle				angle					= eAngle::RIGHT;
	int					x						= 0;
	int					y						= 0;
	fRobotSpeach		fRobotSays				= nullptr;
	const GameBoard&	desk;
};
