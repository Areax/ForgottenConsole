#pragma once
#include "Blackboard.h"


namespace Forgotten
{
	string Blackboard::currentCommand = "";
	Blackboard::Turn Blackboard::currentTurn = Blackboard::Player;

	Blackboard::Blackboard()
	{
	}
	
	void Blackboard::SetCommand(string command)
	{
		currentCommand = command;
	}

	string Blackboard::GetCommand()
	{
		return currentCommand;
	}

	void Blackboard::SetTurn(Turn turn)
	{
		currentTurn = turn;
	}

	Blackboard::Turn Blackboard::GetTurn()
	{
		return currentTurn;
	}
}