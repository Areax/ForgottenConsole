#pragma once
#include <memory>
#include <string>
#include "PlayerWords.h"

using namespace std;

namespace Forgotten
{
	class State;

	class Blackboard
	{
	public:
		static void SetCommand(string command);
		static string GetCommand();
		static void SetMonsterState(shared_ptr<State> state);
		static shared_ptr<State> GetMonsterState();
		static void SetPlayerState(shared_ptr<State> state);
		static shared_ptr<State> GetPlayerState();
		static shared_ptr<PlayerWords> GetPlayer();
	private:
		static string currentCommand;
		static shared_ptr<State> monsterState;
		static shared_ptr<State> playerState;
		static shared_ptr<PlayerWords> player;


		Blackboard();
	};
}