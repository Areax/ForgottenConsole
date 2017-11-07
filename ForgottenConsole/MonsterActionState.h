#pragma once
#include "State.h"
#include "MonsterAttackAction.h"

using namespace std;

namespace Forgotten
{
	class Transition;

	class MonsterActionState : public State
	{
	public:
		MonsterActionState(string name);
		virtual void Enter() override;
		virtual void Exit() override;
		virtual void SetEnter(shared_ptr<Action> action);
		virtual void SetTick(shared_ptr<Action> action);
		virtual void SetExit();
		virtual shared_ptr<State> Update() override;
		virtual void Tick();
	private:
		shared_ptr<Action> enterAction;
		shared_ptr<Action> tickAction;
	};
}