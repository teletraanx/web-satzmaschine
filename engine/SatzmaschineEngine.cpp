#include "SatzmaschineEngine.h"
#include "utility/Utility.h"
#include "utility/parsing.h"
#include "utility/WordBank.h"
#include "generation/Sentence.h"
#include "words/GeneratedSentence.h"

SatzmaschineEngine::SatzmaschineEngine()
{
    WordBank words = parseWords("data/words.csv");
}

bool SatzmaschineEngine::loadedSuccessfully() const
{
    /*
    return !levelOnePronouns.empty()
        && !levelOneVerbs.empty()
        && !levelOneNouns.empty()
        && !levelOnePersonNouns.empty()
        && !levelOneAdjectives.empty()
        && !levelOneAdverbs.empty()
        && !levelOneStartNouns.empty()
        && !levelOneNounStartingVerbs.empty();
    */
}

GeneratedSentence
SatzmaschineEngine::generateLevelOneSentence() const
{
    switch (coinFlip()) {
    case 0:
        return generatePronounSimpleSentence(
            levelOnePronouns,
            levelOneVerbs,
            levelOnePersonNouns,
            levelOneNouns,
            levelOneAdjectives,
            levelOneAdverbs
        );

    case 1:
        return generateNounSimpleSentence(
            levelOneStartNouns,
            levelOneNounStartingVerbs,
            levelOneAdjectives,
            levelOneAdverbs
        );

    default:
        return {
            "Unable to generate a Level 1 sentence.",
            {}
        };
    }
}

GeneratedSentence
SatzmaschineEngine::generateLevelTwoSentence() const
{
    return {
        "Level 2 sentence generation is coming soon.",
        {}
    };
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
        return generateLevelTwoSentence();

    /*
    case 3:
        return generateLevelThreeSentence();

    case 4:
        return generateLevelFourSentence();

    case 5:
        return generateLevelFiveSentence();
    */

    default:
        return {
            "The selected level is not available.",
            {}
        };
    }
}