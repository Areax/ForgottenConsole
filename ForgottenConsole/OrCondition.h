#pragma once
#include <memory>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class OrCondition : public Condition
	{
	public:
		OrCondition(shared_ptr<Condition> a, shared_ptr<Condition> b);
		virtual bool operator()() override;
	private:
		shared_ptr<Condition> mA;
		shared_ptr<Condition> mB;
	};
}
