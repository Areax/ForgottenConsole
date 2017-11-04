#include "MonsterRoomState.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Forgotten
{
	MonsterRoomState::MonsterRoomState(string name, string textfile)
	{
		mName = name;
		//narrateEnter = NarrationAction(mName);
	}

	void MonsterRoomState::Enter()
	{
		cout << "The monster moves." << endl;
		//narrateEnter.operator()();
	}

	void MonsterRoomState::SetEnter(string textfile)
	{
		//narrateEnter = NarrationAction(mName);
	}

	void MonsterRoomState::Exit()
	{
		cout << "The monster leaves." << endl;
	}

	void MonsterRoomState::SetExit()
	{
		cout << "The monster leaves." << endl;
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
