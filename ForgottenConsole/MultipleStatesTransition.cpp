#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "CommandCondition.h"
#include "MultipleStatesTransition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MultipleStatesTransition::MultipleStatesTransition() : Transition(NULL)
	{
	}

	void MultipleStatesTransition::AddState(shared_ptr<State> s)
	{
		mStates.push_back(s);
	}
	
	void MultipleStatesTransition::RemoveState(shared_ptr<State> s)
	{
		mStates.erase(remove(mStates.begin(), mStates.end(), s), mStates.end());
	}
	
	bool MultipleStatesTransition::IsTriggered()
	{
		if(Transition::IsTriggered())
		{
			mTarget = *select_randomly(mStates.begin(), mStates.end());
			return true;
		}
		return false;
	}

}