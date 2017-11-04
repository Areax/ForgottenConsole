#pragma once
#include <string>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class MonsterCondition : public Condition
	{
	public:
		MonsterCondition(string command, string input);
		virtual bool operator()();

		string mCommand;
		string mInput;
	};
}