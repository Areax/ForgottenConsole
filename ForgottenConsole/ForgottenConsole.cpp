// ForgottenConsole.cpp : Defines the entry point for the console application.
//
//#include "RoomsStateMachine.h"
#include "PlayingSM.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include <iostream>



using namespace Forgotten;
using namespace std;



int main()
{
	//RoomsStateMachine rooms = RoomsStateMachine();
	PlayingSM play = PlayingSM();
	//rooms.Initialize();
	play.Initialize();

	string command;
	// use output if you wanted the player to actually quit the game.
	// string output;
	NarrationAction begin = NarrationAction("beginning");

	begin();

	while (command != "exit")
	{
		cout << ">";
		getline(cin, command);

		// "reparse" string
		command = Blackboard::GetPlayer()->ModifyString(command);
		cout << "Command: " << command << endl;
		Blackboard::SetCommand(command);

		play.Update();
		//rooms.Update();
	}

    return 0;
}

