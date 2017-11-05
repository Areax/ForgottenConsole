#include <memory>
#include <stdlib.h>  
#include <time.h> 
#include <iostream>
#include "RoomsStateMachine.h"
#include "Transition.h"
#include "MonsterCondition.h"
#include "MonsterMoves.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{

	MonsterStateMachine::MonsterStateMachine(shared_ptr<State> state)
	{
		currentState = state;
	}

	void MonsterStateMachine::Initialize()
	{

	}

	shared_ptr<State> MonsterStateMachine::Update()
	{
		if (currentState != NULL)
		{
			Blackboard::SetTurn(Blackboard::Monster);
			srand((unsigned int)time(NULL));
			monsterMove = rand() % 4;

			MonsterMoves::SetMove(direction[monsterMove]);

			shared_ptr<State> newState = currentState->Update();
			cout << "Monster went from: " << currentState->Name() << '\n';

			if (newState != NULL)
			{
				currentState->Exit();
				currentState = newState;
				currentState->Enter();
			}

			cout << "Monster went to: " << currentState->Name() << '\n';
		}
		return NULL;
	}
}
