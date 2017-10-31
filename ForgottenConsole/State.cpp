#include "stdafx.h"
#include "State.h"

using namespace std;

namespace Forgotten
{
	void State::Enter()
	{
		cout << "ENTERED STATE";
	}

	void State::Exit()
	{
		cout << "and we out bitches";
	}
}
