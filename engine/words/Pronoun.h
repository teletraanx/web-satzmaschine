#pragma once
#include<iostream>
using namespace std;

class Pronoun {
public:
    string word; // ich
    string person; // first
    string number; // singular

    Pronoun(string w, string p, string n);
};