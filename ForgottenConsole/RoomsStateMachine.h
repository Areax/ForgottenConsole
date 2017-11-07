#pragma once
#include "StateMachine.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class RoomsStateMachine : public StateMachine
	{
	public:
		RoomsStateMachine();
		virtual void Initialize();
		virtual shared_ptr<State> Update();
		void Tick();
	private:
		vector<shared_ptr<State>> RoomStates = vector<shared_ptr<State>>();
		shared_ptr<Action> discoverTheMonster;
	};
}