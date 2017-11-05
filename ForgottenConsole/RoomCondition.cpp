#include "RoomCondition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	RoomCondition::RoomCondition(shared_ptr<Condition> playerCondition, shared_ptr<Condition> monsterCondition)
	{
		mPlayerCondition = playerCondition;
		mMonsterCondition = monsterCondition;
	}

	bool RoomCondition::operator()()
	{
		switch (Blackboard::GetTurn())
		{
		case Blackboard::Player:
			return mPlayerCondition->operator()();
			break;
		case Blackboard::Monster:
			return mMonsterCondition->operator()();
			break;
		}
		return false;
	};
}