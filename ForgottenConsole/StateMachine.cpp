#include "stdafx.h"
#include "State.h"
#include "StateMachine.h"

using namespace std;

namespace Forgotten
{
	void StateMachine::AddState(shared_ptr<State> state)
	{
		mStates.insert(pair<string, shared_ptr<State>>(state->Name(), state));
	}

	void StateMachine::AddStates(vector<shared_ptr<State>> states)
	{
		for each(auto state in states)
		{
			StateMachine::AddState(state);
		}
	}

	//Sets the current state to newState.
	shared_ptr<State> StateMachine::getCurrentState()
	{
		return currentState;
	}

	//Sets the current state to newState.
	void StateMachine::setCurrentState(shared_ptr<State> state)
	{
		currentState = state;
	}

	const map<string, shared_ptr<State>>& StateMachine::States()
	{
		return mStates;
	}

	shared_ptr<State> StateMachine::Update()
	{
		if (currentState != NULL)
		{
			for each(Transition t in currentState.Transitions())
			{
				if (t.IsTriggered())
				{
					currentState->Exit();
					currentState = t.Target();
					currentState->Enter();
				}
			}
		}

		return shared_ptr<State>();
	}
}
