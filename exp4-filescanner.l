%option noyywrap
%{
#include <stdio.h>
%}

%%
integer|read|display|if|else|then|while|for|to|step { printf("Keyword: %s\n", yytext); }
"<="|">="|"<"|">"|"=="|"#" { printf("Relational Operator: %s\n", yytext); }
"+"|"-"|"*"|"/" { printf("Arithmetic Operator: %s\n", yytext); }
"++" { printf("Increment Operator: %s\n", yytext); }
"--" { printf("Decrement Operator: %s\n", yytext); }
"=" { printf("Assignment Operator: %s\n", yytext); }
"("|")"|"{"|"}"|","|";" { printf("Special Symbol: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[0-9]+ { printf("Number: %s\n", yytext); }
[ \t\n]+ { /* Skip whitespace */ }
. { /* Ignore any other symbols */ }
%%

int main() {
    // Open the file provided as argument
    FILE *file = fopen("file4.star.txt", "r");
    if (!file) {
        perror("file4.star.txt");
        return 1;
    }

    // Set Flex to read from the file instead of stdin
    yyin = file;

    // Start parsing
    yylex();

    // Close the file
    fclose(file);
    return 0;
}
