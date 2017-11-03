#include "EnvironmentAction.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	void EnvironmentAction::operator()(State & state)
	{
		cout << "Entering " << state.Name() << endl;
	}
}
