#include <emscripten/bind.h>
#include <string>
#include <sstream>

#include "engine/SatzmaschineEngine.h"
#include "engine/words/GeneratedSentence.h"
using namespace std;

SatzmaschineEngine engine;
GeneratedSentence currentSentence;

string generateSentenceForWeb()
{
    if (!engine.loadedSuccessfully()) {
        return "Failed to load words.";
    }

    currentSentence = engine.generateLevelOneSentence();
    return currentSentence.sentence;
}

string getCurrentWordsForWeb() {
    stringstream ss;

    for (const DisplayWord& word : currentSentence.words) {
        ss << word.german << "|" << word.english << "\n";
    }

    return ss.str();
}

EMSCRIPTEN_BINDINGS(satzmaschine_module)
{
    emscripten::function("generateSentence", &generateSentenceForWeb);
    emscripten::function("getCurrentWords", &getCurrentWordsForWeb);
}