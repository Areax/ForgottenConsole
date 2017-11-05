// ForgottenConsole.cpp : Defines the entry point for the console application.
//
#include "RoomsStateMachine.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include <iostream>



using namespace Forgotten;
using namespace std;



int main()
{
	RoomsStateMachine rooms = RoomsStateMachine();
	rooms.Initialize();

	string command;
	NarrationAction begin = NarrationAction("beginning");

	begin();

	while (command != "exit")
	{
		cout << ">";
		getline(cin, command);
		Blackboard::SetCommand(command);

		rooms.Update();
	}

    return 0;
}

