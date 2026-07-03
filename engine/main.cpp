// in project dir: build.bat
// in web dir, start server: python -m http.server 8000
#include <iostream>
#include <string>

#include "SatzmaschineEngine.h"

using namespace std;

int main()
{
    SatzmaschineEngine engine;

    if (!engine.loadedSuccessfully()) {
        cout << "Failed to load words." << endl;
        return 1;
    }

    string answer;

    cout << "Press Enter for another sentence or q to quit:" << endl;

    do {
        cout << "Say the sentence:" << endl;
        cout << engine.generateLevelOneSentence() << endl;

        getline(cin, answer);
    }
    while (answer != "q");

    return 0;
}