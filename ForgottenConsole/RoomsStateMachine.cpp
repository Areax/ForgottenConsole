#include <memory>
#include "RoomState.h"
#include "RoomsStateMachine.h"

using namespace std;

namespace Forgotten
{
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
		/*
		shared_ptr<Transition> bedroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bedroomToBathroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bedroomToLivingroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> computerroomToBedroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bathroomToHallway = make_shared<Transition>(computerroom);
		shared_ptr<Transition> hallwayToBathroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> hallwayToGuestroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> hallwayToLivingroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> guestroomToHallmay = make_shared<Transition>(computerroom);
		shared_ptr<Transition> livingroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> livingroomToKitchen = make_shared<Transition>(computerroom);
		shared_ptr<Transition> livingroomToBedroom = make_shared<Transition>(bedroom);
		shared_ptr<Transition> livingroomToFrontroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> livingroomToHallway = make_shared<Transition>(computerroom);
		shared_ptr<Transition> frontroomToPlayroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> frontroomToLivingroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> playroomToKitchen = make_shared<Transition>(computerroom);
		shared_ptr<Transition> playroomToHallway = make_shared<Transition>(computerroom);
		shared_ptr<Transition> kitchenToComputerroom = make_shared<Transition>(computerroom);

		bedroom->AddTransition(bedroomToComputerroom);
		bedroom->AddTransition(bedroomToBathroom);
		bedroom->AddTransition(bedroomToLivingroom);
		computerroom->AddTransition(computerroomToBedroom);
		bathroom->AddTransition(bathroomToHallway); 
		hallway->AddTransition(hallwayToBathroom);
		hallway->AddTransition(hallwayToGuestroom);
		hallway->AddTransition(hallwayToLivingroom);
		guestroom->AddTransition(guestroomToHallmay);
		livingroom->AddTransition(livingroomToComputerroom);
		livingroom->AddTransition(livingroomToKitchen);
		livingroom->AddTransition(livingroomToBedroom);
		livingroom->AddTransition(livingroomToFrontroom);
		livingroom->AddTransition(livingroomToHallway);
		frontroom->AddTransition(frontroomToPlayroom);
		frontroom->AddTransition(frontroomToLivingroom);
		playroom->AddTransition(playroomToKitchen);
		playroom->AddTransition(playroomToHallway);
		kitchen->AddTransition(kitchenToComputerroom);

		vector<shared_ptr<State>> RoomStates = vector<shared_ptr<State>>();
		RoomStates.push_back(bedroom);
		RoomStates.push_back(bathroom);
		RoomStates.push_back(livingroom);
		RoomStates.push_back(kitchen);
		RoomStates.push_back(playroom);
		RoomStates.push_back(guestroom);
		RoomStates.push_back(frontroom);
		RoomStates.push_back(hallway);
		RoomStates.push_back(computerroom);*/
	

	}

	StateMachine& RoomsStateMachine::operator()(shared_ptr<State> state)
	{
		return (*this);
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
			}
		}
		return NULL;
	}
}
