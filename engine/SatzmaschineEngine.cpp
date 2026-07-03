#include "SatzmaschineEngine.h"
#include "Utility.h"
#include "Sentence.h"

SatzmaschineEngine::SatzmaschineEngine()
{
    pronouns = parsePronouns("pronouns.txt");
    verbs = parseVerbs("lvl1verbs.txt");
    nouns = parseNouns("lvl1nouns.txt");
    personNouns = parsePersonNouns("lvl1personnouns.txt");
    adjectives = parseAdjectives("lvl1adjectives.txt");
    adverbs = parseAdverbs("lvl1adverbs.txt");
    startNouns = parseStartNouns("lvl1startnouns.txt");
    nounStartingVerbs = parseNounStartingVerbs("lvl1nounstartingverbs.txt");
}

bool SatzmaschineEngine::loadedSuccessfully() const
{
    return !pronouns.empty()
        && !verbs.empty()
        && !nouns.empty()
        && !personNouns.empty()
        && !adjectives.empty()
        && !adverbs.empty()
        && !startNouns.empty()
        && !nounStartingVerbs.empty();
}

std::string SatzmaschineEngine::generateLevelOneSentence() const
{
    switch (coinFlip()) {
    case 0:
        return generatePronounSimpleSentence(
            pronouns,
            verbs,
            personNouns,
            nouns,
            adjectives,
            adverbs
        );

    case 1:
        return generateNounSimpleSentence(
            startNouns,
            nounStartingVerbs,
            adjectives,
            adverbs
        );

    default:
        return "ERROR";
    }
}