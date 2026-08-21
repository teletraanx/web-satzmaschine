#pragma once
#include "../words/Pronoun.h"
#include "../words/Noun.h"
#include "../words/Verb.h"
#include "../words/PersonNoun.h"
#include "../utility/Utility.h"
#include "../words/GeneratedSentence.h"
#include <random>
#include <sstream>
using namespace std;

template <typename T>
const T& getRandomItem(const vector<T>& items);

GeneratedSentence genPronounVerbNoun(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<Noun>& nouns);

string getArticle(const string& gender, const string& number);

string getKein(const string& gender, const string& verb);

vector<Noun> getTaggedNouns(const vector<string>& tags, const vector<Noun>& nouns);

/*
template <typename T>
const T& getRandomItem(const vector<T>& items);

vector<Noun> getValidNouns(const vector<Noun>& nouns, const Verb& verb);
vector<StartNoun> getValidStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb);
vector<StartNoun> getValidSecondStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb);
vector<Adjective> getValidAdjectives(const vector<Adjective>& adjectives, const StartNoun& noun);

GeneratedSentence genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun);
GeneratedSentence genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective);
GeneratedSentence genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective);
GeneratedSentence genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun);
GeneratedSentence genNounVerbNoun(const StartNoun& startNoun, const NounStartingVerb& verb, const StartNoun& secondNoun);
GeneratedSentence genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb);
GeneratedSentence genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb);

GeneratedSentence generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);
GeneratedSentence generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs);
GeneratedSentence generateKeinSentence();
GeneratedSentence generateNichtSentence();
GeneratedSentence generateEinOrKeinSentence();
GeneratedSentence generateYesNoQuestion();
//GeneratedSentence generateMeinOrDeinSentence();
*/