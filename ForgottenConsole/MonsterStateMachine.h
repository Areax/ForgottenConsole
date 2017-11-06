#pragma once
#include "StateMachine.h"
#include "RoomsStateMachine.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class MonsterStateMachine : public StateMachine
	{
	public:
		MonsterStateMachine(shared_ptr<RoomsStateMachine> rms);
		virtual void Initialize() override;
		virtual shared_ptr<State> Update();

	private:
		string direction[4] = { "north", "south", "east", "west" };
		int monsterMove;
		shared_ptr<RoomsStateMachine> player;
	};
}