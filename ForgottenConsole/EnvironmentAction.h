#pragma once
#include "Action.h"

namespace Forgotten
{
	class EnvironmentAction
	{
		EnvironmentAction(action);
		virtual void operator()(State & state);
		virtual EnvironmentAction& operator=(action)
		{
			return (*this);
		};
	};
}
