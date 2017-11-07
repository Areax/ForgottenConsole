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
	private:
		vector<char> consonants;
		unordered_set<char> lettersLost;
	};
}