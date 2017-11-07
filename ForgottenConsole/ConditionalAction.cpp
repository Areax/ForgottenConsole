#include "ConditionalAction.h"

#include <iostream>
using namespace std;

namespace Forgotten
{
	ConditionalAction::ConditionalAction(string name, shared_ptr<Condition> condition, shared_ptr<Action> action) : Action(name)
	{
		mCondition = condition;
		mAction = action;
	}

	void ConditionalAction::operator()()
	{
		if (mCondition->operator()())
			mAction->operator()();
	}
}
