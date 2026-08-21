#pragma once
#include <string>
#include <vector>
using namespace std;

class Noun {
public:
	string kind;
	int level;
	string english;
	string word;
	vector<string> categories;
	string nounGender;
	string neuterNoun;
	string masculineNoun;
	string feminineNoun;
	string pluralNoun;

	// constructor
	Noun(string kind, int level, string english, string word, vector<string> categories, string nounGender, string neuterNoun, string masculineNoun, string feminineNoun, string pluralNoun);
};