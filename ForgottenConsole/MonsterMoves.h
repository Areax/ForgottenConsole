#pragma once
#include <string>

using namespace std;

namespace Forgotten
{
	class MonsterMoves
	{
	public:
		static void SetMove(string move);
		static string GetMove();
	private:
		static string currentMove;

		MonsterMoves();
	};
}