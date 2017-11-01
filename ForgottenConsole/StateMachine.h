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
		virtual void AddState(shared_ptr<State> state);
		virtual void AddStates(vector<shared_ptr<State>> states);
		virtual shared_ptr<State> getCurrentState();
		virtual void Initialize();
		virtual StateMachine& operator()(State state);
		virtual void setCurrentState(shared_ptr<State> state);
		virtual const map<string, shared_ptr<State>> States();
			shared_ptr<State> Update();

	private:
		shared_ptr<State> currentState;
		map<string, shared_ptr<State>> mStates;
}