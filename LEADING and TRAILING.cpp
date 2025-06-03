#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

// Grammar map: non-terminal -> list of productions
map<char, vector<string>> grammar;

// Sets to store LEADING and TRAILING
map<char, set<char>> leading, trailing;

// Function to compute LEADING set
void computeLeading(char nonTerminal) {
    for (const string &prod : grammar[nonTerminal]) {
        if (isupper(prod[0])) {
            computeLeading(prod[0]);
            leading[nonTerminal].insert(leading[prod[0]].begin(), leading[prod[0]].end());
        } else {
            leading[nonTerminal].insert(prod[0]);
        }

        // Check second character if first is non-terminal an
