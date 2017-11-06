#pragma once
#include <string>
#include "NearCondition.h"
#include "Blackboard.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	NearCondition::NearCondition(shared_ptr<State> player, shared_ptr<State> monster)
	{
		mPlayer = player;
		mMonster = monster;
	}

	bool NearCondition::operator()()
	{
		return mPlayer->Name() == mMonster->Name();
	};
}