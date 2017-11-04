#include <memory>
#include <stdlib.h>  
#include <time.h> 
#include <iostream>
#include "MonsterRoomState.h"
#include "MonsterStateMachine.h"
#include "RoomsStateMachine.h"
#include "Transition.h"
#include "MonsterCondition.h"

using namespace std;

namespace Forgotten
{
	MonsterStateMachine::MonsterStateMachine()
	{

	}

	void MonsterStateMachine::Initialize()
	{
		shared_ptr<RoomsStateMachine> roomsSM;

		srand((unsigned int)time(NULL));
		monsterMove = rand() % 4;

		shared_ptr<State> bedroom = make_shared<MonsterRoomState>("bedroom");
		shared_ptr<State> bathroom = make_shared<MonsterRoomState>("bathroom");
		shared_ptr<State> livingroom = make_shared<MonsterRoomState>("livingroom");
		shared_ptr<State> kitchen = make_shared<MonsterRoomState>("kitchen");
		shared_ptr<State> playroom = make_shared<MonsterRoomState>("playroom");
		shared_ptr<State> guestroom = make_shared<MonsterRoomState>("guestroom");
		shared_ptr<State> frontroom = make_shared<MonsterRoomState>("frontroom");
		shared_ptr<State> hallway = make_shared<MonsterRoomState>("hallway");
		shared_ptr<State> computerroom = make_shared<MonsterRoomState>("computerroom");

		shared_ptr<Transition> bedroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bedroomToBathroom = make_shared<Transition>(bathroom);

		shared_ptr<Condition> north = make_shared<MonsterCondition>("north", direction[monsterMove]);
		shared_ptr<Condition> south = make_shared<MonsterCondition>("south", direction[monsterMove]);
		shared_ptr<Condition> east = make_shared<MonsterCondition>("east", direction[monsterMove]);
		shared_ptr<Condition> west = make_shared<MonsterCondition>("west", direction[monsterMove]);

		bedroomToComputerroom->SetCondition(north);
		bedroomToBathroom->SetCondition(south);

		bedroom->AddTransition(bedroomToComputerroom);
		bedroom->AddTransition(bedroomToBathroom);

		vector<shared_ptr<State>> MonsterRoomStates = vector<shared_ptr<State>>();
		MonsterRoomStates.push_back(bedroom);
		MonsterRoomStates.push_back(bathroom);
		MonsterRoomStates.push_back(livingroom);
		MonsterRoomStates.push_back(kitchen);
		MonsterRoomStates.push_back(playroom);
		MonsterRoomStates.push_back(guestroom);
		MonsterRoomStates.push_back(frontroom);
		MonsterRoomStates.push_back(hallway);
		MonsterRoomStates.push_back(computerroom);

		currentState = bedroom;

	}

	shared_ptr<State> MonsterStateMachine::Update()
	{
		if (currentState != NULL)
		{
			shared_ptr<State> newState = currentState->Update();

			cout << "Monster is in: " << currentState->Name() << '\n';

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
