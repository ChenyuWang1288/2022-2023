%{ 
    #include<stdio.h>
    #include"cparser.tab.h"
    #include"absyn.h"
   //#include "tokens.h"

    extern  int  yyerror( const  char*);

    int LinePos = 1;  
    int ColPos = 1;
 
    void CountLine();
    void CountWord();
    int hexToDec(char hexChar);
%}

digit [0-9]

no_digit [_a-zA-Z]

no_zero_digit [1-9]

hexadecimal_digit [0-9a-fA-F]

c_char [^\'\\]

s_char [^\"\\]

%%


"/*"([^*]|(\*+[^*/]))*"*/" {
    char* newlinePtr = yytext;
    while ((newlinePtr = strchr(newlinePtr, '\n')) != NULL) {
        LinePos++;
        ColPos=1;
        newlinePtr++;
    }
}

"//"(.*)     { LinePos++; ColPos=1; }

td {
        CountWord();
        return TD;
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

default {
        CountWord();
        return DEFAULT;
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
       int len = strlen(yytext);
       yylval.s = (char*) malloc(len*sizeof(char)+1);
       strcpy(yylval.s,yytext);
       return ID;
}

[1-9][0-9]*         { yylval.i = atoi(yytext); return C_INT; }
0[xX][0-9a-fA-F]+   { yylval.i = strtol(yytext, NULL, 16); return C_INT; }
0[0-7]+             { yylval.i = strtol(yytext, NULL, 8); return C_INT; }
0                   { yylval.i = 0; return C_INT; }

{digit}*\.{digit}* {
    CountWord();
    yylval.fnum = atof(yytext);
    return C_FLOAT;
}


'([^'\\\n]|\\[abfnrtv\\'\?"]|\\[0-7]{1,3}|\\x[0-9a-fA-F]+)'   {
    CountWord();
    char* escaped = yytext + 1;
    char converted;
    if (*escaped == '\\') {
        escaped++;
        switch (*escaped) {
            case 'a': converted = '\a'; break;
            case 'b': converted = '\b'; break;
            case 'f': converted = '\f'; break;
            case 'n': converted = '\n'; break;
            case 'r': converted = '\r'; break;
            case 't': converted = '\t'; break;
            case 'v': converted = '\v'; break;
            case '\\': converted = '\\'; break;
            case '\'': converted = '\''; break;
            case '\"': converted = '\"'; break;
            case '\?': converted = '\?'; break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7': {
                int octalValue = 0;
                while (*escaped >= '0' && *escaped <= '7') {
                    octalValue = (octalValue * 8) + (*escaped - '0');
                    escaped++;
                }
                converted = (char)octalValue;
                escaped--;
                break;
            }
            case 'x': {
                escaped++;
                int hexValue = 0;
                while ((*escaped >= '0' && *escaped <= '9') || (*escaped >= 'a' && *escaped <= 'f') || (*escaped >= 'A' && *escaped <= 'F')) {
                    hexValue = (hexValue * 16) + hexToDec(*escaped);
                    escaped++;
                }
                converted = (char)hexValue;
                escaped--;
                break;
            }
            default: converted = *escaped; break;
        }
    } else {
        converted = *escaped;
    }

    yylval.c = converted;
    return C_CHAR;
}

\"(\\.|[^"])*\" {
  
    CountWord();
    int len = strlen(yytext);
    char * result = (char*)malloc((len-1)*sizeof(char));  //len-2 + 1
    int i;
    for(i=0;i<len-2;i++){
       result[i] = yytext[i+1];
    }
    result[len-1] = '\0';
    yylval.s = result;
    return C_STRING;
}



<<EOF>>  {
    return EOF;
}

\r|(\n\r)|(\n)|(\r\n) {
           CountWord();
           CountLine();
           //return '\n';   //for testing
}

\t {
        CountWord();
}

" " {
           CountWord();
          // return ' ' ;  //for testing
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

int hexToDec(char hexChar) {
    if (hexChar >= '0' && hexChar <= '9') {
        return hexChar - '0';
    } else if (hexChar >= 'a' && hexChar <= 'f') {
        return hexChar - 'a' + 10;
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        return hexChar - 'A' + 10;
    } else {
        return 0;  // 非法的十六进制字符，返回0
    }
}

int yywrap(){
    return 1;
}



