#pragma once
#include "Action.h"

namespace Forgotten
{
	class MonsterAttackAction : public Action
	{
	public:
		MonsterAttackAction();
		virtual void operator()() override;
	};
}
