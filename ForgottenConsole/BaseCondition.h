#pragma once
#include "Condition.h"

namespace Forgotten
{
	class BaseCondition : public Condition
	{
	public:
		virtual bool operator()(shared_ptr<State> state);
		virtual Condition& operator=(shared_ptr<State> state);

		shared_ptr<commandStatement> mCheck;
	};
}