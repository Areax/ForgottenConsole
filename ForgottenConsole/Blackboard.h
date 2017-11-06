#pragma once
#include <memory>
#include <string>
#include "State.h"
#include "PlayerWords.h"

using namespace std;

namespace Forgotten
{
	class Blackboard
	{
	public:
		enum Turn { Player, Monster };

		static void SetCommand(string command);
		static string GetCommand();
		static void SetTurn(Turn turn);
		static Turn GetTurn();
		static shared_ptr<PlayerWords> GetPlayer();
	private:
		static string currentCommand;
		static Blackboard::Turn currentTurn;
		static shared_ptr<PlayerWords> player;


		Blackboard();
	};
}