#include "NounStartingVerb.h"

NounStartingVerb::NounStartingVerb(string singular, string plural, vector<string> firstTags, vector<string> secondTags)
	: singular(singular), plural(plural), firstTags(firstTags), secondTags(secondTags) {
}

bool NounStartingVerb::hasFirstTag(const string& tag) const {
	for (const string& verbTag : firstTags) {
		if (verbTag == tag) { return true; }
	}
	return false;
}

bool NounStartingVerb::hasSecondTag(const string& tag) const {
    for (const string& verbTag : secondTags) {
        if (verbTag == tag) { return true; }
    }
    return false;
}

bool NounStartingVerb::acceptsStartNoun(const StartNoun& noun) const
{
    for (const string& verbTag : firstTags) {
        if (verbTag == "none") {
            return false;
        }

        for (const string& nounTag : noun.firstTags) {
            if (verbTag == nounTag) {
                return true;
            }
        }
    }

    return false;
}

bool NounStartingVerb::acceptsSecondStartNoun(const StartNoun& noun) const
{
    for (const string& verbTag : secondTags) {
        if (verbTag == "none") {
            return false;
        }

        for (const string& nounTag : noun.secondTags) {
            if (verbTag == nounTag) {
                return true;
            }
        }
    }

    return false;
}

