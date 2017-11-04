#pragma once
#include "State.h"
#include "NarrationAction.h"

using namespace std;

namespace Forgotten
{
	class Transition;

	class MonsterState : public State
	{
	public:
		MonsterState(string name, string textfile = "");
		virtual void Enter() override;
		virtual void Exit() override;
		virtual void SetEnter(string textfile);
		virtual void SetExit();
		virtual shared_ptr<State> Update() override;

	private:

	};
}
