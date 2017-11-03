#include "LeaveCondition.h"

namespace Forgotten
{
	LeaveCondition::LeaveCondition(shared_ptr<commandStatement> mStatement)
	{
		mCheck = mStatement;
	}

	bool LeaveCondition::operator()(string command)
	{
		return command == "leave";
	}
}