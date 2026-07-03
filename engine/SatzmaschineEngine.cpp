#include "SatzmaschineEngine.h"
#include "parsing/Utility.h"
#include "generation/Sentence.h"

SatzmaschineEngine::SatzmaschineEngine()
{
    pronouns = parsePronouns("data/pronouns.txt");
    verbs = parseVerbs("data/lvl1verbs.txt");
    nouns = parseNouns("data/lvl1nouns.txt");
    personNouns = parsePersonNouns("data/lvl1personnouns.txt");
    adjectives = parseAdjectives("data/lvl1adjectives.txt");
    adverbs = parseAdverbs("data/lvl1adverbs.txt");
    startNouns = parseStartNouns("data/lvl1startnouns.txt");
    nounStartingVerbs = parseNounStartingVerbs("data/lvl1nounstartingverbs.txt");
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