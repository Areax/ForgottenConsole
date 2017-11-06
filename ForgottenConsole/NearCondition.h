#pragma once
#include <string>
#include "Condition.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	class NearCondition : public Condition
	{
	public:
		NearCondition(shared_ptr<State> player, shared_ptr<State> monster);
		virtual bool operator()();

		shared_ptr<State> mPlayer;
		shared_ptr<State> mMonster;
	};
}