#pragma once
#include <functional>
#include "BaseCondition.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	//conditionalStatement is a lambda expression.
	typedef std::function<bool(State&)> conditionalStatement;

	class Condition
	{
	public:

		Condition(shared_ptr<conditionalStatement> mStatement);
		virtual bool operator()(State & state);

	private:
		shared_ptr<conditionalStatement> mCheck;

	};
}