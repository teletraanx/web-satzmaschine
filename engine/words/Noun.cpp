#include "Noun.h"

Noun::Noun(string kind, string level, string english, string word, vector<string> categories, string nounGender, string neuterNoun, string masculineNoun, string feminineNoun, string pluralNoun)
	: kind(kind), level(level), english(english), word(word), categories(categories), nounGender(nounGender), neuterNoun(neuterNoun), masculineNoun(masculineNoun), feminineNoun(feminineNoun), pluralNoun(pluralNoun)
{
};