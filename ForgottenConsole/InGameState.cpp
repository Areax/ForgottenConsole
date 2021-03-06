#include "InGameState.h"
#include <iostream>
#include <fstream>
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	InGameState::InGameState(string name)
	{
		mName = name;
	}

	void InGameState::Enter()
	{
	}

	void InGameState::Exit()
	{
		if (mExit != nullptr)
			mExit->operator()();
	}

	shared_ptr<State> InGameState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			if (t->IsTriggered())
				return t->Target();
		}

		return NULL;
	}
}
