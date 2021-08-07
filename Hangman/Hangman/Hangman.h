#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;

class Hangman {
public:
	Hangman();
	void printMenu();
	void guessLetter(char guess);
	void getWord();
	void gameOver();

private:
	int wrong_guesses;
	char letters[26];
	string theWord;
	string placeHolderWord;
	string user_input;
};