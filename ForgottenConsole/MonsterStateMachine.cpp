#include <memory>
#include "RoomState.h"
#include "MonsterStateMachine.h"
#include "RoomsStateMachine.h"
#include "Transition.h"

using namespace std;

namespace Forgotten
{
	MonsterStateMachine::MonsterStateMachine()
	{

	}

	void MonsterStateMachine::Initialize()
	{
		shared_ptr<RoomsStateMachine> roomsSM;

		shared_ptr<State> bedroom = make_shared<RoomState>("bedroom");
		shared_ptr<State> bathroom = make_shared<RoomState>("bathroom");
		shared_ptr<State> livingroom = make_shared<RoomState>("livingroom");
		shared_ptr<State> kitchen = make_shared<RoomState>("kitchen");
		shared_ptr<State> playroom = make_shared<RoomState>("playroom");
		shared_ptr<State> guestroom = make_shared<RoomState>("guestroom");
		shared_ptr<State> frontroom = make_shared<RoomState>("frontroom");
		shared_ptr<State> hallway = make_shared<RoomState>("hallway");
		shared_ptr<State> computerroom = make_shared<RoomState>("computerroom");

		shared_ptr<Transition> bedroomToComputerroom = make_shared<Transition>(computerroom);
		shared_ptr<Transition> bedroomToLivingroom = make_shared<Transition>(livingroom);

		bedroom->AddTransition(bedroomToComputerroom);
		bedroom->AddTransition(bedroomToLivingroom);

		//If they're in the same room, the player will lose a letter.




	}

	shared_ptr<State> MonsterStateMachine::Update()
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
