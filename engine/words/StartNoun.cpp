#include "StartNoun.h"
StartNoun::StartNoun(string masc, string fem, string plural, string otherGender, vector<string> firstTags, vector<string> secondTags)
	: masc(masc), fem(fem), plural(plural), otherGender(otherGender), firstTags(firstTags), secondTags(secondTags) {
}

bool StartNoun::acceptsAdjective(const Adjective& adjective) const
{
    for (const string& nounTag : secondTags) {
        if (nounTag == "none") {
            return false;
        }

        for (const string& adjectiveTag : adjective.tags) {
            if (nounTag == adjectiveTag) {
                return true;
            }
        }
    }

    return false;
}
