#pragma once
#include<iostream>
using namespace std;

class Pronoun {
public:
    string kind;
    int level;
    string english;
    string word; 
    string number; 
    string person; 

    Pronoun(string kind, int level, string english, string word, string number, string person);
};