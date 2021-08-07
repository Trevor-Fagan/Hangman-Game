#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

class Hangman {
public:
	Hangman();
	void printMenu();
	void guessLetter(char guess);
	void wrongGuess();
	void getWord();

private:
	int wrong_guesses;
	char letters[26];
	string theWord;
	string placeHolderWord;
};