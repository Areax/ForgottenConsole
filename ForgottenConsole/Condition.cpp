#include "stdafx.h"
#include "Condition.h"

namespace Forgotten
{
	Condition::Condition(shared_ptr<conditionalStatement> mStatement)
	{
		mCheck = mStatement;
	}
	
	bool Condition::operator()(shared_ptr<State> state)
	{
		return (mCheck*)(state);
	}



}