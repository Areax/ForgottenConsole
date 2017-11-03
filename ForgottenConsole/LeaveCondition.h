#pragma once
#include <functional>
#include <memory>
#include "CommandCondition.h"

using namespace std;

namespace Forgotten
{
	class LeaveCondition : public CommandCondition
	{
	public:

		LeaveCondition(shared_ptr<commandStatement> mStatement);
		virtual bool operator()(string command) override;
	};
}