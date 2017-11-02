#include <memory>
#include "BaseCondition.h"

using namespace std;

namespace Forgotten
{
	bool BaseCondition::operator()(shared_ptr<State> state)
	{
		return mCheck->operator()(state);
	}
	Condition & BaseCondition::operator=(shared_ptr<State> state)
	{
		return (*this);
	}
}
