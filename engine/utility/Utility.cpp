#include "Utility.h"

string capitalizeFirst(const string& text) {
	string capitalizeFirst = text;
	capitalizeFirst[0] = toupper(capitalizeFirst[0]);
	return capitalizeFirst;
}

int rollDice(const int& chances) {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 
	uniform_int_distribution<> dist(0, (chances - 1)); // if you want only 0 or 1, chances should be 2
	return dist(gen);
}

/*
int coinFlip() {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 
	uniform_int_distribution<> dist(0, 1);
	return dist(gen);
}

int threeSideDice() {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 
	uniform_int_distribution<> dist(0, 2);
	return dist(gen);
}
*/

