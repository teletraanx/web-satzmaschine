#include "Sentence.h"

// Present Tense Pronoun + Verb + Noun (including negation)
GeneratedSentence genPronounVerbNoun(
    const vector<Pronoun>& pronouns,
    const vector<Verb>& verbs,
    const vector<Noun>& nouns
) {
    GeneratedSentence result;

    Pronoun pronoun = getRandomItem(pronouns);
    Verb verb = getRandomItem(verbs);

    bool negated = rollDice(2) == 0;

    vector<Noun> validNouns;

    if (verb.kind == "linking verb") {
        validNouns =
            getTaggedNouns({"profession"}, nouns);
    }
    else {
        validNouns =
            getTaggedNouns(verb.categories, nouns);
    }

    if (validNouns.empty()) {
        return {
            "ERROR: No valid nouns.",
            {}
        };
    }

    Noun noun = getRandomItem(validNouns);

    string nounWord;
    string determiner;

    if (verb.kind == "linking verb") {

        if (pronoun.number == "plural") {
            nounWord = noun.pluralNoun;

            if (negated) {
                determiner = "keine ";
            }
        }
        else if (pronoun.word == "sie") {
            nounWord = noun.feminineNoun;

            if (negated) {
                determiner = "keine ";
            }
        }
        else if (pronoun.word == "er") {
            nounWord = noun.masculineNoun;

            if (negated) {
                determiner = "kein ";
            }
        }
        else {
            if (rollDice(2) == 0) {
                nounWord = noun.masculineNoun;

                if (negated) {
                    determiner = "kein ";
                }
            }
            else {
                nounWord = noun.feminineNoun;

                if (negated) {
                    determiner = "keine ";
                }
            }
        }
    }
    else {
        nounWord = noun.word;

        if (negated) {
            determiner =
                getKein(noun.nounGender, "");
        }
    }

    result.sentence =
        capitalizeFirst(pronoun.word)
        + " "
        + verb.conjugate(pronoun)
        + " "
        + determiner
        + nounWord
        + ".";

    result.words.push_back({
        pronoun.word,
        pronoun.english
    });

    result.words.push_back({
        verb.conjugate(pronoun),
        verb.english
    });

    result.words.push_back({
        nounWord,
        noun.english
    });

    return result;
}
/*
GeneratedSentence genPronounVerbNoun(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<Noun>& nouns) {
	int roll;
	int negationRoll = rollDice(2);
	GeneratedSentence result;

	Pronoun pronoun = getRandomItem(pronouns);
	Verb verb = getRandomItem(verbs);
	Noun noun;

	vector<Noun> validNouns;
	string genderedNoun = "";
	string determiner;

	if (verb.kind == "linking verb") {
		validNouns = getTaggedNouns("profession", nouns);
		noun = getRandomItem(validNouns);
		// get actual noun word depends on pronoun.number here
		if (pronoun.number == "singular") {
			if (pronoun.person == "third") {
				if (pronoun.word == "er") {
					// for he, use masculine noun
					genderedNoun = noun.masculineNoun;
					
					if (negationRoll == 0) { // negation
						determiner = getKein("masculine", "sein");
					}
				}
				else {
					// for she, use feminine noun
					genderedNoun = noun.feminineNoun;
					
					if (negationRoll == 0) { // negation
						determiner = getKein("feminine", "sein");
					}
				}
			}
			else {
				// I, you (use either masculine or feminine noun)
				roll = rollDice(2);
				if (roll == 0) {
					genderedNoun = noun.masculineNoun;
					
					if (negationRoll == 0) { // negation
						determiner = getKein("masculine", "sein");
					}
				}
				else {
					genderedNoun = noun.feminineNoun;
					
					if (negationRoll == 0) { // negation
						determiner = getKein("feminine", "sein");
					}
				}
			}
		}
		else {
			// for they or we, use plural noun
			genderedNoun = noun.pluralNoun;
			
			if (negationRoll == 0) { // negation
				determiner = getKein("plural", "sein");
			}
		}
	}
	else {
		validNouns = getTaggedNouns(verb.categories, nouns);
		noun = getRandomItem(validNouns);
		// get actual noun word (gender) (for now, is only food and drink, should just be noun.word)
		genderedNoun = noun.word;
		// won't need article for now ('I do not have coffee/water/bread'), but later, such as for 'a sandwich', you'll need one
		if (negationRoll == 0) { // negation
			determiner = getKein(noun.nounGender, "");
		}
	}
	result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + determiner + genderedNoun;
	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({  verb.word, verb.english });
	result.words.push_back({ noun.word, noun.english });
	return result;

	/*
GeneratedSentence genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun) {
	GeneratedSentence result;

	// cout << "Pronoun + Linking Verb + PersonNoun" << endl; // DEBUG
	if (pronoun.number == "plural") {
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.plural + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
		result.words.push_back({ personNoun.plural, personNoun.english });
	}
	else if (pronoun.word == "sie") { // she/her
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.feminine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
		result.words.push_back({ personNoun.feminine, personNoun.english });
	}
	else {
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.masculine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;
		result.words.push_back({ personNoun.masculine, personNoun.english });
	}

	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({ verb.conjugate(pronoun), verb.english });
	return result;
}
	*/
