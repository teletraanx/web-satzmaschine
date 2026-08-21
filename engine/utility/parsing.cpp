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


