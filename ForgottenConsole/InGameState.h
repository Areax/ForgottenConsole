#pragma once
#include "State.h"
#include "NarrationAction.h"

using namespace std;

namespace Forgotten
{
	class Transition;

	class InGameState : public State
	{
	public:
		InGameState(string name);
		virtual void Enter() override;
		virtual void Exit() override;
		virtual shared_ptr<State> Update() override;
	private:
		NarrationAction exitAction;
	};
}
