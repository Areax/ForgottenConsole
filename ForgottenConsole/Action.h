#pragma once
#include <string>
#include "Action.h"

using namespace std;

namespace Forgotten
{
	typedef std::function<void(State&)> action;
	class Action
	{
		virtual void operator()(State & state);

	private:
		string mName;
	};
}