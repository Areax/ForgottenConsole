#pragma once
#include "StateMachine.h"
#include "RoomsStateMachine.h"
#include "MonsterStateMachine.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class PlayingSM : public StateMachine
	{
	public:
		PlayingSM();
		virtual void Initialize();
		virtual shared_ptr<State> Update();

	private:
		shared_ptr<RoomsStateMachine> playerSM;
		shared_ptr<MonsterStateMachine> monsterSM;
		shared_ptr<State> gameState;
	};
}