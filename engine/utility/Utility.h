#pragma once
#include <random>
using namespace std;

template <typename T> 
const T& getRandomItem(const vector<T>& items) {
	if (items.empty()) {
		throw runtime_error("ERROR: getRandomItem called with empty vector.");
	}

	static random_device rd;
	static mt19937 gen(rd());

	uniform_int_distribution<> dist(0, static_cast<int>(items.size()) - 1);
	return items[dist(gen)];
}

string capitalizeFirst(const string& text);

int coinFlip();

int threeSideDice();

