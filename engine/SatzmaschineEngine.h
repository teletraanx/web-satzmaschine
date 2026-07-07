#pragma once

#include <string>
#include <vector>

#include "words/Pronoun.h"
#include "words/Verb.h"
#include "words/Noun.h"
#include "words/PersonNoun.h"
#include "words/Adjective.h"
#include "words/Adverb.h"
#include "words/StartNoun.h"
#include "words/NounStartingVerb.h"
#include "words/GeneratedSentence.h"
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
    GeneratedSentence generateLevelOneSentence() const;
};