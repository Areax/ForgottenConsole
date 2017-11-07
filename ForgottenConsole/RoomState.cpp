#include "RoomState.h"
#include <iostream>
#include <fstream>
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	RoomState::RoomState(string name, string textfile)
	{
		mName = name;
		narrateEnter = NarrationAction(mName);
	}

	void RoomState::Enter()
	{
		narrateEnter.operator()();
	}

	void RoomState::SetEnter(string textfile)
	{
		narrateEnter = NarrationAction(mName);
	}

	void RoomState::Exit()
	{
	}

	void RoomState::SetExit()
	{
		//should be an action if anything
		//cout << "Now leaving..." << endl;
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
