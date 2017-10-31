#include "stdafx.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	void State::enter()
	{
		cout << "ENTERED STATE";
	}

	void State::exit()
	{
		cout << "and we out bitches";
	}
}
