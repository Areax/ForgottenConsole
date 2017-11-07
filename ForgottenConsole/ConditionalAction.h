#pragma once
#include "Action.h"

namespace Forgotten
{
	class ConditionalAction : public Action
	{
	public:
		ConditionalAction(string name, shared_ptr<Condition> condition, shared_ptr<Action> action);
		virtual void operator()() override;
	private:
		shared_ptr<Condition> mCondition;
		shared_ptr<Action> mAction;
	};
}
