#pragma once
#include "State.h"

using namespace std;

namespace Forgotten
{
	class StateMachine
	{
	public:
		//Here, we're going to put a list of the states, which is optional btw.
		shared_ptr<State> currentState; //MUST HAVE THE CURRENT STATE THO.

		//Functions for the state machine.
		void setCurrentState(shared_ptr<State> currentState);
		//void updateState();
	};
}