#include "DieAction.h"
#include "Blackboard.h"

#include <iostream>
using namespace std;

namespace Forgotten
{
	void DieAction::operator()()
	{
		char consonant = Blackboard::GetPlayer()->RandomAvailableConsonant();
		while (consonant != NULL)
		{
			Blackboard::GetPlayer()->LoseLetter(consonant);
			consonant = Blackboard::GetPlayer()->RandomAvailableConsonant();
		}
	}
}



