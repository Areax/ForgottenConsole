#include "MonsterRoomState.h"
#include <iostream>
#include <fstream>
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MonsterRoomState::MonsterRoomState(string name)
	{
		mName = name;
	}

	void MonsterRoomState::Enter()
	{
		//Probably an action to check for a player here?
	}

	void MonsterRoomState::SetEnter(string textfile)
	{
	}

	void MonsterRoomState::Exit()
	{
	}

	void MonsterRoomState::SetExit()
	{
	}

	shared_ptr<State> MonsterRoomState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			if (t->IsTriggered())
				return t->Target();
		}

		return NULL;
	}
}