//}

string getArticle(const string& gender, const string& number) {
	int roll = rollDice(4); // roll for A, my, your, or The 
	if (gender == "masculine" && number == "singular") {
		if (roll == 0) {
			return "der ";
		}
		else if (roll == 1) {
			return "ein ";
		}
		else if (roll == 2) {
			return "meinen ";
		}
		else {
			return "deinen ";
		}
	}
	else if (gender == "feminine" && number == "singular") {
		if (roll == 0) {
			return "die ";
		}
		else if (roll == 1) {
			return "eine ";
		}
		else if (roll == 2) {
			return "meine ";
		}
		else {
			return "deine ";
		}
	}
	else if (number == "plural") {
		if (roll == 0) {
			return "deine "; // your
		}
		else if (roll == 1) {
			return "meine "; // my
		}
		else { // more chance for just "the" (since there is no plural "A")
			return "die "; // the
		}
	}
	else {// gender == neuter, number doesn't matter
		if (roll == 0) {
			return "mein ";
		}
		else if (roll == 1) {
			return "dein ";
		}
		else {
			return "das ";
		}
	}
	return "ERROR";
}

string getKein(const string& gender, const string& verb) {
	// this method also takes "plural" as a gender: plural or fem will always be keine
	if (gender == "plural" || gender == "feminine") {
		return "keine";
	}
	else if (verb == "sein") {
		if (gender == "masculine") {
			return "kein ";
		}
		else { // gender == neuter
			return "kein ";
		}
	}
	else {
		if (gender == "masculine") {
			return "keinen ";
		}
		else { // gender == neuter
			return "kein ";
		}
	}
	return "ERROR ";
}

vector<Noun> getTaggedNouns(
    const vector<string>& tags,
    const vector<Noun>& nouns
) {
    vector<Noun> taggedNouns;

    for (const Noun& noun : nouns) {
        bool matches = false;

        for (const string& nounTag : noun.categories) {
            for (const string& wantedTag : tags) {
                if (nounTag == wantedTag) {
                    matches = true;
                    break;
                }
            }

            if (matches) {
                break;
            }
        }

        if (matches) {
            taggedNouns.push_back(noun);
        }
    }

    return taggedNouns;
}


