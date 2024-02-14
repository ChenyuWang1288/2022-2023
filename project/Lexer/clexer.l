%{ 
    #include<stdio.h>
    #include"cparser.tab.h"
   //#include "tokens.h"

    extern  int  yyerror( const  char*);

    int LinePos = 1;  
    int ColPos = 1;
 
    void CountLine();
    void CountWord();
%}

digit [0-9]

no_digit [_a-zA-Z]

no_zero_digit [1-9]

hexadecimal_digit [0-9a-fA-F]

c_char [^\'\\]

s_char [^\"\\]

%%

(\/\*([^*])*(\*)+([^/*][^*]*(\*)+)*\/)|(\/\/(.*)\n) {   
            
            char *p = yytext;
            for(; *p; p++){    if(*p=='\n') LinePos++; }  //处理多行注释的情况
            return -2;    
}

\n {
           CountLine();
           //return '\n';   //for testing
}

" " {
           CountWord();
          // return ' ' ;  //for testing
}

char {
            
           CountWord(); 
           return CHAR;
     }

int  {
           CountWord();
           return INT;
     }

float {
           CountWord();
           return FLOAT;

    }

double {
           CountWord();
           return DOUBLE; 
}

short {
           CountWord();
           return SHORT;
     }

long {
           CountWord();
           return LONG;
     }

struct {
           CountWord();
           return STRUCT;
    }

void {
           CountWord();
           return VOID; 
}

unsigned {
           CountWord();
           return  UNSIGNED;
     }

static {
           CountWord();
           return STATIC;
     }

auto {
           CountWord();
           return AUTO;
     }

const {
           CountWord();
           return CONST; 
}

break {

          CountWord();
          return BREAK; 
}

case {
           CountWord();
           return CASE;
     }

continue {
           CountWord();
           return CONTINUE;
     }

do {
           CountWord();
           return DO;

   }

else {

           CountWord();
           return ELSE; 

}

enum {

          CountWord();
          return ENUM; 
}

for {
           CountWord();
           return FOR;
     }

if {
           CountWord();
           return IF;
     }

return {
           CountWord();
           return RETURN;
    }

sizeof {

       CountWord();
       return SIZEOF; 

}

switch {

       CountWord();
       return SWITCH; 
}

typedef {
           CountWord();
           return TYPEDEF;
     }

union  {
           CountWord();
           return UNION;
     }

while {    
           CountWord();
           return WHILE;

    }

"++" {  
        CountWord();
        return SELF_ADD;
}

"--" {
        CountWord();
        return SELF_SUB;
}

"<<" {
       CountWord();
       return LEFT_SHIFT;
}

">>" {
        CountWord();
        return RIGHT_SHIFT;
}

"<=" {  
        CountWord();
        return LESS_EQUAL;
}

">=" {
       CountWord();
       return GREATER_EQUAL;
}

"==" {
       CountWord();
       return EQUAL;
}

"!=" {
        CountWord();
        return UNEQUAL;
}

"&&" {

       CountWord();
       return AND;
}

"||" {
        CountWord();
        return OR;
}

"*=" {
        CountWord();
        return MUL_ASSIGN;
}

"/=" {
        CountWord();
        return DIV_ASSIGN;
}

"%=" {
        CountWord();
        return MOD_ASSIGN;
}

"+=" {  
        CountWord();
        return ADD_ASSIGN;
}

"-=" {
       CountWord();
       return SUB_ASSIGN;
}

"<<=" {
        CountWord();
        return LEFT_SHIFT_ASSIGN;
}

">>=" {
        CountWord();
        return RIGHT_SHIFT_ASSIGN; 
}

"&=" {
        CountWord();
        return BIT_AND_ASSIGN;
}

"|=" {
        CountWord();
        return BIT_OR_ASSIGN;
}

"^=" {
       CountWord();
       return BIT_XOR_ASSIGN;
}

"->" {
       CountWord();
       return POINTER;
}

[\[\]\(\)\{\}\.\+\-\*\/\&\|\!\%\>\<\^\?\:\;\=\,\^] {
       CountWord();
       return yytext[0];
}
 
{no_digit}({no_digit}|{digit})* {
       CountWord();       
       return ID;
}

0|({no_zero_digit}{digit}*)|(("0x"|"0X"){hexadecimal_digit}*) {
       CountWord();
       return C_INT;
}

{digit}*\.{digit}* {
    CountWord();
    return C_FLOAT;
}


\'{c_char}+\' {
      CountWord();
      return C_CHAR;
}

\"{s_char}*\" {
  
    CountWord(); 
    return C_STRING;
}

<<EOF>>  {
    return EOF;
}

. {
    return  ERROR;
}

%%

void CountLine(){
    LinePos += 1;
    ColPos = 0;
}

void CountWord(){
    ColPos += yyleng;
}

int yywrap(){
    return 1;
}

