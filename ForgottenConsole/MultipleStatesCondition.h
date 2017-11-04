#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CommandCondition.h"

using namespace std;

namespace Forgotten
{
	class State;

	class MultipleStatesCondition : public CommandCondition
	{
	public:
		MultipleStatesCondition(string command, shared_ptr<State> state);
		bool operator()(shared_ptr<State> state);
	private:
		shared_ptr<State> mState;
	};
}