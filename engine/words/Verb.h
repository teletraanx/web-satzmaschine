#pragma once
#include <iostream>
#include <vector>
#include "Pronoun.h"
#include "Noun.h"
using namespace std;

class Verb {
public:
    string kind;
    int level;
    string english;
    string word;
    vector<string> categories;
    string singularFirst;
    string singularSecond;
    string singularThird;
    string pluralVerb;
    // constructor
    Verb(string kind, int level, string english, string word, vector<string> categories, string singularFirst, string singularSecond, string singularThird, string pluralVerb);

    string conjugate(const Pronoun& subject) const;
    
    bool acceptsNoun(const Noun& noun) const;

    bool hasTag(const string& tag) const;
};