#pragma once
#include <string>

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
	private:
		static string currentCommand;
		static Blackboard::Turn currentTurn;


		Blackboard();
	};
}