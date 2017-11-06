#pragma once
#include <unordered_set>

using namespace std;

namespace Forgotten
{
	class PlayerWords
	{
	public:
		PlayerWords();
		void LoseLetters(vector<char> letters);
		void LoseLetter(char letter);
		char RandomAvailableConsonant();
		bool AlreadyLostLetter(char letter);
		string ModifyString(string line);
		int r();

		// keyword: notes.  player owns the dictionary until the monster takes it away 
		//if the player is blind, maybe dictionary and map don't work anymore? @Monster (map tells you where to go)

	private:
		vector<char> consonants;
		unordered_set<char> lettersLost;
	};
}