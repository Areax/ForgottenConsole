#pragma once
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class State;

	class Transition
	{
	public:
		Transition(shared_ptr<State> target);
		void SetCondition(shared_ptr<Condition> condition);
		shared_ptr<Condition> GetCondition();
		virtual void SetTarget(shared_ptr<State> target);
		virtual shared_ptr<State> Target();
		virtual bool IsTriggered();


	private:
		shared_ptr<Condition> mCondition;
		shared_ptr<State> mTarget;
	};
}