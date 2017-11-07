#pragma once
#include <functional>
#include <memory>
#include <string>
#include "SameStateCondition.h"
#include "Blackboard.h"
#include "State.h"

#include <iostream>

using namespace std;

namespace Forgotten
{
	bool SameStateCondition::operator()()
	{
		return Blackboard::GetMonsterState()->Name() == Blackboard::GetPlayerState()->Name();
	}
}