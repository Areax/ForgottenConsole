#pragma once
#include <string>
#include "Condition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	class WhoseTurnCondition : public Condition
	{
	public:
		WhoseTurnCondition(Blackboard::Turn turn);
		virtual bool operator()();

		Blackboard::Turn mTurn;
	};
}