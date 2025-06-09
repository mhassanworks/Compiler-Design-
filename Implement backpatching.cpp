#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Quadruple structure
struct Quad {
    string op;
    string arg1;
    string arg2;
    string result;
};

vector<Quad> quadTable;
int nextInstr = 0;

// Generates a new quadruple
void gen(string op, string arg1, string arg2, string result) {
    quadTable.push_back({op, arg1, arg2, result});
    nextInstr++;
}

// Makes a new list containing a single index
vector<int> makelist(int i) {
    return vector<int>{i};
}

// Merges two lists of indices
vector<int> merge(const vector<int>& list1, const vector<int>& list2) {
    vector<int> result = list1;
    result.insert(result.end(), list2.begin(), list2.end());
    return result;
}

// Backpatch the given list with the target label/index
void backpatch(vector<int>& list, int target) {
    for (int i : list) {
        quadTable[i].result = to_string(target);
    }
}

// Displays the generated quadruples
void printQuads() {
    cout << "\nGenerated Quadruples:\n";
    for (int i = 0; i < quadTable.size(); ++i) {
        cout << i << ": (" << quadTable[i].op << ", " 
             << quadTable[i].arg1 << ", " 
             << quadTable[i].arg2 << ", " 
             << quadTable[i].result << ")\n";
    }
}

// Sample usage demonstrating backpatching
int main() {
    // Simulating: if a < b goto ?
    gen("if_less", "a", "b", "_");
    vector<int> truelist = makelist(nextInstr - 1);

    // Simulating: goto ?
    gen("goto", "_", "_", "_");
    vector<int> falselist = makelist(nextInstr - 1);

    // Simulate target instruction
    int target1 = nextInstr;
    gen("=", "1", "_", "x");  // Then block

    // Backpatch true condition with then block
    backpatch(truelist, target1);

    // Simulate target for false jump
    int target2 = nextInstr;
    gen("=", "0", "_", "x");  // Else block

    // Backpatch false condition with else block
    backpatch(falselist, target2);

    // Print all quadruples
    printQuads();

    return 0;
}
