%{
#include <stdio.h>
%}


%%
if|for|while|read|then|else|display|step { printf("KEYWORD %s\n",yytext); }
[<|<=|==|#|>=|>]   { printf("%s: RELATIONAL operators\n",yytext); }
"+"|"-"|"*"|"/" { printf("Arithmetic Operator: %s\n", yytext); }
"++"|"--"|"=" { printf("Increment Operator: %s\n", yytext); }

"integer"          { printf("INTEGER %s\n",yytext); }
[a-zA-Z][a-zA-Z0-9]*  { printf("IDENTIFIER %s\n",yytext); }
[ \t\n]+         ; /* Ignore whitespace and newline */
[{}();,]         { printf("%s: SYMBOL\n",yytext); }

[.]                { printf("ERROR: Unrecognized token\n"); }
[0-9]            { printf(“Digit: %s\n”,yytext); }

%%

int yywrap() {}
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
