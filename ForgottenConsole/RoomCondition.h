#pragma once
#include <memory>
#include <functional>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	class RoomCondition : public Condition
	{
	public:
		RoomCondition(shared_ptr<Condition> condition);
		virtual bool operator()() override;
	private:
		shared_ptr<Condition> mCondition;
	};
}
