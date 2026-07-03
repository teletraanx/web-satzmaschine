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