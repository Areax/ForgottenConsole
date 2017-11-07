#pragma once
#include <functional>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class SameStateCondition : public Condition
	{
	public:
		virtual bool operator()() override;
	};
}