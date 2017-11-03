#pragma once
#include <functional>
#include "Condition.h"

using namespace std;

namespace Forgotten
{
	//typedef std::function<bool(string)> commandStatement;

	class CommandCondition : public Condition
	{
	protected:
		virtual bool operator()(string command) = 0;
		virtual Condition& operator=(commandStatement) = 0;

		shared_ptr<commandStatement> mCheck;
	};
}