// Interpritator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "board.h"
#include "lexer.h"

using namespace std;

int main()
{
	MyBoard board(10, 10, [](const string& _text)
	{
		cout << _text << endl;
	});
	cout << board.Dump() << endl;
	cout << "*******************************************\n";

	while (true)
	{
		cout << "Enter Command|commands:" << endl;
		string text;
		getline(cin, text);
		if (text == "end")
		{
			return 0;
		}
		eLexer lexer;
		lexer.FindAllLexems(text);
		while (!lexer.IsEnd())
		{
			try
			{
				board.Do(lexer.Next());
				cout << board.Dump() << endl;
				cout << "==========================================\n";
			}
			catch (const std::logic_error& _error)
			{
				cerr << "[Error]:" << _error.what() << endl;
			}
		}
	}
	/*eRobot test(0, 0);
	Desk tert;
	tert.Generate();
	tert.Print();
	cout <<endl<< "Comands are: move, left, right, numbers and stop"<<endl;
	while (true)
	{
		if (tert.b=="a3")
		{
			break;
		}
		cin >> a;
		if (a == "move")
		{
			tert.Move();
		}
		else if (a == "left")
		{
			tert.Left();
		}
		else if (a == "right")
		{
			tert.Right();
		}
		else if (a == "stop")
		{
			break;
		}
		else if (a >= "0" && a <= "9")
		{
			int z = stoi(a);
			tert.repeatCounter = z;
		}
		else
		{
			cout << "Robot says: " << a << endl;
		}
		tert.Print();
	}*/
	system("pause");
	return 0;

}


//eFileReader o("1.txt");
	//o.ReadFile();
