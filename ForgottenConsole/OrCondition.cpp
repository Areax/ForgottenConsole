#include "OrCondition.h"

using namespace std;

namespace Forgotten
{
	OrCondition::OrCondition(shared_ptr<Condition> a, shared_ptr<Condition> b)
	{
		mA = a;
		mB = b;
	}

	bool OrCondition::operator()()
	{
		return mA->operator()() || mB->operator()();
	};
}