#include <emscripten/bind.h>
#include <string>

#include "engine/SatzmaschineEngine.h"

SatzmaschineEngine engine;

std::string generateSentenceForWeb()
{
    if (!engine.loadedSuccessfully()) {
        return "Failed to load words.";
    }

    return engine.generateLevelOneSentence();
}

EMSCRIPTEN_BINDINGS(satzmaschine_module)
{
    emscripten::function("generateSentence", &generateSentenceForWeb);
}