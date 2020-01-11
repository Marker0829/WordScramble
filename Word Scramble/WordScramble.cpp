/*
* Title  : Word Scramble
* File   : WordScramble.cpp
* Author : Mark Stone
* Date   : 9/24/19
* Info   : The implementation of the Word Scramble game.
*/

#include "WordScramble.h"
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

WordScramble::WordScramble(int gamemode) {
	wordInitialization();

	srand(time(NULL));

	cout << "Welcome to Word Scramble!" << endl;
	
	for (int i = 0; i < numberOfRounds; i++) {
		word = getWord();
		cout << "\nRound " << i + 1;
		cout << "\nYour word to unscramble is: " << scrambledWord << endl;
		scramble(word);

		while (!correct) {
			cin >> guessedWord;

			if (isCorrect(word, guessedWord)) {
				cout << "Correct!" << endl;
				correct = true;
			}
			else {
				cout << "Incorrect. Try again!" << endl;
			}
		}
		correct = false;
	}

}

void WordScramble::wordInitialization() {
	ifstream words("words.txt");
	string tempWord;
	numberOfRounds = 0;
	if (words.is_open()) {
		while (getline(words, tempWord)) {
			wordList.push_front(tempWord);
			numberOfRounds++;
		}
		words.close();
	}
	else
		cout << "Failed to open 'words.txt'\n";
}

string WordScramble::getWord() {
	string getWord;
	getWord = wordList.front();
	wordList.pop_front();
	return getWord;
}

string WordScramble::scramble(string word) {
	string scrambledWord;
	for (int i = 0; i < word.size(); i++)
		listOfNumbers[i] = i;

	int size = (word.size() * 4) / sizeof(listOfNumbers[0]);

	random_shuffle(listOfNumbers, listOfNumbers + size);
	for (int i = 0; i < size; ++i) {
		scrambledWord += word[listOfNumbers[i]];
	}
	cout << scrambledWord << endl;
	return scrambledWord;
}

bool WordScramble::isCorrect(string word, string guess) {
	if (word == guess) // add a toLower, to ensure the inputted answer is correct no matter what case is used
		return true;
	else
		return false;
}
