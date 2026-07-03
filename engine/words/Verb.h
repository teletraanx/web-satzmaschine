#pragma once
#include <iostream>
#include <vector>
#include "Pronoun.h"
#include "Noun.h"
using namespace std;

class Verb {
// verbs.txt: infinitive,ichForm,duForm,thirdSingularForm,wirForm,ihrForm,sieForm
public:
    string infinitive;
    string ichForm;
    string duForm;
    string thirdSingularForm;
    string wirForm;
    string ihrForm;
    string sieForm;
    vector<string> objectTags;
    // constructor
    Verb(string infinitive, 
        string ichForm,
        string duForm,
        string thirdSingularForm,
        string wirForm,
        string ihrForm,
        string sieForm,
        vector<string> objectTags
    );

    string conjugate(const Pronoun& subject) const;
    
    bool acceptsNoun(const Noun& noun) const;

    bool hasTag(const string& tag) const;
};