#pragma once
#include <string>
#include "MonsterCondition.h"
#include "Blackboard.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	MonsterCondition::MonsterCondition(string command, string input)
	{
		mCommand = command;
		mInput = input;
	}

	bool MonsterCondition::operator()()
	{
		return mCommand == mInput;
	};
}