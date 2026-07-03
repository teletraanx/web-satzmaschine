#include "Sentence.h"

template <typename T> 
const T& getRandomItem(const vector<T>& items) {
	if (items.empty()) {
		throw runtime_error("ERROR: getRandomItem called with empty vector.");
	}

	static random_device rd;
	static mt19937 gen(rd());

	uniform_int_distribution<> dist(0, static_cast<int>(items.size()) - 1);
	return items[dist(gen)];
}

// Valid noun depends on verb's tags
vector<Noun> getValidNouns(const vector<Noun>& nouns, const Verb& verb) {
	vector<Noun> validNouns;
	for (const Noun& noun : nouns) {
		if (verb.acceptsNoun(noun)) {
			validNouns.push_back(noun);
		}
	}
	return validNouns;
}

vector<StartNoun> getValidStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb) {
	vector<StartNoun> validStartNouns;
	for (const StartNoun& noun : nouns) {
		if (verb.acceptsStartNoun(noun)) {
			validStartNouns.push_back(noun);
		}
	}
	return validStartNouns;
}

vector<StartNoun> getValidSecondStartNouns(const vector<StartNoun>& nouns, const NounStartingVerb& verb) {
	vector<StartNoun> validStartNouns;
	for (const StartNoun& noun : nouns) {
		if (verb.acceptsSecondStartNoun(noun)) {
			validStartNouns.push_back(noun);
		}
	}
	return validStartNouns;
}

// Valid adjective depends on startNoun's second tags
vector<Adjective> getValidAdjectives(const vector<Adjective>& adjectives, const StartNoun& noun) {
	vector<Adjective> validAdjectives;
	for (const Adjective& adjective : adjectives) {
		if (noun.acceptsAdjective(adjective)) {
			validAdjectives.push_back(adjective);
		}
	}
	return validAdjectives;
}

// A Simple Sentence can be:
// 0: Noun + Verb + Noun
// 1: Noun + Verb + Adverb
// 2: Pronoun + Verb + Noun
// 3: Pronoun + Verb + Adverb
// 4: Pronoun + Linking Verb + Adjective
// 5: Pronoun + Linking Verb + PersonNoun
// 6: Noun + Linking Verb + Adjective

// 5: Pronoun + Linking Verb + PersonNoun
string genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun) {
	// cout << "Pronoun + Linking Verb + PersonNoun" << endl; // DEBUG
	if (pronoun.number == "plural") {
		return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.plural + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
	}
	else if (pronoun.word == "sie") { // she/her
		return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.feminine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
	}
	else
		return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.masculine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;
}

// 4: Pronoun + Linking Verb + Adjective
string genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective) {
	//cout << "Pronoun + Linking Verb + Adjective" << endl; // DEBUG 
	// Pronoun will always use singular adjective at the end 
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adjective.singular << "." << endl;
	return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + adjective.singular + ".";
}

// 6: Noun + Linking Verb + Adjective
string genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective) {
	//cout << "Noun + Linking Verb + Adjective" << endl; // DEBUG 
	if (noun.otherGender != "neuter") {
		// flip for Masc, Fem, or Plural Noun
		switch (threeSideDice()) {
		case 0: // noun is masculine
		{
			//cout << "DEBUG: " << "flipped masculine" << endl;
			if (noun.otherGender == "feminine") { // if we flipped to use masculine, but the noun can't be, just use the plural form
				//cout << "but the noun is only feminine. Using plural instead." << endl; // DEBUG
				return "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
			}
			else {
				return "Der " + noun.masc + " " + verb.singular + " " + adjective.singular + ".";
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adjective.singular << "." << endl;
			}
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				return "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
			}
			else {
				return "Die " + noun.fem + " " + verb.singular + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adjective.singular << "." << endl;
			}
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			return "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
		}
		}
	}
	else { // for Wasser, can only use plural Das
		return "Das " + noun.plural + " " + verb.singular + " " + adjective.singular + ".";
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << adjective.singular << "." << endl;
	}
}

