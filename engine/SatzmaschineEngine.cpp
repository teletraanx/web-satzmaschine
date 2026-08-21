#include "SatzmaschineEngine.h"
#include "utility/Utility.h"
#include "utility/parsing.h"
#include "utility/WordBank.h"
#include "generation/Sentence.h"
#include "words/GeneratedSentence.h"

SatzmaschineEngine::SatzmaschineEngine()
{
    words = parseWords("data/words.csv");
}

bool SatzmaschineEngine::loadedSuccessfully() const
{
    return !words.pronouns.empty() 
        && !words.verbs.empty()
        && !words.nouns.empty();
}


GeneratedSentence
SatzmaschineEngine::generateLevelOneSentence() const
{
    vector<int> levels = {1};

    vector<Pronoun> pronouns = getWordsForLevels(words.pronouns, levels);
    vector<Verb> verbs = getWordsForLevels(words.verbs, levels);
    vector<Noun> nouns = getWordsForLevels(words.nouns, levels);

    return genPronounVerbNoun(pronouns, verbs, nouns);
}

GeneratedSentence
SatzmaschineEngine::generateSentence(
    const vector<int>& selectedLevels
) const
{
    if (selectedLevels.empty()) {
        return {
            "Select at least one level.",
            {}
        };
    }

    const int selectedLevel =
        getRandomItem(selectedLevels);

    switch (selectedLevel) {
    case 1:
        return generateLevelOneSentence();

    case 2:
        //

    default:
        return {
            "The selected level is not available.",
            {}
        };
    }
}