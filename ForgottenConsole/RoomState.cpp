#include "RoomState.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	RoomState::RoomState(string name)
	{
		mName = name;
	}

	void RoomState::Enter()
	{
		cout << "Now entering Numbani" << endl;
	}

	void RoomState::Exit()
	{
		cout << "Now leaving..." << endl;
	}

	shared_ptr<State> RoomState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			
			if (t->IsTriggered())
				return t->Target();
		}
		
		return NULL;
	}
}
