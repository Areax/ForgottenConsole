#include "stdafx.h"
#include "Condition.h"

namespace Forgotten
{
	Condition::Condition(shared_ptr<conditionalStatement> mStatement)
	{
		mStatement = mCheck;
	}

	bool Condition::operator()(shared_ptr<State> state)
	{
		return ;
	}


}