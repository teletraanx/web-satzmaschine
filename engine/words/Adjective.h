#pragma once
#include <string>
#include <vector>
using namespace std;

class Adjective {
public:
	string singular;
	string plural;
	vector<string> tags;
	string english;

	Adjective(string singular, string plural, vector<string> tags, string english);

	bool hasTag(const string& tag) const;
};