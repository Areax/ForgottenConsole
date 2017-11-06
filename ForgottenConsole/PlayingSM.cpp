#include <memory>
#include "RoomState.h"
#include "PlayingSM.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "MonsterCondition.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include "RoomCondition.h"
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
		shared_ptr<RoomsStateMachine> playerSM = make_shared<RoomsStateMachine>();
		shared_ptr<MonsterStateMachine> monsterSM = make_shared<MonsterStateMachine>();
		playerSM->Initialize();
		monsterSM->Initialize();

		shared_ptr<State> player = playerSM->getCurrentState();
		shared_ptr<State> monster = monsterSM->getCurrentState();

		currentState = player;
	}

	shared_ptr<State> PlayingSM::Update()
	{

		if (currentState != NULL)
		{
			shared_ptr<State> newState = currentState->Update();

			if (newState != NULL)
			{
				currentState->Exit();
				currentState = newState;
				currentState->Enter();
			}
		}
		return NULL;
	}
}
