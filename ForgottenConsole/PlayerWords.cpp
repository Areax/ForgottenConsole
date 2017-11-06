#include <vector>
#include <algorithm>
#include <cstdlib>
#include "PlayerWords.h"

#include <iostream>

namespace Forgotten
{
	int NUM_LETTERS = 21;

	PlayerWords::PlayerWords()
	{
		lettersLost = unordered_set<char>();
		consonants = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
	}

	void PlayerWords::LoseLetters(vector<char> letters)
	{
		for (char letter : letters)
			LoseLetter(letter);
	}

	void PlayerWords::LoseLetter(char letter)
	{
		if (letter != NULL)
		{
			consonants.erase(remove(consonants.begin(), consonants.end(), letter), consonants.end());
			if (lettersLost.find(letter) == lettersLost.end())
				lettersLost.insert(letter);
		}
	}

	char PlayerWords::RandomAvailableConsonant()
	{
		if(consonants.size() > 0)
			return consonants[rand() % consonants.size()];
		return NULL;
	}

	bool PlayerWords::AlreadyLostLetter(char letter)
	{
		return lettersLost.find(letter) != lettersLost.end();
	}

	string PlayerWords::ModifyString(string line)
	{
		for (const auto& c : lettersLost)
		{
			replace(line.begin(), line.end(), c, '_');
		}
		return line;
	}
}