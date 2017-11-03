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
		virtual StateMachine& operator()(shared_ptr<State> state);
		virtual shared_ptr<State> Update();
	};
}