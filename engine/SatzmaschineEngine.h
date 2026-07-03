#pragma once

#include <string>
#include <vector>

#include "Pronoun.h"
#include "Verb.h"
#include "Noun.h"
#include "PersonNoun.h"
#include "Adjective.h"
#include "Adverb.h"
#include "StartNoun.h"
#include "NounStartingVerb.h"
using namespace std;

class SatzmaschineEngine {
private:
    vector<Pronoun> pronouns;
    vector<Verb> verbs;
    vector<Noun> nouns;
    vector<PersonNoun> personNouns;
    vector<Adjective> adjectives;
    vector<Adverb> adverbs;
    vector<StartNoun> startNouns;
    vector<NounStartingVerb> nounStartingVerbs;

public:
    SatzmaschineEngine();

    bool loadedSuccessfully() const;
    string generateLevelOneSentence() const;
};