#include "FindMonsterAction.h"
#include "Blackboard.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace Forgotten
{
	void FindMonsterAction::operator()()
	{
		cout << "The monster currently is in: " << Blackboard::GetMonsterState()->Name() << ".  But watch out, seems like you've forgotten something..." << endl;
		char consonant = Blackboard::GetPlayer()->RandomAvailableConsonant();
		Blackboard::GetPlayer()->LoseLetter(consonant);
	}
}
