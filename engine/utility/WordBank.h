#pragma once

#include <vector>

#include "Pronoun.h"
#include "Verb.h"
#include "Noun.h"
#include "Adjective.h"
#include "Adverb.h"

struct WordBank
{
    vector<Pronoun> pronouns;
    vector<Verb> verbs;
    vector<Noun> nouns;
    vector<Adjective> adjectives;
    vector<Adverb> adverbs;
};