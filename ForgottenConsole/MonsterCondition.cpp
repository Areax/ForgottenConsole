#pragma once
#include <string>
#include "MonsterCondition.h"
#include "MonsterMoves.h"
#include <iostream>

using namespace std;

namespace Forgotten
{
	MonsterCondition::MonsterCondition(string move)
	{
		mMove = move;
	}

	bool MonsterCondition::operator()()
	{
		return mMove == MonsterMoves::GetMove();
	};
}