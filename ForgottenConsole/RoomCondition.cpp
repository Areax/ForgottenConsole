#include "RoomCondition.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	// keyword: check.  This is 100% the best way I could think of keeping similar states but separate conditions.
	// the idea is that 'RoomStateMachine' is the game environment, so it should instantiate the monster, not main (and update as well)
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