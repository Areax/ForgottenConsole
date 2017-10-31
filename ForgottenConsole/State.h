#pragma once
#include "Action.h"
#include "Transition.h"
#include <string>
#include <vector>

using namespace std;

namespace Forgotten
{
	class State
	{
	public:
		
		shared_ptr<Action> mEnter;
		shared_ptr<Action> mExit;
		vector<shared_ptr<Transition>> mTransitions;
		string mName;


		void Enter();
		void Exit();

	};
}