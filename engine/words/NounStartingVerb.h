#pragma once
#include <string>
#include <vector>
#include "StartNoun.h"
using namespace std;

class NounStartingVerb {
public:
	string singular;
	string plural;
	vector<string> firstTags;
	vector<string> secondTags;
	string english;

	NounStartingVerb(string singular, string plural, vector<string> firstTags, vector<string> secondTags, string english);

	bool hasFirstTag(const string& tag) const;
	bool hasSecondTag(const string& tag) const;


	bool acceptsStartNoun(const StartNoun& noun) const;
	bool acceptsSecondStartNoun(const StartNoun& noun) const;
};