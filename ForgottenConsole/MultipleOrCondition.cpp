#include "MultipleOrCondition.h"

using namespace std;

namespace Forgotten
{
	void MultipleOrCondition::AddCondition(shared_ptr<Condition> condition)
	{
		conditions.push_back(condition);
	}
	bool MultipleOrCondition::operator()()
	{
		for (shared_ptr<Condition> c : conditions)
		{
			if (c->operator()())
				return true;
		}
		return false;
	};
}