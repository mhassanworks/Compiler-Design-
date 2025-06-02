#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Grammar rules
bool isReducible(stack<string>& parseStack) {
    vector<string> tokens;

    // Get top 3 elements (if possible)
    if (parseStack.size() >= 3) {
        string third = parseStack.top(); parseStack.pop();
        string second = parseStack.top(); parseStack.pop();
        string first = parseStack.top(); parseStack.pop();

        // Check for E + E or E * E
        if ((first == "E" && (second == "+" || second == "*") && third == "E")) {
            parseStack.push("E");
            return true;
        }

        // Restore stack if no reduction
        parseStack.push(first);
        parseStack.push(second);
        parseStack.push(third);
    }

    // Check for ( E )
    if (parseStack.size() >= 3) {
        string third = parseStack.top(); parseStack.pop();
        string second = parseStack.top(); parseStack.pop();
        string first = parseStack.top(); parseStack.pop();

        if (first == "(" && second == "E" && third == ")") {
            parseStack.push("E");
            return true;
        }

        parseStack.push(first);
        parseStack.push(second);
        parseStack.push(third);
    }

    // Check for id → E
    if (!parseStack.empty()) {
        string top = parseStack.top();
        if (top == "id") {
            parseStack.pop();
            parseStack.push("E");
            return true;
        }
    }

    return false;
}

int main() {
    vector<string> input;
    string token;

    cout << "Enter input string (space-separated tokens, e.g., id + id * id): ";
    while (cin >> token) {
        input.push_back(token);
        if (cin.peek() == '\n') break;
    }

    stack<string> parseStack;
    int i = 0
