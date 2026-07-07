#include "Adjective.h"

Adjective::Adjective(string singular, string plural, vector<string> tags, string english) : singular(singular), plural(plural), tags(tags), english(english) {};

bool Adjective::hasTag(const string& tag) const {
	for (const string& adjectiveTag : tags) {
		if (adjectiveTag == tag) { return true; }
	}
	return false;
}