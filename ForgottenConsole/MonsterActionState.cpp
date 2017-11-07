#include "MonsterActionState.h"
#include <iostream>
#include <fstream>
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MonsterActionState::MonsterActionState(string name)
	{
		mName = name;
	}

	void MonsterActionState::Enter()
	{
		if (tickAction != NULL)
			enterAction->operator()();
	}

	void MonsterActionState::SetEnter(shared_ptr<Action> action)
	{
		enterAction = action;
	}

	void MonsterActionState::SetTick(shared_ptr<Action> action)
	{
		tickAction = action;
	}

	void MonsterActionState::Exit()
	{
	}

	void MonsterActionState::SetExit()
	{
	}

	shared_ptr<State> MonsterActionState::Update()
	{
		for each(shared_ptr<Transition> t in mTransitions)
		{
			if (t->IsTriggered())
				return t->Target();
		}
		Tick();
		return NULL;
	}

	void MonsterActionState::Tick()
	{
		if(tickAction != NULL)
			tickAction->operator()();
	}
}
