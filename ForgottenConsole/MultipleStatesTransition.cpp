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

	void MultipleStatesTransition::AddTarget(shared_ptr<State> s)
	{
		mTargets.push_back(s);
	}
	
	void MultipleStatesTransition::RemoveTarget(shared_ptr<State> s)
	{
		mTargets.erase(remove(mTargets.begin(), mTargets.end(), s), mTargets.end());
	}
	
	bool MultipleStatesTransition::IsTriggered()
	{
		if(Transition::IsTriggered())
		{
			mTarget = *select_randomly(mTargets.begin(), mTargets.end());
			return true;
		}
		return false;
	}

}