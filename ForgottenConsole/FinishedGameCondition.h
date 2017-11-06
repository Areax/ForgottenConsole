#pragma once
#include <memory>
#include <functional>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class FinishedGameCondition : public Condition
	{
	public:
		virtual bool operator()() override;
	};
}
