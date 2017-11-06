#pragma once
#include <memory>
#include <vector>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class MultipleOrCondition : public Condition
	{
	public:
		void AddCondition(shared_ptr<Condition> condition);
		virtual bool operator()() override;
	private:
		vector<shared_ptr<Condition>> conditions;
	};
}
#pragma once
