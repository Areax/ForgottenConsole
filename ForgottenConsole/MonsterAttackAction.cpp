#include "MonsterAttackAction.h"
#include "Blackboard.h"
#include <fstream>
#include <iostream>

using namespace std;

namespace Forgotten
{
	int minimumLettersToLose = 1;
	int diffulty = 1;

	MonsterAttackAction::MonsterAttackAction()
	{
	}

	void MonsterAttackAction::operator()()
	{
		cout << "\n\nArgh! Out of nowhere a blind bememoth mentally pummles you to the ground.  You're being attacked!  You've lost: ";
		int numLettersLose = (rand() % diffulty) + 1 + minimumLettersToLose;
		for (int i = 0; i < numLettersLose; i++)
		{
			char consonant = Blackboard::GetPlayer()->RandomAvailableConsonant();
			cout << consonant << " ";
			Blackboard::GetPlayer()->LoseLetter(consonant);
		}
		cout << endl;
	}
}
