%{
#include <iostream>
#include <string>
using namespace std;

int line_num = 1;
%}

digit       [0-9]
alpha       [a-zA-Z]
id          {alpha}({alpha}|{digit})*
number      {digit}+

%%
"int"|"float"|"return"|"if"|"else"|"while"    { cout << "Keyword: " << yytext << endl; }
{id}                                           { cout << "Identifier: " << yytext << endl; }
{number}                                       { cout << "Number: " << yytext << endl; }
"+"|"-"|"*"|"/"                                { cout << "Operator: " << yytext << endl; }
"="                                            { cout << "Assignment: " << yytext << endl; }
"("                                            { cout << "Left Parenthesis" << endl; }
")"                                            { cout << "Right Parenthesis" << endl; }
";"                                            { cout << "Semicolon" << endl; }
"{"                                            { cout << "Left Brace" << endl; }
"}"                                            { cout << "Right Brace" << endl; }
[ \t]+                                         { /* skip whitespace */ }
\n                                             { line_num++; }
"//".*                                         { /* single line comment */ }
.                                              { cout << "Unknown token: " << yytext << endl; }
%%

int main(int argc, char** argv) {
    cout << "Lexical Analysis Started...\n";
    yylex();
    cout << "Lexical Analysis Completed. Total lines: " << line_num << endl;
    return 0;
}

int yywrap() {
    return 1;
}
