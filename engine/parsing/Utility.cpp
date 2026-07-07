#include "Utility.h"

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

vector<string> splitTags(const string& text) {
	vector<string> tags;
	stringstream ss(text);
	string tag;

	while (getline(ss, tag, '|')) {
		tags.push_back(tag);
	}
	return tags;
}

string capitalizeFirst(const string& text) {
	string capitalizeFirst = text;
	capitalizeFirst[0] = toupper(capitalizeFirst[0]);
	return capitalizeFirst;
}

int coinFlip() {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 
	uniform_int_distribution<> dist(0, 1);
	return dist(gen);
}

int threeSideDice() {
	random_device rd; // get randomness from system
	mt19937 gen(rd()); // random number generator 
	uniform_int_distribution<> dist(0, 2);
	return dist(gen);
}

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