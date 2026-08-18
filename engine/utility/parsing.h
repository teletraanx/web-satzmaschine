#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <fstream> // for files
#include <sstream> // for files
#include "../utility/WordBank.h"
#include "../words/Pronoun.h"
#include "../words/Verb.h"
#include "../words/Noun.h"
#include "../words/Adjective.h"
#include "../words/Adverb.h"

using namespace std;

WordBank parseWords(const string& fileName);
vector<string> splitTags(const string& text);
string trim(string text);


