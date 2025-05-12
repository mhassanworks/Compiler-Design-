%{
#include <iostream>
using namespace std;
%}

%option noyywrap

DIGIT   [0-9]+
WORD    [a-zA-Z]+

%%

{DIGIT}     { cout << "Number: " << yytext << endl; }
{WORD}      { cout << "Word: " << yytext << endl; }
\n          { /* ignore newlines */ }
.           { cout << "Unknown: " << yytext << endl; }

%%

int main() {
    cout << "Enter input (Ctrl+D to stop):" << endl;
    yylex();
    return 0;
}
