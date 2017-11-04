#pragma once
#include <functional>
#include <memory>

using namespace std;

namespace Forgotten
{
	class State;

	typedef std::function<bool(shared_ptr<State>)> commandStatement;

	class Condition
	{
	public:

		Condition(shared_ptr<commandStatement> mStatement);
		virtual bool operator()(shared_ptr<State> state);
		virtual Condition& operator=(commandStatement) = 0;

	protected:
		shared_ptr<commandStatement> mCheck;

	};
}