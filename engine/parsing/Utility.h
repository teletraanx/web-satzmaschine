#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <fstream> // for files
#include <sstream> // for files
#include "Pronoun.h"
#include "Verb.h"
#include "Noun.h"
#include "PersonNoun.h"
#include "Adjective.h"
#include "Adverb.h"
#include "StartNoun.h"
#include "NounStartingVerb.h"
#include <random>
using namespace std;

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