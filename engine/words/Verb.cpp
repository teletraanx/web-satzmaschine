#include "Verb.h"

// verbs.txt: infinitive,ichForm,duForm,thirdSingularForm,wirForm,ihrForm,sieForm
Verb::Verb(string infinitive,
    string ichForm,
    string duForm,
    string thirdSingularForm,
    string wirForm,
    string ihrForm,
    string sieForm,
    vector<string> objectTags) 
    : infinitive(infinitive),
      ichForm(ichForm),
      duForm(duForm),
      thirdSingularForm(thirdSingularForm),
      wirForm(wirForm),
      ihrForm(ihrForm),
      sieForm(sieForm),
      objectTags(objectTags)
    {}; // constructor 

string Verb::conjugate(const Pronoun& subject) const {
    if (subject.person == "first" && subject.number == "singular") return ichForm;
    if (subject.person == "first" && subject.number == "plural") return wirForm;
    if (subject.person == "second" && subject.number == "singular") return duForm;
    if (subject.person == "second" && subject.number == "plural") return ihrForm;
    if (subject.person == "third" && subject.number == "singular") return thirdSingularForm;
    if (subject.person == "third" && subject.number == "plural") return sieForm;

    return infinitive;
}

bool Verb::acceptsNoun(const Noun& noun) const
{
    for (const string& verbTag : objectTags) {
        if (verbTag == "none") {
            return false;
        }

        for (const string& nounTag : noun.tags) {
            if (verbTag == nounTag) {
                return true;
            }
        }
    }

    return false;
}

bool Verb::hasTag(const string& tag) const {
    for (const string& verbTag : objectTags) {
        if (verbTag == tag) { return true;  }
    }
    return false;
}