#include <memory>
#include "PlayingSM.h"
#include "Transition.h"
#include "CommandCondition.h"
#include "FinishedGameCondition.h"
#include "Blackboard.h"
#include "MonsterMoves.h"
#include "InGameState.h"
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
		monsterSM = make_shared<MonsterStateMachine>(playerSM);

		//probably need to pass player and monster into the game state. Have that update everything.
		//because gameOver state should not know about all of this <^>v
		//and then gameOver should probably stop asking for commands
		//so the CIN / COMMAND stuff in forgottonconsole
		//should instead be in the state where you ask for the commands constantly.
		playerSM->Initialize();
		monsterSM->Initialize();

		shared_ptr<State> playing = make_shared<InGameState>("ingame");
		shared_ptr<State> gameOver = make_shared<InGameState>("gameOver");
		shared_ptr<Transition> playToGameOver = make_shared<Transition>(gameOver);
		shared_ptr<Condition> losingCondition = make_shared<FinishedGameCondition>();

		playToGameOver->SetCondition(losingCondition);
		playing->AddTransition(playToGameOver);


		gameState = playing;

	}

	// keyword: states !!! where are the states lol
	// why do we need whoseTurn?

	shared_ptr<State> PlayingSM::Update()
	{
		playerSM->Update();
		monsterSM->Update();
		
		if (gameState != NULL)
		{
			shared_ptr<State> newState = gameState->Update();

			if (newState != NULL)
			{
				gameState->Exit();
				gameState = newState;
				gameState->Enter();
			}
		}
		return NULL;
	}
}
