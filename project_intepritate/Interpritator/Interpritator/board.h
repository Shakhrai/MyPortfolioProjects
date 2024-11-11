#pragma once

#include "robot.h"
#include "enums.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>


class MyBoard //problem with isstartpassed and x y redifininning massive
{
public:
	MyBoard(int cols, int rows, eRobot::fRobotSpeach _f = nullptr);
	
	void	Do(const eToken& token);
	bool	IsRobotFinish() const;

	string	Dump() const;
protected:
	void Generate();
	void Generate_mass();
	void Generate_start_poss();
	void Generate_finish_poss();
	void Generate_barriers();

private:
	GameBoard				gameBoard;
	std::unique_ptr<eRobot>	robot;
	int						cols = 0;
	int						rows = 0;
};
