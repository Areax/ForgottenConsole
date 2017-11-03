#pragma once
#include <string>
#include <functional>
#include "State.h"

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