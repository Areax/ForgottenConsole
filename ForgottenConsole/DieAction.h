#pragma once
#include "Action.h"

namespace Forgotten
{
	class DieAction : public Action
	{
	public:
		virtual void operator()() override;
	};
}
