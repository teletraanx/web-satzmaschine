#include <emscripten/bind.h>

#include <sstream>
#include <string>
#include <vector>

#include "engine/SatzmaschineEngine.h"
#include "engine/words/GeneratedSentence.h"

SatzmaschineEngine engine;
GeneratedSentence currentSentence;

std::vector<int> parseSelectedLevels(
    const std::string& selectedLevelsText
) {
    std::vector<int> selectedLevels;
    std::stringstream stream(selectedLevelsText);
    std::string levelText;

    while (std::getline(stream, levelText, ',')) {
        if (levelText.empty()) {
            continue;
        }

        std::stringstream levelStream(levelText);
        int level = 0;

        if (levelStream >> level && level > 0) {
            selectedLevels.push_back(level);
        }
    }

    return selectedLevels;
}

std::string generateSentenceForWeb(
    const std::string& selectedLevelsText
) {
    if (!engine.loadedSuccessfully()) {
        return "Failed to load words.";
    }

    const std::vector<int> selectedLevels =
        parseSelectedLevels(selectedLevelsText);

    currentSentence =
        engine.generateSentence(selectedLevels);

    return currentSentence.sentence;
}

std::string getCurrentWordsForWeb()
{
    std::stringstream output;

    for (const DisplayWord& word : currentSentence.words) {
        output
            << word.german
            << "|"
            << word.english
            << "\n";
    }

    return output.str();
}

EMSCRIPTEN_BINDINGS(satzmaschine_module)
{
    emscripten::function(
        "generateSentence",
        &generateSentenceForWeb
    );

    emscripten::function(
        "getCurrentWords",
        &getCurrentWordsForWeb
    );
}