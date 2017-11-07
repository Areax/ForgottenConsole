#include "RoomCondition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	RoomCondition::RoomCondition(shared_ptr<Condition> condition)
	{
		mCondition = condition;
	}

	bool RoomCondition::operator()()
	{
		return mCondition->operator()();
	};
}