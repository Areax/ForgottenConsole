#pragma once
#include <string>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class CommandCondition : public Condition
	{
	public:
		CommandCondition(string command);
		virtual bool operator()();

		string mCommand;
	};
}