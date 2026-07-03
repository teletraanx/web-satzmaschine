#pragma once
#include <iostream>
#include <vector>
using namespace std;

class PersonNoun {
public:
	string masculine;
	string feminine;
	string plural;
	vector<string> tags;

	PersonNoun(string m, string f, string p, vector<string> t);
};