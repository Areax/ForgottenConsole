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

		//Condition(shared_ptr<conditionalStatement> mStatement);
		//virtual bool operator()(shared_ptr<State> state) = 0;
		//virtual Condition& operator=(conditionalStatement) = 0;

	protected:
		//shared_ptr<commandStatement> mCheck;

	};
}