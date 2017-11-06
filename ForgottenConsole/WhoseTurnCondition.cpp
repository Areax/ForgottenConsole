#pragma once
#include <string>
#include "WhoseTurnCondition.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	WhoseTurnCondition::WhoseTurnCondition(Blackboard::Turn turn)
	{
		mTurn = turn;
	}

	bool WhoseTurnCondition::operator()()
	{
		return mTurn == Blackboard::GetTurn();
	};
}