#pragma once
#include "Action.h"

namespace Forgotten
{
	class FindMonsterAction : public Action
	{
	public:
		virtual void operator()() override;
	};
}
