#include "stdafx.h"
#include "Action.h"

namespace Forgotten
{
	Action::Action()
	{
	}
	Action::Action(string name)
	{
		mName = name;
	}
	string Action::Name()
	{
		return mName;
	}
}
