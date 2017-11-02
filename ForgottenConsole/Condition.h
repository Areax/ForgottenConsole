#pragma once
#include <functional>
#include "State.h"

using namespace std;

namespace Forgotten
{
	//conditionalStatement is a lambda expression.
	typedef std::function<bool(shared_ptr<State>)> conditionalStatement;

	class Condition
	{
	public:

		Condition(shared_ptr<conditionalStatement> mStatement);
		virtual bool operator()(shared_ptr<State> state) = 0;
		virtual Condition& operator=(conditionalStatement) = 0;

	protected:
		shared_ptr<conditionalStatement> mCheck;

	};
}