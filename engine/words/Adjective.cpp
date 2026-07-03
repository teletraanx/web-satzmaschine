#include "Adjective.h"

Adjective::Adjective(string singular, string plural, vector<string> tags) : singular(singular), plural(plural), tags(tags) {};

bool Adjective::hasTag(const string& tag) const {
	for (const string& adjectiveTag : tags) {
		if (adjectiveTag == tag) { return true; }
	}
	return false;
}