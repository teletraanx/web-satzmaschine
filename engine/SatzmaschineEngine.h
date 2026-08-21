#pragma once

#include <vector>

#include "words/GeneratedSentence.h"
#include "utility/WordBank.h"

using namespace std;

class SatzmaschineEngine
{
private:
    WordBank words;

    GeneratedSentence generateLevelOneSentence() const;

public:
    SatzmaschineEngine();

    bool loadedSuccessfully() const;

    GeneratedSentence generateSentence(
        const vector<int>& selectedLevels
    ) const;
};