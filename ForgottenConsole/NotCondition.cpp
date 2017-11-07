#include "NotCondition.h"

using namespace std;

namespace Forgotten
{
	NotCondition::NotCondition(shared_ptr<Condition> condition)
	{
		mCondition = condition;
	}

	bool NotCondition::operator()()
	{
		return !(mCondition->operator()());
	};
}