#include "stdafx.h"
#include "State.h"
#include "StateMachine.h"

using namespace std;

namespace Forgotten
{
	void setCurrentState(shared_ptr<State> state)
	{
		currentState = state;
	}
}
