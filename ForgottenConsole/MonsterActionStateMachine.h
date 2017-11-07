#pragma once
#include "StateMachine.h"
#include "RoomsStateMachine.h"
#include "MonsterActionState.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class MonsterActionStateMachine : public StateMachine
	{
	public:
		MonsterActionStateMachine(shared_ptr<RoomsStateMachine> rms);
		virtual void Initialize() override;
		virtual shared_ptr<State> Update() override;
		void Tick();

	private:
		shared_ptr<RoomsStateMachine> player;
	};
}
