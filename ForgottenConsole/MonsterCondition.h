#pragma once
#include <string>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class MonsterCondition : public Condition
	{
	public:
		MonsterCondition(string move);
		virtual bool operator()() override;

		string mMove;
	};
}