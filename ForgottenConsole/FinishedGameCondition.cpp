#pragma once
#include <string>
#include "FinishedGameCondition.h"
#include "Blackboard.h"

#include <iostream>
using namespace std;

namespace Forgotten
{
	bool FinishedGameCondition::operator()()
	{
		return Blackboard::GetPlayer()->RandomAvailableConsonant() == NULL;
	};
}