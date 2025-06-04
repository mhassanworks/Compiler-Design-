#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct Production {
    string lhs;
    string rhs;

    Production(string l, string r) : lhs(l), rhs(r) {}
};

struct Item {
    string lhs;
    string rhs;
    int dotPosition;

    Item(string l, string r, int d) : lhs(l), rhs(r), dotPosition(d) {}

    string toString() const {
        string s = lhs + " -> ";
        for (int i = 0; i < rhs.size(); i++) {
            if (i == dotPosition) s += ".";
            s += rhs[i];
        }
        if (dotPosition == rhs.size()) s += ".";
        return s;
    }

    bool operator<(const Item &other) const {
        return make_tuple(lhs, rhs, dotPosition) < make_tuple(other.lhs, other.rhs, other.dotPosition);
    }

    bool operator==(const Item &other) const {
        return lhs == other.lhs && rhs == other.rhs && dotPosition == other.dotPosition;
    }
};

using ItemSet = set<Item>;

vector<Production> productions;
map<string, vector<string>> prodMap;

ItemSet closure(const ItemSet &items) {
    ItemSet result = items;
    queue<Item> q;

    for (const auto &item : items)
        q.push(item);

    while (!q.empty()) {
        Item current = q.front();
        q.pop();

        if (current.dotPosition < current.rhs.size()) {
            string symbol(1, current.rhs[current.dotPosition]);

            if (prodMap.find(symbol) != prodMap.end()) {
                for (const auto &prod : prodMap[symbol]) {
                    Item newItem(symbol, prod, 0);
                    if (result.
