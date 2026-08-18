#include "parsing.h"

WordBank parseWords(const string& fileName) {
	WordBank words;

	ifstream file(fileName);

	if (!file.is_open()) {
		return words;
	}

	string line;

	getline(file, line); // skip header

	while (getline(file, line)) {
		stringstream ss(line);

		string kind;
		string levelText;
		string english;
		string word;
		string categories;
		string number;
		string person;

		string singularFirst;
		string singularSecond;
		string singularThird;
		string pluralVerb;

		string nounGender;
		string neuterNoun;
		string masculineNoun;
		string feminineNoun;
		string pluralNoun;

        getline(ss, kind, ',');
        getline(ss, levelText, ',');
        getline(ss, english, ',');
        getline(ss, word, ',');
        getline(ss, categories, ',');
        getline(ss, number, ',');
        getline(ss, person, ',');

        getline(ss, singularFirst, ',');
        getline(ss, singularSecond, ',');
        getline(ss, singularThird, ',');
        getline(ss, pluralVerb, ',');

        getline(ss, nounGender, ',');
		getline(ss, neuterNoun, ',');
        getline(ss, masculineNoun, ',');
        getline(ss, feminineNoun, ',');
        getline(ss, pluralNoun, ',');

        kind = trim(kind);
        levelText = trim(levelText);
        english = trim(english);
        word = trim(word);
        categories = trim(categories);
        number = trim(number);
        person = trim(person);

        singularFirst = trim(singularFirst);
        singularSecond = trim(singularSecond);
        singularThird = trim(singularThird);
        pluralVerb = trim(pluralVerb);

        nounGender = trim(nounGender);
		neuterNoun = trim(neuterNoun);
        masculineNoun = trim(masculineNoun);
        feminineNoun = trim(feminineNoun);
        pluralNoun = trim(pluralNoun);

        int level = stoi(levelText);

		// Pronouns
        if (kind == "pronoun") {

            words.pronouns.emplace_back(
                kind,
                level,
                english,
                word,
                number,
                person
            );
        }
		// Verbs
        else if (
            kind == "verb" ||
            kind == "linking verb"
        ) {

            words.verbs.emplace_back(
                kind,
                level,
                english,
                word,
                splitTags(categories),
                singularFirst,
                singularSecond,
                singularThird,
                pluralVerb
            );
        }
		// Nouns
        else if (kind == "noun") {

            words.nouns.emplace_back(
                kind,
                level,
                english,
                word,
                splitTags(categories),
                nounGender,
				neuterNoun,
                masculineNoun,
                feminineNoun,
                pluralNoun
            );
        }
		/*
		// Adjectives
        else if (kind == "adjective") {

            words.adjectives.emplace_back(
                kind,
                level,
                english,
                word,
                splitTags(categories)
            );
        }
		// Adverbs
        else if (kind == "adverb") {

            words.adverbs.emplace_back(
                kind,
                level,
                english,
                word
            );
        }
		*/
	}
	return words;
}

vector<string> splitTags(const string& text) {
	vector<string> tags;
	stringstream ss(text);
	string tag;

	while (getline(ss, tag, '|')) {
		tags.push_back(tag);
	}
	return tags;
}

