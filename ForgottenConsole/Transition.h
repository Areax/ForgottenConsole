#pragma once

using namespace std;

namespace Forgotten
{
	class Condition;
	class State;

	class Transition
	{
	public:
		void SetCondition(shared_ptr<Condition> condition);
		shared_ptr<Condition> GetCondition();
		void SetTarget(shared_ptr<State> target);
		shared_ptr<State> Target();
		bool IsTriggered();


	private:
		shared_ptr<Condition> mCondition;
		shared_ptr<State> mTarget;
	};
}