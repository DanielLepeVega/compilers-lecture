%{
    #include <stdio.h>
    #include <stdlib.h>
%}//libraries in C for the methods- In this Yacc file all the input is handled, the files is being read, then it checks all the possible cases
//It checks the grammar and deppending on the case it prints the output
%token NUMBER

%left '+' '-'

%left '*'

%left '(' ')'
//here the expressions are divided into smaller expressions and then the parentheses are checked depending on the position of the token, 
//it is really easy to read and use this functions, because in YACC you can reach a more powerful and easy to use compiler following this structure.
%%
E:   E'+'E            { printf("add %d,%d,acum\n", $1, $3); }
|    E'-'E            { printf("sub %d,%d,acum\n", $1, $3); }
|    E'*'E            { printf("mul %d,%d,acum\n", $1, $3); }
|    E'+'T            { printf("add &acum,%d,acum\n", $3); }
|    E'-'T            { printf("sub &acum,%d,acum\n", $3); }
|    E'*'T            { printf("mul &acum,%d,acum\n", $3); }
|    '('E')'
|    NUMBER           
;

T:   '('E'+'E')'        { printf("add %d,%d,acum\n", $3, $5); }
|    '('E'-'E')'        { printf("sub %d,%d,acum\n", $3, $5); }
|    '('E'*'E')'        { printf("mul %d,%d,acum\n", $3, $5); }
|    '('E'*'T')'        { printf("mul &acum, %d, acum\n", $3); }
|    '('E'-'T')'        { printf("sub &acum, %d, acum\n", $3); }
|    '('E'+'T')'        { printf("add &acum, %d, acum\n", $3); }
;
%%

int main(int argc, char** argv){
    FILE *fileIn;
    char* line = NULL;
    int lineLength = 0;

    fileIn = fopen("input.txt", "r");

    if (fileIn != NULL){
        while(getline(&line, &lineLength, fileIn) != -1){
            printf("%s", line, "\n"); 
            yy_scan_string(line);
            yyparse();
        }
    }else{
        yyerror();
    }
}

int yyerror(char *s){
    fprintf(stderr,"%s\n",s);
}