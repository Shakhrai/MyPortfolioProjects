#include "board.h"
#include <sstream>

MyBoard::MyBoard(int _cols, int _rows, eRobot::fRobotSpeach _f)
: cols(_cols)
, rows(_rows)
{
	srand(time(0));
	robot = std::make_unique<eRobot>(gameBoard, _f);
	Generate();
}

string MyBoard::Dump() const
{
	std::stringstream ss;
	ss << robot->Dump() << endl;
	for (int i = 0; i < gameBoard.size(); i++)
	{
		for (int j = 0; j < gameBoard[i].size(); j++)
		{
			eCellType cell = gameBoard[i][j];
			if (robot->X() == j && robot->Y() == i)
			{
				cell = eCellType::ROBOT;
			}
			ss << ToString(cell) << "\t";
		}
		ss << endl;
	}
	return ss.str();
}

void MyBoard::Do(const eToken & token)
{
	robot->Do(token);
}

bool MyBoard::IsRobotFinish() const
{
	return gameBoard[robot->Y()][robot->X()] == eCellType::FINISH;
}

void MyBoard::Generate()
{
	Generate_mass();
	Generate_start_poss();
	Generate_finish_poss();
	Generate_barriers();
	robot->Init();
}

void MyBoard::Generate_mass()
{
	gameBoard.resize(cols);
	for (std::vector<eCellType>& row : gameBoard)
	{
		row.resize(rows, eCellType::NOTHING);
	}
}

void MyBoard::Generate_start_poss()
{
	gameBoard[0][rand() % rows] = eCellType::START;
}
void MyBoard::Generate_finish_poss()
{
	gameBoard[rand() % cols][0] = eCellType::FINISH;
}

void MyBoard::Generate_barriers()
{
	int count = 0;
	int free_cells = cols * rows - 2;
	int MaxBarriers = (int)(free_cells * 0.2);
	int RealBarriers = rand() % MaxBarriers;
	do
	{
		int i = rand() % cols;
		int j = rand() % rows;

		if (gameBoard[i][j] == eCellType::NOTHING)
		{
			count++;
			gameBoard[i][j] = eCellType::WALL;
		}
	}while (count < MaxBarriers);
}
