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
		virtual void Initialize() = 0;
		virtual void AddState(shared_ptr<State> state);
		virtual void AddStates(vector<shared_ptr<State>> states);
		virtual shared_ptr<State> getCurrentState();
		virtual void setCurrentState(shared_ptr<State> state);
		virtual StateMachine& operator()(State state);
		virtual const map<string, shared_ptr<State>>& States();
		virtual shared_ptr<State> Update();

	private:
		shared_ptr<State> currentState;
		map<string, shared_ptr<State>> mStates;
}