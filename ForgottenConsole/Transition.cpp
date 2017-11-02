#include "stdafx.h"
#include "Transition.h"

using namespace std;

namespace Forgotten
{
	void Transition::SetCondition(shared_ptr<Condition> condition)
	{
		mCondition = condition;
	}

	shared_ptr<Condition> Transition::GetCondition()
	{
		return mCondition;
	}

	void Transition::SetTarget(shared_ptr<State> target)
	{
		mTarget = target;
	}

	shared_ptr<State> Transition::Target()
	{
		return mTarget;
	}

	bool Transition::IsTriggered()
	{
		return true;//mCondition->operator()(mTarget);
	}

}