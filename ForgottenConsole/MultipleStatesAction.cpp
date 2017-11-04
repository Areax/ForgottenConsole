#include <string>
#include <vector>
#include<algorithm>
#include "MultipleStatesAction.h"
#include "MultipleStatesCondition.h"

using namespace std;

namespace Forgotten
{
	MultipleStatesAction::MultipleStatesAction(string name) : Action(name)
	{
	}
	void MultipleStatesAction::AddState(shared_ptr<State> s)
	{
		mStates.push_back(s);
	}

	void MultipleStatesAction::RemoveState(shared_ptr<State> s)
	{
		mStates.erase(remove(mStates.begin(), mStates.end(), s), mStates.end());
	}

	vector<shared_ptr<State>> MultipleStatesAction::States()
	{
		return vector<shared_ptr<State>>();
	}

	void MultipleStatesAction::operator()()
	{
		int r = random_element(0, (int)mStates.size());
		MultipleStatesCondition c = MultipleStatesCondition(mName, mStates[r]);
	};
}