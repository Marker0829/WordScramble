#pragma once

/*
* Title  : Word Scramble
* File   : WordScramble.h
* Author : Mark Stone
* Date   : 9/24/19
* Info   : The declaration of the Word Scramble game.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

const int NUMBER_OF_WORDS = 10;
const int NUM_LIMIT = 100;

class WordScramble {
public:
	WordScramble(int gamemode);
	void wordInitialization();
	string getWord();
	string scramble(string word);
	bool isCorrect(string word, string guess);

private:
	int numberOfTries = 0;
	string word;
	string scrambledWord;
	string guessedWord;
	int randomNumber;
	int index = 0;
	int listOfNumbers[NUM_LIMIT];

	bool correct = false;

	int numberOfRounds;
	
	list<string> wordList;
};