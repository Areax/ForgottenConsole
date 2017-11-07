#include "MonsterWanderAction.h"
#include "Blackboard.h"
#include <iostream>
#include <stdlib.h>  
#include <time.h> 
#include "MonsterMoves.h"

using namespace std;

namespace Forgotten
{
	MonsterWanderAction::MonsterWanderAction()
	{
		srand((unsigned int)time(NULL));
	}

	void MonsterWanderAction::operator()()
	{
		string state = direction[rand() % (direction->size())];
		MonsterMoves::SetMove(state);
	}
}