/*
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
GeneratedSentence genPronounLVerbPNoun(const Pronoun& pronoun, const Verb& verb, const PersonNoun& personNoun) {
	GeneratedSentence result;

	// cout << "Pronoun + Linking Verb + PersonNoun" << endl; // DEBUG
	if (pronoun.number == "plural") {
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.plural + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.plural << "." << endl;
		result.words.push_back({ personNoun.plural, personNoun.english });
	}
	else if (pronoun.word == "sie") { // she/her
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.feminine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.feminine << "." << endl;
		result.words.push_back({ personNoun.feminine, personNoun.english });
	}
	else {
		result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + personNoun.masculine + ".";
		//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << personNoun.masculine << "." << endl;
		result.words.push_back({ personNoun.masculine, personNoun.english });
	}

	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({ verb.conjugate(pronoun), verb.english });
	return result;
}

// 4: Pronoun + Linking Verb + Adjective
GeneratedSentence genPronounLVerbAdjective(const Pronoun& pronoun, const Verb& verb, const Adjective& adjective) {
	GeneratedSentence result;
	//cout << "Pronoun + Linking Verb + Adjective" << endl; // DEBUG 
	// Pronoun will always use singular adjective at the end 
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adjective.singular << "." << endl;
	result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + adjective.singular + ".";
	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({ verb.conjugate(pronoun), verb.english });
	result.words.push_back({ adjective.singular, adjective.english });
	return result;
}

// 6: Noun + Linking Verb + Adjective
GeneratedSentence genNounLVerbAdjective(const StartNoun& noun, const NounStartingVerb& verb, const Adjective& adjective) {
	GeneratedSentence result;
	//cout << "Noun + Linking Verb + Adjective" << endl; // DEBUG 
	if (noun.otherGender != "neuter") {
		// flip for Masc, Fem, or Plural Noun
		switch (threeSideDice()) {
		case 0: // noun is masculine
		{
			//cout << "DEBUG: " << "flipped masculine" << endl;
			if (noun.otherGender == "feminine") { // if we flipped to use masculine, but the noun can't be, just use the plural form
				//cout << "but the noun is only feminine. Using plural instead." << endl; // DEBUG
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ adjective.singular, adjective.english });				
			}
			else {
				result.sentence = "Der " + noun.masc + " " + verb.singular + " " + adjective.singular + ".";
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adjective.singular << "." << endl;
				result.words.push_back({ noun.masc, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ adjective.singular, adjective.english });					
			}
			return result;
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ adjective.singular, adjective.english });			
			}
			else {
				result.sentence = "Die " + noun.fem + " " + verb.singular + " " + adjective.singular + ".";
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adjective.singular << "." << endl;
				result.words.push_back({ noun.fem, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ adjective.singular, adjective.english });			
			}
			return result;
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adjective.singular + ".";
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adjective.singular << "." << endl;
			result.words.push_back({ noun.plural, noun.english });
			result.words.push_back({ verb.plural, verb.english });
			result.words.push_back({ adjective.singular, adjective.english });		
			return result;	
		}
		}
	}
	else { // for Wasser, can only use plural Das
		result.sentence = "Das " + noun.plural + " " + verb.singular + " " + adjective.singular + ".";
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << adjective.singular << "." << endl;
		result.words.push_back({ noun.plural, noun.english });
		result.words.push_back({ verb.singular, verb.english });
		result.words.push_back({ adjective.singular, adjective.english });		
		return result;	
	}
}

// 2: Pronoun + Verb + Noun
GeneratedSentence genPronounVerbNoun(const Pronoun& pronoun, const Verb& verb, const Noun& noun) {
	GeneratedSentence result;
	//cout << "Pronoun + Verb + Noun" << endl; // DEBUG 
	result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + noun.noun + ".";
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << noun.noun << "." << endl;
	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({ verb.conjugate(pronoun), verb.english });
	result.words.push_back({ noun.noun, noun.english });		
	return result;
}

// 0: Noun + Verb + Noun
GeneratedSentence genNounVerbNoun(const StartNoun& noun, const NounStartingVerb& verb, const StartNoun& secondNoun) {
	GeneratedSentence result;
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
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ secondNoun.masc, secondNoun.english });	
			}
			else {
				result.sentence = "Der " + noun.masc + " " + verb.singular + " " + secondNoun.masc + ".";
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << secondNoun.masc << "." << endl;
				result.words.push_back({ noun.masc, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ secondNoun.masc, secondNoun.english });			
			}
			return result;
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ secondNoun.masc, secondNoun.english });
			}
			else {
				result.sentence = "Die " + noun.fem + " " + verb.singular + " " + secondNoun.masc + ".";
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << secondNoun.masc << "." << endl;
				result.words.push_back({ noun.fem, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ secondNoun.masc, secondNoun.english });			
			}
			return result;
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << secondNoun.masc << "." << endl;
			result.sentence = "Die " + noun.plural + " " + verb.plural + " " + secondNoun.masc + ".";
			result.words.push_back({ noun.plural, noun.english });
			result.words.push_back({ verb.plural, verb.english });
			result.words.push_back({ secondNoun.masc, secondNoun.english });
			return result;
		}
		}
	}
	else { // for Wasser, can only use plural Das
		result.sentence = "Das " + noun.plural + " " + verb.singular + " " + secondNoun.masc + ".";
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << secondNoun.masc << "." << endl;
		result.words.push_back({ noun.plural, noun.english });
		result.words.push_back({ verb.singular, verb.english });
		result.words.push_back({ secondNoun.masc, secondNoun.english });
		return result;
	}
}

// 3: Pronoun + Verb + Adverb
GeneratedSentence genPronounVerbAdverb(const Pronoun& pronoun, const Verb& verb, const Adverb& adverb) {
	GeneratedSentence result;
	//cout << "Pronoun + Verb + Adverb" << endl;// DEBUG
	//cout << capitalizeFirst(pronoun.word) << " " << verb.conjugate(pronoun) << " " << adverb.adverb << "." << endl;
	result.sentence = capitalizeFirst(pronoun.word) + " " + verb.conjugate(pronoun) + " " + adverb.adverb + ".";
	result.words.push_back({ pronoun.word, pronoun.english });
	result.words.push_back({ verb.conjugate(pronoun), verb.english });
	result.words.push_back({ adverb.adverb, adverb.english });
	return result;
}

// 1: Noun + Verb + Adverb
GeneratedSentence genNounVerbAdverb(const StartNoun& noun, const NounStartingVerb& verb, const Adverb& adverb) {
	GeneratedSentence result;
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
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ adverb.adverb, adverb.english });
			}
			else {
				//cout << "Der" << " " << noun.masc << " " << verb.singular << " " << adverb.adverb << "." << endl;
				result.sentence = "Der " + noun.masc + " " + verb.singular + " " + adverb.adverb + ".";
				result.words.push_back({ noun.masc, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ adverb.adverb, adverb.english });
			}
			return result;
		}
		case 1: // noun is feminine
		{
			//cout << "DEBUG: " << "flipped feminine" << endl;
			if (noun.otherGender == "masculine") { // if we flipped fem, but the noun can't be, just use plural
				//cout << "but the noun is only masculine. Using plural instead." << endl; // DEBUG
				//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
				result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
				result.words.push_back({ noun.plural, noun.english });
				result.words.push_back({ verb.plural, verb.english });
				result.words.push_back({ adverb.adverb, adverb.english });
			}
			else {
				//cout << "Die" << " " << noun.fem << " " << verb.singular << " " << adverb.adverb << "." << endl;
				result.sentence = "Die " + noun.fem + " " + verb.singular + " " + adverb.adverb + ".";
				result.words.push_back({ noun.fem, noun.english });
				result.words.push_back({ verb.singular, verb.english });
				result.words.push_back({ adverb.adverb, adverb.english });
			}
			return result;
		}
		case 2: // noun is plural
		{
			//cout << "DEBUG: " << "flipped plural" << endl;
			//cout << "Die" << " " << noun.plural << " " << verb.plural << " " << adverb.adverb << "." << endl;
			result.sentence = "Die " + noun.plural + " " + verb.plural + " " + adverb.adverb + ".";
			result.words.push_back({ noun.plural, noun.english });
			result.words.push_back({ verb.plural, verb.english });
			result.words.push_back({ adverb.adverb, adverb.english });
			return result;
		}
		}
	}
	else { // for Wasser, can only use plural Das
		//cout << "Das" << " " << noun.plural << " " << verb.singular << " " << adverb.adverb << "." << endl;
		result.sentence = "Das " + noun.plural + " " + verb.singular + " " + adverb.adverb + ".";
		result.words.push_back({ noun.plural, noun.english });
		result.words.push_back({ verb.singular, verb.english });
		result.words.push_back({ adverb.adverb, adverb.english });
		return result;
	}
}

GeneratedSentence generatePronounSimpleSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<PersonNoun>& personNouns, const vector<Noun>& nouns, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
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
			}
		}
		else {
			vector<Noun> validNouns = getValidNouns(nouns, verb);
			if (validNouns.empty()) {
				return generatePronounSimpleSentence(pronouns,verbs,personNouns,nouns,adjectives,adverbs);
			}
			else {
				Noun noun = getRandomItem(validNouns);
				return genPronounVerbNoun(pronoun, verb, noun);
			}
		}
	}
}

GeneratedSentence generateNounSimpleSentence(const vector<StartNoun>& nouns, const vector<NounStartingVerb>& verbs, const vector<Adjective>& adjectives, const vector<Adverb>& adverbs) {
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
			}
		}
	}
}

GeneratedSentence generateNichtSentence() {
	//
}
GeneratedSentence generateEinOrKeinSentence(const vector<Pronoun>& pronouns, const vector<Verb>& verbs, const vector<Noun>& nouns, const vector<PersonNoun>& personNouns) {
	GeneratedSentence result;
	GeneratedSentence firstSentence;
	vector<string> splitSentence;
	string part;

	vector <Verb> validVerbs;
	for (Verb word : verbs) {
		if (word.hasTag("kein")) { validVerbs.push_back(word); }
	}

	Pronoun pronoun = getRandomItem(pronouns);
	Verb verb = getRandomItem(validVerbs);
	vector<Noun> validNouns = getValidNouns(nouns, verb);
	Noun noun = getRandomItem(validNouns);
	PersonNoun personNoun = getRandomItem(personNouns);
	int choice;

	choice = coinFlip(); // flip again for kein vs ein

	if (verb.hasTag("linking")) // use Person Noun
	{
		// I am not a student. (can't use ein here)
		firstSentence = genPronounLVerbPNoun(pronoun, verb, personNoun);
		result.words = firstSentence.words;
		stringstream ss(firstSentence.sentence);
		while(getline(ss, part, ' ')) { splitSentence.push_back(part); }

		if (splitSentence[2] == personNoun.masculine) // if person noun is masculine, use keinen
		{
			result.sentence = splitSentence[0] + " " + splitSentence[1] + " keinen " + splitSentence[2];
			result.words.push_back({ "keinen", "not one, masc." });
		} 
		else { // if fem or plural, use keine
			result.sentence = splitSentence[0] + " " + splitSentence[1] + " keine " + splitSentence[2];
			result.words.push_back({ "keine", "not one/not any, fem./plural" });
		}
	} 
	else {
		// I do not have a coffee. I have a coffee.
		firstSentence = genPronounVerbNoun(pronoun, verb, noun);
		stringstream ss(firstSentence.sentence);
		result.words = firstSentence.words;
		while(getline(ss, part, ' ')) { splitSentence.push_back(part); }

		if (choice == 0) { // kein
			if (noun.gender == "masculine") {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " keinen " + splitSentence[2];
				result.words.push_back({ "keinen", "not one, masc." });
			} else if (noun.gender == "neuter") {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " kein " + splitSentence[2];
				result.words.push_back({ "kein", "not one, neuter." });
			} else {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " keine " + splitSentence[2];
				result.words.push_back({ "keine", "not one, fem." });
			}
		} else { // ein
			if (noun.gender == "masculine") {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " einen " + splitSentence[2];
			    result.words.push_back({ "einen", "a, masc." });
			} else if (noun.gender == "neuter") {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " ein " + splitSentence[2];
				result.words.push_back({ "ein", "a, neuter" });
			} else {
				firstSentence.sentence = splitSentence[0] + " " + splitSentence[1] + " eine " + splitSentence[2];
				result.words.push_back({ "eine", "a, fem." });
			}
		}
	}
	return result;
}
GeneratedSentence generateYesNoQuestion() {
	//
}

GeneratedSentence generateKeinSentence() {
	//
}
*/
