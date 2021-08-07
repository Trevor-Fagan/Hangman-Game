#include "Hangman.h"

Hangman::Hangman() : letters{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'} {
	// Init
	wrong_guesses = 0;

	string user_input = "";
	getWord();

	while (user_input != "exit") {
		printMenu();

		// Print the guessing word
		cout << "The word: ";
		for (int i = 0; i < placeHolderWord.size(); i++) {
			cout << placeHolderWord[i] << " ";
		}

		// Print letters
		cout << endl << "Letters remaining: " << endl;

		for (int i = 0; i < 26; i++) {
			cout << letters[i] << " ";
			if (i == 12) {
				cout << endl;
			}
		}

		cout << endl << endl << "Guess a letter: ";
		cin >> user_input;
		guessLetter(user_input[0]);
	}
}

void Hangman::printMenu() {
	string lineOne = " |";
	string lineTwo = " |";
	string lineThree = " |";
	string lineFour = " |";

	switch (wrong_guesses) {
	case 1:
		lineOne = " |				 0";
		break;
	case 2:
		lineTwo = " |				 |";
		break;
	case 3:
		lineTwo = " |				/|";
		break;
	case 4:
		lineTwo = " |				/|\\";
		break;
	case 5:
		lineThree = " |				/";
		break;
	case 6:
		lineThree = " |				/ \\";
		break;
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "==================" << endl;
	cout << " |               |" << endl;
	cout << lineOne << endl;
	cout << lineTwo << endl;
	cout << lineThree << endl;
	cout << lineFour << endl;
	cout << "========" << endl;

	/*
	==================
	 |               |
	 |				 0
	 |				/|\
	 |				/ \
	 |	
	 ========
	*/
}

void Hangman::guessLetter(char guess) {
	char final_guess = toupper(guess);

	// Updates list of letters with guess
	for (int i = 0; i < 26; i++) {
		if (letters[i] == final_guess) {
			letters[i] = '_';
		}
	}

	// Replace placeholder with correct letter
	bool letterFound = false;

	for (int i = 0; i < theWord.size(); i++) {
		if (toupper(theWord[i]) == final_guess) {
			placeHolderWord[i] = toupper(theWord[i]);
		}
	}

	if (!letterFound) {
		wrong_guesses++;
	}

	// Check if word was successfully found
	bool allTheSame = true;

	for (int i = 0; i < theWord.size(); i++) {
		if (theWord[i] != placeHolderWord[i]) {
			allTheSame = false;
		}
	}

	if (allTheSame) { // Restart the game
		cout << "Completed!" << endl;
	}
}

void Hangman::wrongGuess() {

}

void Hangman::getWord() {
	srand(time(NULL));
	int random_number = rand() % 200;
	string temp;
	int counter = 0;

	// Open input file
	ifstream inFile;
	inFile.open("words.txt");

	while (getline(inFile, temp)) {
		if (counter == random_number) {
			theWord = temp;
		}
		counter++;
	}

	placeHolderWord = theWord;
	for (int i = 0; i < theWord.size(); i++) {
		placeHolderWord[i] = '_';
	}
}