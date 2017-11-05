#include <string>
#include <vector>
#include<algorithm>
#include "MultipleStatesTransition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MultipleStatesTransition::MultipleStatesTransition() : CommandCondition(null)
	{
	}

	bool MultipleStatesTransition::AddState(shared_ptr<State> s)
	{
		mStates.push_back(s);
	}
	
	void MultipleStatesTransition::RemoveState(shared_ptr<State> s)
	{
		mStates.erase(remove(mStates.begin(), mStates.end(), s), mStates.end());
	}
	
	void MultipleStatesTransition::IsTriggered()
	{
		if(Transition::IsTriggered())
		{
			int r = random_element(0, (int)mStates.size());
			mTarget = mStates[r];
		}
	}

}