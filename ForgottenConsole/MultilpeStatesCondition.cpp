#pragma once
#include <string>
#include <algorithm>
#include "MultipleStatesCondition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MultipleStatesCondition::MultipleStatesCondition(string command, shared_ptr<State> state) : CommandCondition(command)
	{
		mState = state;
	}

	bool MultipleStatesCondition::operator()(shared_ptr<State> state)
	{
		return mState == state;
	}

}