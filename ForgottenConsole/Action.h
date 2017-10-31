#pragma once
#include <string>
#include "Action.h"

using namespace std;

namespace Forgotten
{
	class Action
	{
		string mName;
		Action();
		//~Action();

		void operator()();
	};
}