#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <fstream> // for files
#include <sstream> // for files
#include "../words/Pronoun.h"
#include "../words/Verb.h"
#include "../words/Noun.h"
#include "../words/PersonNoun.h"
#include "../words/Adjective.h"
#include "../words/Adverb.h"
#include "../words/StartNoun.h"
#include "../words/NounStartingVerb.h"
#include <random>
using namespace std;

template <typename T> 
const T& getRandomItem(const vector<T>& items) {
	if (items.empty()) {
		throw runtime_error("ERROR: getRandomItem called with empty vector.");
	}

	static random_device rd;
	static mt19937 gen(rd());

	uniform_int_distribution<> dist(0, static_cast<int>(items.size()) - 1);
	return items[dist(gen)];
}

string trim(string text);

vector<string> splitTags(const string& text);

string capitalizeFirst(const string& text);

int coinFlip();

int threeSideDice();

vector<Pronoun> parsePronouns(string fileName);

vector<Verb> parseVerbs(string fileName);

vector<Noun> parseNouns(string fileName);

vector<PersonNoun> parsePersonNouns(string fileName);

vector<Adjective> parseAdjectives(string fileName);

vector<Adverb> parseAdverbs(string fileName);

vector<StartNoun> parseStartNouns(string fileName);

vector<NounStartingVerb> parseNounStartingVerbs(string fileName);