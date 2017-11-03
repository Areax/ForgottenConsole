// ForgottenConsole.cpp : Defines the entry point for the console application.
//
#include "RoomsStateMachine.h"
#include <iostream>
#include <fstream>


using namespace Forgotten;
using namespace std;

int main()
{
	RoomsStateMachine rooms = RoomsStateMachine();
	rooms.Initialize();
	string command;

	string filename = "Content//beginning.txt";
	ifstream f(filename);

	if (f.is_open())
		std::cout << f.rdbuf();

	while (command != "exit")
	{

		cout << ">";
		cin >> command;
		rooms.Update();
	}

    return 0;
}

