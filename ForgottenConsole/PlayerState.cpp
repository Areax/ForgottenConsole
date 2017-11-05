#include "PlayerState.h"
#include <iostream>
#include <fstream>
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	PlayerState::PlayerState()
	{
	}

	void PlayerState::Enter()
	{
		cout << "YOU WON" << endl;
	}

	void PlayerState::SetEnter(string textfile)
	{
		cout << "YOU WON" << endl;
	}

	void PlayerState::Exit()
	{
	}

	void PlayerState::SetExit()
	{
	}

	shared_ptr<State> PlayerState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			if (t->IsTriggered())
				return t->Target();
		}

		return NULL;
	}
}
