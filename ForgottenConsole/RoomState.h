#pragma once
#include "State.h"
#include "Action.h"
#include <memory>

using namespace std;

namespace Forgotten
{
	class Transition;

	class RoomState : public State
	{
	public:
		RoomState(string name);
		virtual void Enter() override;
		virtual void Exit() override;
		virtual shared_ptr<State> Update() override;
	};
}
