#include "stdafx.h"
#include "State.h"
#include "StateMachine.h"

using namespace std;

namespace Forgotten
{
	//Sets the current state to newState.
	void StateMachine::setCurrentState(shared_ptr<State> newState)
	{
		currentState = newState;
	}


}
