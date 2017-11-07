#include <memory>
#include <stdlib.h>  
#include <time.h> 
#include <iostream>
#include "MonsterStateMachine.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "MonsterRoomState.h"
#include "MonsterCondition.h"
#include "MonsterMoves.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{
	MonsterStateMachine::MonsterStateMachine(shared_ptr<RoomsStateMachine> rms)
	{
		player = rms;
	}

	void MonsterStateMachine::Initialize()
	{
		shared_ptr<State> livingroom = make_shared<MonsterRoomState>("livingroom");
		shared_ptr<State> playroom = make_shared<MonsterRoomState>("playroom");
		shared_ptr<State> guestroom = make_shared<MonsterRoomState>("guestroom");
		shared_ptr<State> frontroom = make_shared<MonsterRoomState>("frontroom");
		shared_ptr<State> hallway = make_shared<MonsterRoomState>("hallway");

		shared_ptr<Transition> hallwayToLivingroom = make_shared<Transition>(livingroom);
		shared_ptr<Transition> livingroomToFrontroom = make_shared<Transition>(frontroom);
		shared_ptr<Transition> livingroomToHallway = make_shared<Transition>(hallway);
		shared_ptr<Transition> frontroomToPlayroom = make_shared<Transition>(playroom);
		shared_ptr<Transition> frontroomToLivingroom = make_shared<Transition>(livingroom);
		shared_ptr<Transition> playroomToFrontroom = make_shared<Transition>(hallway);

		hallway->AddTransition(hallwayToLivingroom);
		livingroom->AddTransition(livingroomToFrontroom);
		livingroom->AddTransition(livingroomToHallway);
		frontroom->AddTransition(frontroomToPlayroom);
		frontroom->AddTransition(frontroomToLivingroom);
		playroom->AddTransition(playroomToFrontroom);

		vector<shared_ptr<State>> RoomStates = vector<shared_ptr<State>>();
		RoomStates.push_back(livingroom);
		RoomStates.push_back(playroom);
		RoomStates.push_back(frontroom);
		RoomStates.push_back(hallway);

		srand((unsigned int)time(NULL));
		int monsterStart = rand() % 3;
		currentState = RoomStates[monsterStart]; //Randomly places a monster in a room that's not in computer room, kitchen, bedroom, or guestroom.
		Blackboard::SetMonsterState(currentState);

		shared_ptr<Condition> north = make_shared<MonsterCondition>("north");
		shared_ptr<Condition> south = make_shared<MonsterCondition>("south");
		shared_ptr<Condition> east = make_shared<MonsterCondition>("east");
		shared_ptr<Condition> west = make_shared<MonsterCondition>("west");


		hallwayToLivingroom->SetCondition(north);
		livingroomToHallway->SetCondition(south);
		livingroomToFrontroom->SetCondition(east);
		frontroomToLivingroom->SetCondition(west);
		frontroomToPlayroom->SetCondition(north);
		playroomToFrontroom->SetCondition(south);

		monsterActionSM = make_shared<MonsterActionStateMachine>(player);
		monsterActionSM->Initialize();

	}

	shared_ptr<State> MonsterStateMachine::Update()
	{
		monsterActionSM->Update();

		if (currentState != NULL)
		{
			Tick();

			shared_ptr<State> newState = currentState->Update();
			if (newState != NULL)
			{
				currentState->Exit();
				currentState = newState;
				currentState->Enter();
				Blackboard::SetMonsterState(currentState);
			}
		}
		return NULL;
		
	}

	void MonsterStateMachine::Tick()
	{
		//cout << "The monster's current whereabouts : " << currentState->Name() << endl;
	}
}
