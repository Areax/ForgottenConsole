#include <memory>
#include "PlayingSM.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "WhoseTurnCondition.h"
#include "Blackboard.h"
#include "MonsterMoves.h"
#include <iostream>
#include <stdlib.h>  
#include <time.h> 


using namespace std;

namespace Forgotten
{
	PlayingSM::PlayingSM()
	{

	}

	void PlayingSM::Initialize()
	{
		playerSM = make_shared<RoomsStateMachine>();
		monsterSM = make_shared<MonsterStateMachine>();
		playerSM->Initialize();
		monsterSM->Initialize();
	}

	shared_ptr<State> PlayingSM::Update()
	{
		playerSM->Update();
		monsterSM->Update();
		return NULL;
	}
}
