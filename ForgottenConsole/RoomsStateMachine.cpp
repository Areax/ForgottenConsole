#include <memory>
#include "RoomState.h"
#include "RoomsStateMachine.h"
#include "Transition.h"
#include "MultipleStatesTransition.h"
#include "CommandCondition.h"
#include "MonsterCondition.h"
#include "OrCondition.h"
#include "NarrationAction.h"
#include "Blackboard.h"
#include "RoomCondition.h"
#include "MultipleOrCondition.h"
#include <iostream>


using namespace std;

namespace Forgotten
{
	RoomsStateMachine::RoomsStateMachine()
	{
	}

	void RoomsStateMachine::Initialize()
	{		
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
		shared_ptr<Transition> playroomToHallway = make_shared<Transition>(hallway);
		shared_ptr<Transition> kitchenToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> victory = make_shared<Transition>(winState);

		MultipleStatesTransition bedroomLeavingRaw = MultipleStatesTransition();
		bedroomLeavingRaw.AddTarget(computerroom);
		bedroomLeavingRaw.AddTarget(bathroom);
		bedroomLeavingRaw.AddTarget(livingroom);
		shared_ptr<Transition> bedroomLeaving = make_shared<MultipleStatesTransition>(bedroomLeavingRaw);
		bedroom->AddTransition(bedroomLeaving);

		MultipleStatesTransition computerroomLeavingRaw = MultipleStatesTransition();
		computerroomLeavingRaw.AddTarget(bedroom);
		shared_ptr<Transition> computerroomLeaving = make_shared<MultipleStatesTransition>(computerroomLeavingRaw);
		computerroom->AddTransition(computerroomLeaving);

		MultipleStatesTransition bathroomLeavingRaw = MultipleStatesTransition();
		bathroomLeavingRaw.AddTarget(hallway);
		shared_ptr<Transition> bathroomLeaving = make_shared<MultipleStatesTransition>(bathroomLeavingRaw);
		bathroom->AddTransition(bathroomLeaving);

		MultipleStatesTransition hallwayLeavingRaw = MultipleStatesTransition();
		hallwayLeavingRaw.AddTarget(bathroom);
		hallwayLeavingRaw.AddTarget(guestroom);
		hallwayLeavingRaw.AddTarget(livingroom);
		shared_ptr<Transition> hallwayLeaving = make_shared<MultipleStatesTransition>(hallwayLeavingRaw);
		hallway->AddTransition(hallwayLeaving);

		MultipleStatesTransition guestroomLeavingRaw = MultipleStatesTransition();
		guestroomLeavingRaw.AddTarget(computerroom);
		shared_ptr<Transition> guestroomLeaving = make_shared<MultipleStatesTransition>(guestroomLeavingRaw);
		guestroom->AddTransition(guestroomLeaving);

		MultipleStatesTransition livingroomLeavingRaw = MultipleStatesTransition();
		livingroomLeavingRaw.AddTarget(kitchen);
		livingroomLeavingRaw.AddTarget(bedroom);
		livingroomLeavingRaw.AddTarget(frontroom);
		livingroomLeavingRaw.AddTarget(hallway);
		shared_ptr<Transition> livingroomLeaving = make_shared<MultipleStatesTransition>(livingroomLeavingRaw);
		livingroom->AddTransition(livingroomLeaving);

		MultipleStatesTransition frontroomLeavingRaw = MultipleStatesTransition();
		frontroomLeavingRaw.AddTarget(playroom);
		frontroomLeavingRaw.AddTarget(livingroom);
		shared_ptr<Transition> frontroomLeaving = make_shared<MultipleStatesTransition>(frontroomLeavingRaw);
		frontroom->AddTransition(frontroomLeaving);

		MultipleStatesTransition playroomLeavingRaw = MultipleStatesTransition();
		playroomLeavingRaw.AddTarget(kitchen);
		playroomLeavingRaw.AddTarget(frontroom);
		shared_ptr<Transition> playroomLeaving = make_shared<MultipleStatesTransition>(playroomLeavingRaw);
		playroom->AddTransition(playroomLeaving);

		MultipleStatesTransition kitchenLeavingRaw = MultipleStatesTransition();
		kitchenLeavingRaw.AddTarget(computerroom);
		kitchenLeavingRaw.AddTarget(bathroom);
		kitchenLeavingRaw.AddTarget(livingroom);
		shared_ptr<Transition> kitchenLeaving = make_shared<MultipleStatesTransition>(kitchenLeavingRaw);
		kitchen->AddTransition(kitchenLeaving);

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
		frontroom->AddTransition(victory);
		playroom->AddTransition(playroomToKitchen);
		playroom->AddTransition(playroomToHallway);
		kitchen->AddTransition(kitchenToComputerroom);

		vector<shared_ptr<State>> RoomStates = vector<shared_ptr<State>>();
		RoomStates.push_back(livingroom);
		RoomStates.push_back(playroom);
		RoomStates.push_back(frontroom);
		RoomStates.push_back(hallway);
		RoomStates.push_back(bathroom);
		RoomStates.push_back(computerroom);
		RoomStates.push_back(bedroom);
		RoomStates.push_back(kitchen);
		RoomStates.push_back(guestroom);
	
		currentState = bedroom;
		Blackboard::SetPlayerState(currentState);

		// movement commands
		shared_ptr<Condition> run = make_shared<CommandCondition>("run");
		shared_ptr<Condition> leave = make_shared<CommandCondition>("leave");
		shared_ptr<Condition> flee = make_shared<CommandCondition>("flee");

		shared_ptr<MultipleOrCondition> leaveCommands = make_shared<MultipleOrCondition>();
		leaveCommands->AddCondition(run);
		leaveCommands->AddCondition(leave);
		leaveCommands->AddCondition(flee);

		shared_ptr<Condition> leaveRoom = leaveCommands;

		// movement
		shared_ptr<Condition> north = make_shared<CommandCondition>("north");
		shared_ptr<Condition> south = make_shared<CommandCondition>("south");
		shared_ptr<Condition> east = make_shared<CommandCondition>("east");
		shared_ptr<Condition> west = make_shared<CommandCondition>("west");

		shared_ptr<Condition> up = make_shared<CommandCondition>("up");
		shared_ptr<Condition> down = make_shared<CommandCondition>("down");
		shared_ptr<Condition> right = make_shared<CommandCondition>("right");
		shared_ptr<Condition> left = make_shared<CommandCondition>("left");

		shared_ptr<Condition> moveNorth = make_shared<OrCondition>(north, up);
		shared_ptr<Condition> moveSouth = make_shared<OrCondition>(south, down);
		shared_ptr<Condition> moveEast = make_shared<OrCondition>(east, right);
		shared_ptr<Condition> moveWest = make_shared<OrCondition>(west, left);

		// dictionary (prints out all words that we can use. HashMap maps word -> definition (definitions hidden until you lose more letters)
		// win, lose, unlock, east, finish, leave, transcend, die, complete (finishes the game (only with key & in front room), but all have different text files. Neat right?)
		// remove, kill, delete + letter (resets monster to a random room (or the kitchen? maybe he just eats it) but you lose that letter. Shouldn't be a hard action to implement)
		// advanced actions would probably include obscure words to utilize for more fun situations (less popular letters too like b,z,x,y,g,h,j,q,r,u,v,w)

		shared_ptr<Condition> dictionary = make_shared<CommandCondition>("dictionary");

		//need to implement + letter
		shared_ptr<Condition> remove = make_shared<CommandCondition>("remove");
		shared_ptr<Condition> kill = make_shared<CommandCondition>("kill");
		shared_ptr<Condition> deleteWord = make_shared<CommandCondition>("delete");

		// looking around comments

		shared_ptr<Condition> look = make_shared<CommandCondition>("look");
		shared_ptr<Condition> discover = make_shared<CommandCondition>("discover");
		shared_ptr<Condition> notice = make_shared<CommandCondition>("notice");
		shared_ptr<Condition> search = make_shared<CommandCondition>("search");

		// pick up
		shared_ptr<Condition> find = make_shared<CommandCondition>("find");
		shared_ptr<Condition> pickup = make_shared<CommandCondition>("pickup");

		// win words

		shared_ptr<Condition> win = make_shared<CommandCondition>("win");
		//shared_ptr<Condition> lose = make_shared<CommandCondition>("lose");
		shared_ptr<Condition> finish = make_shared<CommandCondition>("finish");
		//shared_ptr<Condition> transcend = make_shared<CommandCondition>("transcend");
		shared_ptr<Condition> door = make_shared<CommandCondition>("door");
		//shared_ptr<Condition> die = make_shared<MonsterCondition>("die");
		//shared_ptr<Condition> quit = make_shared<MonsterCondition>("quit");
		shared_ptr<Condition> complete = make_shared<MonsterCondition>("complete");
		//Temp win con since I'm lazy. Probablt change this to passing in a set with the specific key words(?)
		shared_ptr<Condition> remember = make_shared<CommandCondition>("remember");

		shared_ptr<MultipleOrCondition> winWords = make_shared<MultipleOrCondition>();
		winWords->AddCondition(win);
		winWords->AddCondition(finish);
		winWords->AddCondition(door);
		winWords->AddCondition(complete);


		bedroomLeaving->SetCondition(leaveRoom);
		computerroomLeaving->SetCondition(leaveRoom);
		bathroomLeaving->SetCondition(leaveRoom);
		hallwayLeaving->SetCondition(leaveRoom);
		guestroomLeaving->SetCondition(leaveRoom);
		livingroomLeaving->SetCondition(leaveRoom);
		frontroomLeaving->SetCondition(leaveRoom);
		playroomLeaving->SetCondition(leaveRoom);
		kitchenLeaving->SetCondition(leaveRoom);

		bedroomToComputerroom->SetCondition(moveNorth);
		bedroomToBathroom->SetCondition(moveSouth);
		bedroomToLivingroom->SetCondition(moveEast);

		computerroomToBedroom->SetCondition(moveSouth);

		bathroomToHallway->SetCondition(moveEast);

		hallwayToBathroom->SetCondition(moveWest);
		hallwayToGuestroom->SetCondition(moveSouth);
		hallwayToLivingroom->SetCondition(moveNorth);

		guestroomToHallmay->SetCondition(moveNorth);
		victory->SetCondition(remember);

		livingroomToKitchen->SetCondition(moveNorth);
		livingroomToBedroom->SetCondition(moveWest);
		livingroomToHallway->SetCondition(moveSouth);
		livingroomToFrontroom->SetCondition(moveEast);

		//currently impossible.
		//livingroomToComputerroom->SetCondition();
		frontroomToLivingroom->SetCondition(moveWest);
		frontroomToPlayroom->SetCondition(moveNorth);

		victory->SetCondition(winWords);
		
		playroomToKitchen->SetCondition(moveWest);
		//definitely not south, different condition (secret)
		playroomToHallway->SetCondition(moveSouth);

		//this is forced.
		kitchenToComputerroom->SetCondition(moveWest);
	}

	shared_ptr<State> RoomsStateMachine::Update()
	{
		if (currentState != NULL)
		{
			shared_ptr<State> newState = currentState->Update();

			if (newState != NULL)
			{
				currentState->Exit();
				currentState = newState;
				currentState->Enter();
				Blackboard::SetPlayerState(currentState);
			}
		}
		return NULL;
	}
}
