%{
#include <stdio.h>
%}

/*Lex program to take input from file and 
remove multiple spaces, newline and tab 
and write output in a separate file*/

%%
\/\/           {}
f           { printf("floatdcl"); }
i           { printf("intdcl"); }
p           { printf("print"); }
=           { printf("assign"); }
"+"         { printf("plus"); }
"-"         { printf("minus"); }
"*"         { printf("mult"); }
"/"         { printf("div"); }
[\r]          { printf("\r"); }
[\n]          { printf("\n"); }
" "          { printf(" "); }
[\t]        { printf("\t"); }
^[-+]?[0-9]*    { printf("inum"); }
^[-+]?[0-9]*[.][0-9]+$  { printf("fnum"); }
[a-eghj-oq-z]+   { printf("id"); }
%%

int main(int argc, char** argv) 
{ 
    FILE *fileOut, *fileIn;

        if(argc > 1) {
            fileIn = fopen(argv[1],"r");
            yyin = fileIn;
        }

        fileOut = fopen("lex.out","w");
        yyout = fileOut;
        yylex();
} 


