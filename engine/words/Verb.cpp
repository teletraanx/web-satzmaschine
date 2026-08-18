#include "Verb.h"

Verb::Verb(string kind,
    string level,
    string english,
    string word,
    vector<string> categories,
    string singularFirst,
    string singularSecond,
    string singularThird,
    string pluralVerb) 
    : kind(kind),
      level(level),
      english(english),
      word(word),
      categories(categories),
      singularFirst(singularFirst),
      singularSecond(singularSecond),
      singularThird(singularThird),
      pluralVerb(pluralVerb)
    {}; // constructor 

string Verb::conjugate(const Pronoun& subject) const {
    if (subject.person == "third" && subject.number == "singular") return singularThird;
    if (subject.person == "second" && subject.number == "singular") return singularSecond;
    if (subject.person == "first" && subject.number == "singular") return singularFirst;
    if (subject.number == "plural") return pluralVerb;

    return "ERROR";
}

bool Verb::acceptsNoun(const Noun& noun) const
{
    for (const string& verbTag : categories) {
        if (verbTag == "") {
            return false;
        }

        for (const string& nounTag : noun.categories) {
            if (verbTag == nounTag) {
                return true;
            }
        }
    }

    return false;
}

bool Verb::hasTag(const string& tag) const {
    for (const string& verbTag : categories) {
        if (verbTag == tag) { return true;  }
    }
    return false;
}