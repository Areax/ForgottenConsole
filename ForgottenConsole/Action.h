#pragma once
#include <string>
#include <functional>
#include "State.h"

namespace Forgotten
{
	class Action
	{
	public:
		virtual void operator()() = 0;

	protected:
		string mName;
	};
}