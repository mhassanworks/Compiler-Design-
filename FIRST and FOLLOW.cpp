#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> productions;
set<char> nonTerminals, terminals;
char startSymbol;

bool isTerminal(char c) {
    return !isupper(c) && c != 'ε';
}

void computeFirst(char c);

set<char> getFirstOfString(const string& str) {
    set<char> result;

    if (str.empty()) {
        result.insert('ε');
        return result;
    }

    for (size_t i = 0; i < str.size(); i++) {
        char sym = str[i];
        set<char> temp = first[sym];

        for (char f : temp) {
            if (f != 'ε')
                result.insert(f);
        }

        if (temp.find('ε') == temp.end())
            return result;
    }

    result.insert('ε');
    return result;
}

void computeFirst(char c) {
    if (first.find(c) != first.end())
        return;

    first[c] = {};

    for (string prod : productions[c]) {
        if (prod == "ε") {
            first[c].insert('ε');
        } else {
            for (size_t i = 0; i < prod.size(); i++) {
                char symbol = prod[i];

                if (symbol == c)
                    continue;

                if (isTerminal(symbol)) {
                    first[c].insert(symbol);
                    break;
                } else {
                    computeFirst(symbol);
                    set<char> temp = first[symbol];

                    for (char t : temp) {
                        if (t != 'ε')
                            first[c].insert(t);
                    }

                    if (temp.find('ε') == temp.end())
                        break;

                    if (i == prod.size() - 1)
                        first[c].insert('ε');
                }
            }
        }
    }
}

void computeFollow(char c) {
    for (auto& entry : productions) {
        char lhs = entry.first;

        for (string prod : entry.second) {
            for (size_t i = 0; i < prod.size(); i++) {
                if (prod[i] == c) {
                    if (i + 1 < prod.size()) {
                        string beta = prod.substr(i + 1);
                        set<char> firstBeta
