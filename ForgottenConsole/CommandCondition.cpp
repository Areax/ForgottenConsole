#pragma once
#include <string>
#include "CommandCondition.h"
#include "Blackboard.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	CommandCondition::CommandCondition(string command)
	{
		mCommand = command;
	}
		
	bool CommandCondition::operator()()
	{
		return mCommand == Blackboard::GetCommand();
	};
}