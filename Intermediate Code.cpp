#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure for Quadruple
struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};

// Structure for Triple
struct Triple {
    string op;
    string arg1;
    string arg2;
};

// Helper function to print Quadruples
void printQuadruples(const vector<Quadruple>& quads) {
    cout << "\nQuadruples:\n";
    cout << "Op\tArg1\tArg2\tResult\n";
    for (auto& q : quads) {
        cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << "\n";
    }
}

// Helper function to print Triples
void printTriples(const vector<Triple>& triples) {
    cout << "\nTriples:\n";
    cout << "Index\tOp\tArg1\tArg2\n";
    for (int i = 0; i < triples.size(); ++i) {
        cout << i << "\t" << triples[i].op << "\t" << triples[i].arg1 << "\t" << triples[i].arg2 << "\n";
    }
}

// Helper function to print Indirect Triples
void printIndirectTriples(const vector<Triple>& triples) {
    cout << "\nIndirect Triples:\n";
    cout << "Pointer\t→\tOp\tArg1\tArg2\n";
    for (int i = 0; i < triples.size(); ++i) {
        cout << "P[" << i << "]\t→\t" << triples[i].op << "\t" << triples[i].arg1 << "\t" << triples[i].arg2 << "\n";
    }
}

int main() {
    // Example expression: a = b + c * d
    vector<Quadruple> quads;
    vector<Triple> triples;

    // Step 1: t1 = c * d
    quads.push_back({"*", "c", "d", "t1"});
    triples.push_back({"*", "c", "d"});

    // Step 2: t2 = b + t1
    quads.push_back({"+", "b", "t1", "t2"});
    triples.push_back({"+", "b", "(0)"}); // Referring to t1

    // Step 3: a = t2
    quads.push_back({"=", "t2", "", "a"});
    triples.push_back({"=", "(1)", ""});  // Referring to t2

    // Output all representations
    printQuadruples(quads);
    printTriples(triples);
    printIndirectTriples(triples);

    return 0;
}
