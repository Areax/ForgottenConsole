#pragma once
#include "State.h"
#include <memory>

using namespace std;

namespace Forgotten
{
	class StateMachine
	{
	public:
		//Here, we're going to put a list of the states, which is optional btw.
		shared_ptr<State> currentState; //MUST HAVE THE CURRENT STATE THO.
		shared_ptr<State> targetState;

		//Functions for the state machine.
		void setCurrentState(shared_ptr<State> currentState);
		shared_ptr<State> updateState();
	};

	//Sets the current state to newState.
	void StateMachine::setCurrentState(shared_ptr<State> newState)
	{
		currentState = newState;
	}

	inline shared_ptr<State> StateMachine::updateState()
	{
		if (targetState != NULL)
		{
			currentState->Exit();
			currentState = targetState;
			currentState->Enter();
		}

		return shared_ptr<State>();
	}
}