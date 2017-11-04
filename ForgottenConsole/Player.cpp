#include "Player.h"

void Forgotten::Player::LoseLetters(vector<char> letters)
{
	for (char letter : letters)
		LoseLetter(letter);
}

void Forgotten::Player::LoseLetter(char letter)
{
	lettersLost.insert(letter);
}

bool Forgotten::Player::AlreadyLostLetter(char letter)
{
	return lettersLost.find(letter) != lettersLost.end();
}
