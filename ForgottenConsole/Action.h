#pragma once
#include <string>
#include "Action.h"

namespace Forgotten
{
	typedef std::function<void(State&)> action;
	class Action
	{
		Action(action);
		virtual void operator()(State & state);
		virtual Action& operator=(action)
		{
			return (*this);
		};


	private:
		string mName;
	};
}