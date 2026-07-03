#pragma once
#include "../words/Pronoun.h"
#include "../words/Noun.h"
#include "../words/Verb.h"
#include "../words/PersonNoun.h"
#include "../parsing/Utility.h"
#include "../words/Adjective.h"
#include "../words/Adverb.h"
#include "../words/NounStartingVerb.h"
#include "../words/StartNoun.h"
#include <random>
using namespace std;

template <typename T>
const T& getRandomItem(const vector<T>& items);

vector<Noun> getValidNouns(const vector<Noun>& nouns, const Verb& verb);
vector<StartNoun> getValidStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb);
vector<StartNoun> getValidSecondStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb);
vector<Adjective> getValidAdjectives(const vector<Adjective>& adjectives, const StartNoun& noun);

string genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun);
string genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective);
string genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective);
string genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun);
string genNounVerbNoun(const StartNoun& startNoun, const NounStartingVerb& verb, const StartNoun& secondNoun);
string genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb);
string genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb);

string generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);
string generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);