/* To run in cmd:
bison -d exp5_y.y
flex exp5-scanner.l
gcc lex.yy.c exp5_y.tab.c -W
a
*/

%option noyywrap

%{
#include <stdio.h>
#include "exp5_y.tab.h"

int yylex();
void yyerror(const char *s);
%}

%%
[0-9]+ { yylval.num = atoi(yytext);
         return (NUMBER);}
\n { return 0; }
[ \t]+ ;
. { return (yytext[0]); }
%%
