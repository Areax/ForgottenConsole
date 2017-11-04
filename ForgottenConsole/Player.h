#pragma once
#include <unordered_set>

using namespace std;

namespace Forgotten
{
	class Player
	{
		void LoseLetters(vector<char> letters);
		void LoseLetter(char letter);
		bool AlreadyLostLetter(char letter);

		//player owns the dictionary until the monster takes it away 
		//if the player is blind, maybe dictionary and map don't work anymore? @Monster (map tells you where to go)

	private:
		unordered_set<char> lettersLost;
	};
}