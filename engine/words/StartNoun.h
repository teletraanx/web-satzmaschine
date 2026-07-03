#pragma once
#include <string>
#include <vector>
#include "Adjective.h"
using namespace std;

class StartNoun {
public: 
	string masc;
	string fem;
	string plural;
	string otherGender;
	vector<string> firstTags;
	vector<string> secondTags;

	StartNoun(string masc, string fem, string plural, string otherGender, vector<string> firstTags, vector<string> secondTags);

	bool acceptsAdjective(const Adjective& adjective) const;
};