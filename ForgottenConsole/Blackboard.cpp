#pragma once
#include "Blackboard.h"


namespace Forgotten
{
	string Blackboard::currentCommand = "";
	shared_ptr<PlayerWords> Blackboard::player = make_shared<PlayerWords>();
	shared_ptr<State> Blackboard::monsterState = NULL;
	shared_ptr<State> Blackboard::playerState = NULL;

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

	shared_ptr<PlayerWords> Blackboard::GetPlayer()
	{
		return player;
	}

	void Blackboard::SetPlayerState(shared_ptr<State> state)
	{
		playerState = state;
	}

	shared_ptr<State> Blackboard::GetPlayerState()
	{
		return playerState;
	}

	void Blackboard::SetMonsterState(shared_ptr<State> state)
	{
		monsterState = state;
	}

	shared_ptr<State> Blackboard::GetMonsterState()
	{
		return monsterState;
	}
}