#pragma once
#include <memory>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class NotCondition : public Condition
	{
	public:
		NotCondition(shared_ptr<Condition> condition);
		virtual bool operator()() override;
	private:
		shared_ptr<Condition> mCondition;
	};
}
