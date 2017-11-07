#include <memory>
#include <stdlib.h>  
#include <time.h> 
#include <iostream>
#include "MonsterActionStateMachine.h"
#include "MonsterWanderAction.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "SameStateCondition.h"
#include "NotCondition.h"
#include "MonsterRoomState.h"
#include "MonsterCondition.h"
#include "MonsterAttackAction.h"
#include "Blackboard.h"

using namespace std;

namespace Forgotten
{

	MonsterActionStateMachine::MonsterActionStateMachine(shared_ptr<RoomsStateMachine> rms)
	{
		player = rms;
	}

	void MonsterActionStateMachine::Initialize()
	{
		shared_ptr<MonsterActionState> attack = make_shared<MonsterActionState>("attack");
		shared_ptr<MonsterActionState> wander = make_shared<MonsterActionState>("wander");

		shared_ptr<Transition> toAttack = make_shared<Transition>(attack);
		shared_ptr<Transition> toWander = make_shared<Transition>(wander);

		currentState = wander;

		shared_ptr<Condition> willAttack = make_shared<SameStateCondition>();
		shared_ptr<Condition> willWander = make_shared<NotCondition>(willAttack);

		toWander->SetCondition(willWander);
		toAttack->SetCondition(willAttack);

		shared_ptr<Action> attacking = make_shared<MonsterAttackAction>();
		shared_ptr<Action> wandering = make_shared<MonsterWanderAction>();

		attack->SetEnter(attacking);
		attack->SetTick(attacking);
		attack->AddTransition(toWander);

		wander->SetEnter(wandering);
		wander->SetTick(wandering);
		wander->AddTransition(toAttack);
		
	}

	shared_ptr<State> MonsterActionStateMachine::Update()
	{

		if (currentState != NULL)
		{
			Tick();

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

	void MonsterActionStateMachine::Tick()
	{
		
	}
}
