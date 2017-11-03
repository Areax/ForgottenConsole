// ForgottenConsole.cpp : Defines the entry point for the console application.
//
#include "RoomsStateMachine.h"
#include "iostream"

using namespace Forgotten;
using namespace std;

int main()
{
	RoomsStateMachine rooms = RoomsStateMachine();
	rooms.Initialize();
	string command;

	while (command != "exit")
	{
		cout << ">";
		cin >> command;
		rooms.Update();
	}

    return 0;
}

