// GeneratedSentence.h
#pragma once

#include <string>
#include <vector>
using namespace std;

struct DisplayWord {
    string german;
    string english;
};

struct GeneratedSentence {
    string sentence;
    vector<DisplayWord> words;
};