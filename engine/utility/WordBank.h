#pragma once

#include <vector>

#include "../words/Pronoun.h"
#include "../words/Verb.h"
#include "../words/Noun.h"
#include "../words/Adjective.h"
#include "../words/Adverb.h"

struct WordBank
{
    vector<Pronoun> pronouns;
    vector<Verb> verbs;
    vector<Noun> nouns;
    vector<Adjective> adjectives;
    vector<Adverb> adverbs;
};