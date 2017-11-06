#pragma once
#include "Blackboard.h"


namespace Forgotten
{
	string Blackboard::currentCommand = "";
	Blackboard::Turn Blackboard::currentTurn = Blackboard::Player;
	shared_ptr<PlayerWords> Blackboard::player = make_shared<PlayerWords>();

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

	shared_ptr<PlayerWords> Blackboard::GetPlayer()
	{
		return player;
	}

	Blackboard::Turn Blackboard::GetTurn()
	{
		return currentTurn;
	}
}