#pragma once
#include <string>
#include <functional>
#include "State.h"

namespace Forgotten
{
	class Action
	{
	public:
		Action();
		Action(string name);
		virtual void operator()() = 0;
		virtual string Name();

	protected:
		string mName;
	};
}