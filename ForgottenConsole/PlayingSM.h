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
	};
}