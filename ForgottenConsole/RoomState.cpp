#include "RoomState.h"

using namespace std;

namespace Forgotten
{
	RoomState::RoomState(string name)
	{
		mName = name;
	}

	void RoomState::Enter()
	{

	}

	void RoomState::Exit()
	{

	}

	shared_ptr<State> RoomState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			
			//if (t->IsTriggered())
				//return t->Target();
		}
		
		return NULL;
	}
}
