#pragma once
#include "StateMachine.h"
#include <memory>
#include <map>

using namespace std;

namespace Forgotten
{
	class MonsterStateMachine : public StateMachine
	{
	public:
		MonsterStateMachine();
		virtual void Initialize();
		virtual shared_ptr<State> Update();
	};
}