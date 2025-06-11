#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 5;
    int b = 3;
    int c = a + b;

    cout << "Simulated Machine Code for: int c = a + b;\n";
    cout << "MOV R1, 5\t; Load 5 into R1\n";
    cout << "MOV R2, 3\t; Load 3 into R2\n";
    cout << "ADD R3, R1, R2\t; Add R1 and R2, store in R3\n";

    cout << "Result: c = " << c << endl;
    return 0;
}
