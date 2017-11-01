#pragma once
#include "Condition.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	class Transition
	{
		void SetCondition(shared_ptr<Condition> condition);
		shared_ptr<Condition> GetCondition();
		void SetTarget(shared_ptr<State> target);
		shared_ptr<State> Target();
		bool isTriggered();


	private:
		shared_ptr<Condition> mCondition;
		shared_ptr<State> mTarget;
	};
}