%{ 
   /* Definition section */
  #include<stdio.h> 
  #include "y.tab.h" 
  extern int yylval;//This is the lex file that reads numbers \t, \n and spaces so that then in the Yacc you can handle the grammar
%} 
  
/* Rule Section */
%% 
[0-9]+ { 
          yylval=atoi(yytext); 
          return NUMBER; 
       } 
[\t] ; 
[" "] ;
[\n] return 0; 
  
. return yytext[0]; 
  
%% 
  
int yywrap() 
{ 
 return 1; 
} 