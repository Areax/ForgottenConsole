#pragma once
#include "MonsterMoves.h"


namespace Forgotten
{
	string MonsterMoves::currentMove = "";

	MonsterMoves::MonsterMoves()
	{
	}
	
	void MonsterMoves::SetMove(string move)
	{
		currentMove = move;
	}

	string MonsterMoves::GetMove()
	{
		return currentMove;
	}
}