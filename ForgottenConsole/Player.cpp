#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Player.h"

namespace Forgotten
{
	int NUM_LETTERS = 21;

	Player::Player()
	{
		consonants = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
	}

	void Player::LoseLetters(vector<char> letters)
	{
		for (char letter : letters)
			LoseLetter(letter);
	}

	void Player::LoseLetter(char letter)
	{
		consonants.erase(remove(consonants.begin(), consonants.end(), letter), consonants.end());
		if(lettersLost.find(letter) != lettersLost.end())
			lettersLost.insert(letter);
	}

	char Player::RandomAvailableConsonant()
	{
		return consonants[rand() % consonants.size()];
	}

	bool Player::AlreadyLostLetter(char letter)
	{
		return lettersLost.find(letter) != lettersLost.end();
	}
}