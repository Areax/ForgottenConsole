#include <memory>
#include "RoomState.h"
#include "RoomsStateMachine.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "MonsterCondition.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include "RoomCondition.h"
#include "MonsterStateMachine.h"
#include <iostream>
#include <stdlib.h>  
#include <time.h> 


using namespace std;

namespace Forgotten
{
	RoomsStateMachine::RoomsStateMachine()
	{

	}

	void RoomsStateMachine::Initialize()
	{
		// keyword: a lot of work lol.  Time to implement all of the south/west/north/east !!!
		// then we'll need to add a state where, if the letter was lost, you're screwed.  Should be somewhere in the code
		// in any case, basic text comes first
		// trying currently to implement the following:
		// run, flee, leave (randomly picks a Target to flee to, MultipleStateTransitions)
		// dictionary (prints out all words that we can use. HashMap maps word -> definition (definitions hidden until you lose more letters)
		// win, lose, unlock, east, finish, leave, transcend, die, complete (finishes the game (only with key & in front room), but all have different text files. Neat right?)
		// remove, kill, delete + letter (resets monster to a random room (or the kitchen? maybe he just eats it) but you lose that letter. Shouldn't be a hard action to implement)
		// advanced actions would probably include obscure words to utilize for more fun situations (less popular letters too like b,z,x,y,g,h,j,q,r,u,v,w)
		shared_ptr<State> bedroom = make_shared<RoomState>("bedroom");
		shared_ptr<State> bathroom = make_shared<RoomState>("bathroom");
		shared_ptr<State> livingroom = make_shared<RoomState>("livingroom");
		shared_ptr<State> kitchen = make_shared<RoomState>("kitchen");
		shared_ptr<State> playroom = make_shared<RoomState>("playroom");
		shared_ptr<State> guestroom = make_shared<RoomState>("guestroom");
		shared_ptr<State> frontroom = make_shared<RoomState>("frontroom");
		shared_ptr<State> hallway = make_shared<RoomState>("hallway");
		shared_ptr<State> computerroom = make_shared<RoomState>("computerroom");
		shared_ptr<State> winState = make_shared<RoomState>("victory");

		shared_ptr<Transition> bedroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bedroomToBathroom = make_shared<Transition>(bathroom);
		shared_ptr<Transition> bedroomToLivingroom = make_shared<Transition>(livingroom);
		shared_ptr<Transition> computerroomToBedroom = make_shared<Transition>(bedroom);
		shared_ptr<Transition> bathroomToHallway = make_shared<Transition>(hallway);
		shared_ptr<Transition> hallwayToBathroom = make_shared<Transition>(bathroom);
		shared_ptr<Transition> hallwayToGuestroom = make_shared<Transition>(guestroom);
		shared_ptr<Transition> hallwayToLivingroom = make_shared<Transition>(livingroom);
		shared_ptr<Transition> guestroomToHallmay = make_shared<Transition>(hallway);
		//shared_ptr<Transition> livingroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> livingroomToKitchen = make_shared<Transition>(kitchen);
		shared_ptr<Transition> livingroomToBedroom = make_shared<Transition>(bedroom);
		shared_ptr<Transition> livingroomToFrontroom = make_shared<Transition>(frontroom);
		shared_ptr<Transition> livingroomToHallway = make_shared<Transition>(hallway);
		shared_ptr<Transition> frontroomToPlayroom = make_shared<Transition>(playroom);
		shared_ptr<Transition> frontroomToLivingroom = make_shared<Transition>(livingroom);
		shared_ptr<Transition> playroomToKitchen = make_shared<Transition>(kitchen);
		shared_ptr<Transition> playroomToFrontroom = make_shared<Transition>(hallway);
		shared_ptr<Transition> kitchenToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> victory = make_shared<Transition>(winState);


		bedroom->AddTransition(bedroomToComputerroom);
		bedroom->AddTransition(bedroomToBathroom);
		bedroom->AddTransition(bedroomToLivingroom);
		computerroom->AddTransition(computerroomToBedroom);
		bathroom->AddTransition(bathroomToHallway); 
		hallway->AddTransition(hallwayToBathroom);
		hallway->AddTransition(hallwayToGuestroom);
		hallway->AddTransition(hallwayToLivingroom);
		guestroom->AddTransition(guestroomToHallmay);
		guestroom->AddTransition(victory);
		//livingroom->AddTransition(livingroomToComputerroom);
		livingroom->AddTransition(livingroomToKitchen);
		livingroom->AddTransition(livingroomToBedroom);
		livingroom->AddTransition(livingroomToFrontroom);
		livingroom->AddTransition(livingroomToHallway);
		frontroom->AddTransition(frontroomToPlayroom);
		frontroom->AddTransition(frontroomToLivingroom);
		playroom->AddTransition(playroomToKitchen);
		playroom->AddTransition(playroomToFrontroom);
		kitchen->AddTransition(kitchenToComputerroom);

		vector<shared_ptr<State>> RoomStates = vector<shared_ptr<State>>();
		RoomStates.push_back(bathroom);
		RoomStates.push_back(livingroom);
		RoomStates.push_back(playroom);
		RoomStates.push_back(frontroom);
		RoomStates.push_back(hallway);
		RoomStates.push_back(computerroom);
		RoomStates.push_back(bedroom);
		RoomStates.push_back(kitchen);
		RoomStates.push_back(guestroom);
	
		currentState = bedroom;

		monster = make_shared<MonsterStateMachine>(getCurrentState());
		monster->Initialize();

		srand((unsigned int)time(NULL));
		int monsterStart = rand() % 4;
		monster->setCurrentState(RoomStates[monsterStart]); //Randomly places a monster in a room that's not in computer room, kitchen, bedroom, or guestroom.


		shared_ptr<Condition> run = make_shared<CommandCondition>("run");
		shared_ptr<Condition> leave = make_shared<CommandCondition>("leave");
		shared_ptr<Condition> northPlayer = make_shared<CommandCondition>("north");
		shared_ptr<Condition> southPlayer = make_shared<CommandCondition>("south");
		shared_ptr<Condition> eastPlayer = make_shared<CommandCondition>("east");
		shared_ptr<Condition> westPlayer = make_shared<CommandCondition>("west");

		shared_ptr<Condition> northMonster = make_shared<MonsterCondition>("north");
		shared_ptr<Condition> southMonster = make_shared<MonsterCondition>("south");
		shared_ptr<Condition> eastMonster = make_shared<MonsterCondition>("east");
		shared_ptr<Condition> westMonster = make_shared<MonsterCondition>("west");

		shared_ptr<Condition> north = make_shared<RoomCondition>(northPlayer, northMonster);
		shared_ptr<Condition> south = make_shared<RoomCondition>(southPlayer, southMonster);
		shared_ptr<Condition> east = make_shared<RoomCondition>(eastPlayer, eastMonster);
		shared_ptr<Condition> west = make_shared<RoomCondition>(westPlayer, westMonster);

		//Temp win con since I'm lazy. Probablt change this to passing in a set with the specific key words(?)
		shared_ptr<Condition> win = make_shared<CommandCondition>("VICTORY");

		bedroomToComputerroom->SetCondition(northPlayer);
		bedroomToBathroom->SetCondition(southPlayer);
		bedroomToLivingroom->SetCondition(eastPlayer);

		computerroomToBedroom->SetCondition(southPlayer);

		bathroomToHallway->SetCondition(eastPlayer);

		hallwayToBathroom->SetCondition(westPlayer);
		hallwayToGuestroom->SetCondition(southPlayer);
		hallwayToLivingroom->SetCondition(north);

		guestroomToHallmay->SetCondition(northPlayer);
		victory->SetCondition(win);

		livingroomToKitchen->SetCondition(northPlayer);
		livingroomToBedroom->SetCondition(westPlayer);
		livingroomToHallway->SetCondition(south);
		livingroomToFrontroom->SetCondition(east);

		frontroomToLivingroom->SetCondition(west);
		frontroomToPlayroom->SetCondition(north);

		playroomToKitchen->SetCondition(westPlayer);
		playroomToFrontroom->SetCondition(south);

		kitchenToComputerroom->SetCondition(westPlayer);

	}

	shared_ptr<State> RoomsStateMachine::Update()
	{
		// keyword: rethink.  Should monster be updated first? If so chasing is very easy
		// if not, character may run into position where the monster can 'see' him/her
		
		monster->Update();

		if (currentState != NULL)
		{
			Blackboard::SetTurn(Blackboard::Player);
			//cout << "Current State coming in : " << currentState->Name() << '\n';
			shared_ptr<State> newState = currentState->Update();

			if (newState != NULL)
			{
				currentState->Exit();
				currentState = newState;
				currentState->Enter();
			}

			//cout << "Current State coming out : " << currentState->Name() << '\n';
		}
		return NULL;
	}
}
