#pragma once
#include "StateMachine.h"
#include "RoomsStateMachine.h"
#include "MonsterActionStateMachine.h"
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
		virtual shared_ptr<State> Update() override;
		void Tick();

	private:
		shared_ptr<RoomsStateMachine> player;
		shared_ptr<MonsterActionStateMachine> monsterActionSM;
	};
}