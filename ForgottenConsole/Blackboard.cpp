#pragma once
#include "Blackboard.h"


namespace Forgotten
{
	string Blackboard::currentCommand = "";

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
}