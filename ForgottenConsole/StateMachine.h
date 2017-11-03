#pragma once
#include "State.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class StateMachine
	{
	public:
		void AddState(shared_ptr<State> state);
		void AddStates(vector<shared_ptr<State>> states);
		void setCurrentState(shared_ptr<State> state);
		const map<string, shared_ptr<State>>& States();
		shared_ptr<State> getCurrentState();

		virtual void Initialize() = 0;
		virtual shared_ptr<State> Update() = 0;

	protected:
		shared_ptr<State> currentState;
		map<string, shared_ptr<State>> mStates;
	};
}