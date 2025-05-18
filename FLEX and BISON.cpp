%{
#include <iostream>
#include <cstdlib>
using namespace std;

int yylex();
void yyerror(const char *s) {
    cerr << "Error: " << s << endl;
}
%}

%token NUMBER
%token PLUS MINUS MUL DIV LPAREN RPAREN EOL

%left PLUS MINUS
%left MUL DIV

%%
input:
    | input line
    ;

line:
    expr EOL   { cout << "Result = " << $1 << endl; }
    ;

expr:
      expr PLUS expr   { $$ = $1 + $3; }
    | expr MINUS expr  { $$ = $1 - $3; }
    | expr MUL expr    { $$ = $1 * $3; }
    | expr DIV expr    { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
