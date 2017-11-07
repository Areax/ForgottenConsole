#pragma once
#include "Action.h"

namespace Forgotten
{
	class MonsterWanderAction : public Action
	{
	public:
		MonsterWanderAction();
		virtual void operator()() override;
	private:
		string direction[5] = { "north", "south", "east", "west", "idle" };
	};
}
