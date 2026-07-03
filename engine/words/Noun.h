#pragma once
#include <string>
#include <vector>
using namespace std;

class Noun {
public:
	string gender;
	string noun;
	vector<string> tags;

	// constructor
	Noun(string gender, string noun, vector<string> tags);
};