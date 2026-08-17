#pragma once

#include <vector>

#include "words/GeneratedSentence.h"
#include "words/Pronoun.h"
#include "words/Verb.h"
#include "words/Noun.h"
#include "words/PersonNoun.h"
#include "words/Adjective.h"
#include "words/Adverb.h"
#include "words/StartNoun.h"
#include "words/NounStartingVerb.h"
using namespace std;

class SatzmaschineEngine
{
private:
    // Level 1 word banks
    vector<Pronoun> levelOnePronouns;
    vector<Verb> levelOneVerbs;
    vector<Noun> levelOneNouns;
    vector<PersonNoun> levelOnePersonNouns;
    vector<Adjective> levelOneAdjectives;
    vector<Adverb> levelOneAdverbs;
    vector<StartNoun> levelOneStartNouns;
    vector<NounStartingVerb>
        levelOneNounStartingVerbs;

    // Level 2 word banks
    vector<Pronoun> levelTwoPronouns;
    vector<Verb> levelTwoVerbs;
    vector<Noun> levelTwoNouns;
    vector<PersonNoun> levelTwoPersonNouns;
    vector<Adjective> levelTwoAdjectives;
    vector<Adverb> levelTwoAdverbs;
    vector<StartNoun> levelTwoStartNouns;
    vector<NounStartingVerb>
        levelTwoNounStartingVerbs;

    GeneratedSentence
        generateLevelOneSentence() const;

    GeneratedSentence
        generateLevelTwoSentence() const;

public:
    SatzmaschineEngine();

    bool loadedSuccessfully() const;

    GeneratedSentence generateSentence(
        const vector<int>& selectedLevels
    ) const;
};