// 2: Pronoun + Verb + Noun
string genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun) {
	//cout << "Pronoun + Verb + Noun" << endl; // DEBUG 
	return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + noun.noun + ".";
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
}

// 0: Noun + Verb + Noun
string genNounVerbNoun(const StartNoun& noun, const NounStartingVerb& verb, const StartNoun& secondNoun) {
	//cout << "Noun + Verb + Noun" << endl; // DEBUG 
	if (noun.otherGender != "neuter") {
		// flip for Masc, Fem, or Plural Noun
		switch (threeSideDice()) {
		case 0: // noun is masculine
		{
			//cout << "DEBUG: " << "flipped masculine" << endl;
			if (noun.otherGender == "feminine") { // if we flipped to use masculine, but the noun can't be, just use the plural form
				//cout << "but the noun is only feminine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
				return "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
			}
			else {
				return "Der " + noun.masc + " " + verb.singular + " " + secondNoun.masc + ".";
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << secondNoun.masc << "." << endl;
			}
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
				return "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
			}
			else {
				return "Die " + noun.fem + " " + verb.singular + " " + secondNoun.masc + ".";
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << secondNoun.masc << "." << endl;
			}
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
			return "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
		}
		}
	}
	else { // for Wasser, can only use plural Das
		return "Das " + noun.plural + " " + verb.singular + " " + secondNoun.masc + ".";
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << secondNoun.masc << "." << endl;
	}
}

// 3: Pronoun + Verb + Adverb
string genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb) {
	//cout << "Pronoun + Verb + Adverb" << endl;// DEBUG
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
	return capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + adverb.adverb + ".";
}

// 1: Noun + Verb + Adverb
string genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb) {
	//cout << "Noun + Verb + Adverb" << endl;// DEBUG
	if (noun.otherGender != "neuter") {
		// flip for Masc, Fem, or Plural Noun
		switch (threeSideDice()) {
		case 0: // noun is masculine
		{
			//cout << "DEBUG: " << "flipped masculine" << endl;
			if (noun.otherGender == "feminine") { // if we flipped to use masculine, but the noun can't be, just use the plural form
				//cout << "but the noun is only feminine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
				return "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
			}
			else {
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adverb.adverb << "." << endl;
				return "Der " + noun.masc + " " + verb.singular + " " + adverb.adverb + ".";
			}
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
				return "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
			}
			else {
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adverb.adverb << "." << endl;
				return "Die " + noun.fem + " " + verb.singular + " " + adverb.adverb + ".";
			}
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
			return "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
		}
		}
	}
	else { // for Wasser, can only use plural Das
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << adverb.adverb << "." << endl;
		return "Das " + noun.plural + " " + verb.singular + " " + adverb.adverb + ".";
	}
}

string generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	Pronoun pronoun = getRandomItem(pronouns);
	Verb verb = getRandomItem(verbs);

	if (verb.hasTag("linking")) {
		switch (coinFlip()) {
		case 0: // use PersonNoun
		{
			// 5: Pronoun + Linking Verb + PersonNoun
			PersonNoun personNoun = getRandomItem(personNouns);
			return genPronounLVerbPNoun(pronoun, verb, personNoun);
		}
		case 1: // use Adjective
		{
			// 4: Pronoun + Linking Verb + Adjective
			Adjective adjective = getRandomItem(adjectives);
			if (!adjective.hasTag("person")) {
				//cout << "DEBUG: adjective, " << adjective.singular << " does not have person tag for verb: " << verb.infinitive << endl;
				//cout << "Generating new sentence..." << endl;
				return generatePronounSimpleSentence(pronouns,verbs,personNouns,nouns,adjectives,adverbs); // for pronouns, if the adjective can't go with a person, make a new sentence (mir introduced later)
			}
			else {
				return genPronounLVerbAdjective(pronoun, verb, adjective);
			}
		}
		default:
			return "ERROR";
		}
	}
	else { // non-linking verb chosen
		if (verb.hasTag("adverb"))
		{
			switch (coinFlip()) {
			case 0:// 2: Pronoun + Verb + Noun
			{
				vector<Noun> validNouns = getValidNouns(nouns, verb);
				if (validNouns.empty()) {
					Adverb adverb = getRandomItem(adverbs);
					return genPronounVerbAdverb(pronoun, verb, adverb);
				}
				else {
					Noun noun = getRandomItem(validNouns);
					return genPronounVerbNoun(pronoun, verb, noun);
				}
			}
			case 1:
			{
				// 3: Pronoun + Verb + Adverb
				Adverb adverb = getRandomItem(adverbs);
				return genPronounVerbAdverb(pronoun, verb, adverb);
			}
			default:
				return "ERROR";
			}
		}
		else {
			vector<Noun> validNouns = getValidNouns(nouns, verb);
			if (validNouns.empty()) {
				return "No valid nouns found for this verb: " + verb.conjugate(pronoun);
			}
			else {
				Noun noun = getRandomItem(validNouns);
				return genPronounVerbNoun(pronoun, verb, noun);
			}
		}
	}
	return "ERROR";
}

string generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
	NounStartingVerb verb = getRandomItem(verbs);
	
	if (verb.hasFirstTag("linking")) { // can only be Noun+LVerb+Adjective
		// if linking verb, use any start noun
		StartNoun startNoun = getRandomItem(nouns);
		// startNoun second tags must match adjective tags
		vector<Adjective> validAdjectives = getValidAdjectives(adjectives, startNoun);
		if (validAdjectives.empty()) {
			//cout << "No valid adjectives for: " << startNoun.masc << " " << verb.singular << endl;
			//cout << "Generating new sentence..." << endl;
			return generateNounSimpleSentence(nouns, verbs, adjectives, adverbs);
		}
		else {
			Adjective adjective = getRandomItem(validAdjectives);
			return genNounLVerbAdjective(startNoun, verb, adjective);
		}
	}
	else { // can be either Noun+Verb+Noun or Noun+Verb+Adverb
		// first tags of startNoun and verb must match to choose a valid startNoun
		vector<StartNoun> validNouns = getValidStartNouns(nouns, verb);

		if (validNouns.empty())
		{
			//cout << "No valid nouns for the verb: " << verb.singular << endl;
			//cout << "Generating new sentence..." << endl;
			return generateNounSimpleSentence(nouns, verbs, adjectives, adverbs);
		}
		else {

			StartNoun startNoun = getRandomItem(validNouns);

			switch (coinFlip()) {
			case 0: // Noun + Verb + Noun
			{
				// second tags of verb and second startNoun must match to be valid
				vector<StartNoun> validSecondStartNouns = getValidSecondStartNouns(nouns, verb);
				if (validSecondStartNouns.empty()) {
					//cout << "No valid ending noun for verb: " << verb.singular << endl;
					//cout << "Generating new sentence..." << endl;
					return generateNounSimpleSentence(nouns, verbs, adjectives, adverbs);
				}
				else {
					StartNoun secondStartNoun = getRandomItem(validSecondStartNouns);
					return genNounVerbNoun(startNoun, verb, secondStartNoun);
				}
			}
			case 1: // Noun + Verb + Adverb
			{
				if (verb.hasSecondTag("adverb")) {
					Adverb adverb = getRandomItem(adverbs);
					return genNounVerbAdverb(startNoun, verb, adverb);
				}
				else {
					//cout << "Verb: " << verb.singular << ", " << "does not fit with adverbs." << endl;
					//cout << "Generating new sentence..." << endl;
					return generateNounSimpleSentence(nouns, verbs, adjectives, adverbs);
				}
			}
			default: 
				return "ERROR";
			}
		}
	}
	return "ERROR";
}
