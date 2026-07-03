#pragma once
#include <string>
#include <vector>
using namespace std;

class Adjective {
public:
	string singular;
	string plural;
	vector<string> tags;

	Adjective(string singular, string plural, vector<string> tags);

	bool hasTag(const string& tag) const;
};