string trim(string text)
{
    while (!text.empty() && isspace(static_cast<unsigned char>(text.front()))) {
        text.erase(text.begin());
    }

    while (!text.empty() && isspace(static_cast<unsigned char>(text.back()))) {
        text.pop_back();
    }

    return text;
}
/*
vector<Pronoun> parsePronouns(string fileName) {
	vector<Pronoun> words;
	ifstream file(fileName);
	string line;

	getline(file, line); //skip header line

	while (getline(file, line)) {
		stringstream ss(line);
		string word;
		string person;
		string number;
		string english;

		getline(ss, word, ','); // from string stream parse field 1, store in word, deliminated by ','
		getline(ss, person, ',');
		getline(ss, number, ',');
		getline(ss, english, ',');

		word = trim(word);
		person = trim(person);
		number = trim(number);
		english = trim(english);

		words.emplace_back(word, person, number, english);
	}
	file.close();
	return words;
}

vector<Verb> parseVerbs(string fileName) {
	vector<Verb> words;
	ifstream file(fileName);
	string line;

	getline(file, line); //skip header

	while (getline(file, line)) {
		stringstream ss(line);
		string infinitive;
		string ichForm;
		string duForm;
		string thirdSingularForm;
		string wirForm;
		string ihrForm;
		string sieForm;
		string tagText;
		string english;

		getline(ss, infinitive, ',');
		getline(ss, ichForm, ',');
		getline(ss, duForm, ',');
		getline(ss, thirdSingularForm, ',');
		getline(ss, wirForm, ',');
		getline(ss, ihrForm, ',');
		getline(ss, sieForm, ',');
		getline(ss, tagText, ',');
		getline(ss, english, ',');

		infinitive = trim(infinitive);
		ichForm = trim(ichForm);
		duForm = trim(duForm);
		thirdSingularForm = trim(thirdSingularForm);
		wirForm = trim(wirForm);
		ihrForm = trim(ihrForm);
		sieForm = trim(sieForm);
		tagText = trim(tagText);
		english = trim(english);

		words.emplace_back(infinitive, ichForm, duForm, thirdSingularForm, wirForm, ihrForm, sieForm, splitTags(tagText), english);
	}
	file.close();
	return words;
}

vector<Noun> parseNouns(string fileName) {
	vector<Noun> words;
	ifstream file(fileName);
	string line;

	getline(file, line); 

	while (getline(file, line)) {
		stringstream ss(line);
		string gender;
		string word;
		string objTagText;
		string english;

		getline(ss, gender, ',');
		getline(ss, word, ',');
		getline(ss, objTagText, ',');
		getline(ss, english, ',');

		gender = trim(gender);
		word = trim(word);
		objTagText = trim(objTagText);
		english = trim(english);

		words.emplace_back(gender, word, splitTags(objTagText), english);
	}
	file.close();
	return words;
}

vector<PersonNoun> parsePersonNouns(string fileName) {
	vector<PersonNoun> words;
	ifstream file(fileName);
	string line;

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string masculine;
		string feminine;
		string plural;
		string personnounTagText;
		string english;

		getline(ss, masculine, ',');
		getline(ss, feminine, ',');
		getline(ss, plural, ',');
		getline(ss, personnounTagText, ',');
		getline(ss, english, ',');

		masculine = trim(masculine);
		feminine = trim(feminine);
		plural = trim(plural);
		personnounTagText = trim(personnounTagText);
		english = trim(english);

		words.emplace_back(masculine, feminine, plural, splitTags(personnounTagText), english);
	}
	file.close();
	return words;
}

vector<Adjective> parseAdjectives(string fileName) {
	vector<Adjective> words;
	ifstream file(fileName);
	string line;

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string singular;
		string plural;
		string tagText;
		string english;

		getline(ss, singular, ',');
		getline(ss, plural, ',');
		getline(ss, tagText, ',');
		getline(ss, english, ',');

		singular = trim(singular);
		plural = trim(plural);
		tagText = trim(tagText);
		english = trim(english);

		words.emplace_back(singular, plural, splitTags(tagText), english);
	}
	file.close();
	return words;
}

vector<Adverb> parseAdverbs(string fileName) {
	vector<Adverb> words;
	ifstream file(fileName);
	string line;

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string adverb;
		string english;

		getline(ss, adverb, ',');
		getline(ss, english, ',');

		adverb = trim(adverb);
		english = trim(english);

		words.emplace_back(adverb, english);
	}
	file.close();
	return words;
}

vector<StartNoun> parseStartNouns(string fileName) {
	vector<StartNoun> words;
	ifstream file(fileName);
	string line;

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string masc;
		string fem;
		string plural;
		string otherGender;
		string firstTagText;
		string secondTagText;
		string english;

		getline(ss, masc, ',');
		getline(ss, fem, ',');
		getline(ss, plural, ',');
		getline(ss, otherGender, ',');
		getline(ss, firstTagText, ',');
		getline(ss, secondTagText, ',');
		getline(ss, english, ',');

		masc = trim(masc);
		fem = trim(fem);
		plural = trim(plural);
		otherGender = trim(otherGender);
		firstTagText = trim(firstTagText);
		secondTagText = trim(secondTagText);
		english = trim(english);

		words.emplace_back(masc, fem, plural, otherGender, splitTags(firstTagText), splitTags(secondTagText), english);
	}
	file.close();
	return words;
}

vector<NounStartingVerb> parseNounStartingVerbs(string fileName) {
	vector<NounStartingVerb> words;
	ifstream file(fileName);
	string line;

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);
		string singular;
		string plural;
		string firstTagText;
		string secondTagText;
		string english;

		getline(ss, singular, ',');
		getline(ss, plural, ',');
		getline(ss, firstTagText, ',');
		getline(ss, secondTagText, ',');
		getline(ss, english, ',');

		singular = trim(singular);
		plural = trim(plural);
		firstTagText = trim(firstTagText);
		secondTagText = trim(secondTagText);
		english = trim(english);

		words.emplace_back(singular, plural, splitTags(firstTagText), splitTags(secondTagText), english);
	}
	file.close();
	return words;
}
*/
