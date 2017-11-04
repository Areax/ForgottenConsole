// ForgottenConsole.cpp : Defines the entry point for the console application.
//
#include "RoomsStateMachine.h"
#include "MonsterStateMachine.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include <iostream>



using namespace Forgotten;
using namespace std;



int main()
{
	RoomsStateMachine rooms = RoomsStateMachine();
	MonsterStateMachine monster = MonsterStateMachine();
	rooms.Initialize();
	monster.Initialize();

	string command;
	NarrationAction begin = NarrationAction("beginning");

	begin();

	while (command != "exit")
	{
		cout << ">";
		getline(cin, command);
		Blackboard::SetCommand(command);

		rooms.Update();
		monster.Update();
	}

    return 0;
}

