#include<iostream>
#include<fstream>
#include"tokens.h"
#include"errormsg.h"

#define CASE_TOKEN(x) case x: outfile<<#x; break;

using namespace std;

extern int yylex();
extern int LinePos;
extern int ColPos;

ofstream outfile, errormsgfile;

int main(){

    outfile.open("outfile.txt", ios::out);
    errormsgfile.open("errormsgfile.txt", ios::out);

    int token;
    while(token = yylex()){
      switch(token){
        CASE_TOKEN(CHAR);
        CASE_TOKEN(INT);
        CASE_TOKEN(SHORT);
        CASE_TOKEN(LONG);
        CASE_TOKEN(DOUBLE);
        CASE_TOKEN(FLOAT);
        CASE_TOKEN(STRUCT);
        CASE_TOKEN(VOID);
        CASE_TOKEN(UNSIGNED);
        CASE_TOKEN(STATIC);
        CASE_TOKEN(AUTO);
        CASE_TOKEN(CONST);
        CASE_TOKEN(BREAK);
        CASE_TOKEN(CASE);
        CASE_TOKEN(CONTINUE);
        CASE_TOKEN(DO);
        CASE_TOKEN(ELSE);
        CASE_TOKEN(ENUM);
        CASE_TOKEN(FOR);
        CASE_TOKEN(IF);
        CASE_TOKEN(RETURN);
        CASE_TOKEN(SIZEOF);
        CASE_TOKEN(SWITCH);
        CASE_TOKEN(TYPEDEF);
        CASE_TOKEN(UNION);
        CASE_TOKEN(WHILE);
        CASE_TOKEN(SELF_ADD);
        CASE_TOKEN(SELF_SUB);
        CASE_TOKEN(LEFT_SHIFT);
        CASE_TOKEN(RIGHT_SHIFT);
        CASE_TOKEN(LESS_EQUAL);
        CASE_TOKEN(GREATER_EQUAL);
        CASE_TOKEN(EQUAL);
        CASE_TOKEN(UNEQUAL);
        CASE_TOKEN(AND);
        CASE_TOKEN(OR);
        CASE_TOKEN(MUL_ASSIGN);
        CASE_TOKEN(DIV_ASSIGN);
        CASE_TOKEN(MOD_ASSIGN);
        CASE_TOKEN(ADD_ASSIGN);
        CASE_TOKEN(SUB_ASSIGN);
        CASE_TOKEN(LEFT_SHIFT_ASSIGN);
        CASE_TOKEN(RIGHT_SHIFT_ASSIGN);
        CASE_TOKEN(BIT_AND_ASSIGN);
        CASE_TOKEN(BIT_OR_ASSIGN);
        CASE_TOKEN(BIT_XOR_ASSIGN);
        CASE_TOKEN(POINTER);
        CASE_TOKEN(ID);
        CASE_TOKEN(C_INT);
        CASE_TOKEN(C_CHAR);
        CASE_TOKEN(C_FLOAT);
        CASE_TOKEN(C_STRING);
        CASE_TOKEN('[');
        CASE_TOKEN(']');
        CASE_TOKEN('(');
        CASE_TOKEN(')');
        CASE_TOKEN('{');
        CASE_TOKEN('}');
        CASE_TOKEN('.');
        CASE_TOKEN('+');
        CASE_TOKEN('-');
        CASE_TOKEN('*');
        CASE_TOKEN('/');
        CASE_TOKEN('%');
        CASE_TOKEN('&');
        CASE_TOKEN('|');
        CASE_TOKEN('^');
        CASE_TOKEN('!');
        CASE_TOKEN('~');
        CASE_TOKEN('>');
        CASE_TOKEN('<');
        CASE_TOKEN('=');
        CASE_TOKEN(':');
        CASE_TOKEN(';');
        CASE_TOKEN(',');
        CASE_TOKEN('#');
        case ' ':
            outfile << " ";
            break;
        case '\n':
            outfile << endl;
            break;
        case ERROR:
            echo_error_msg(string("test.txt"),errormsgfile,LinePos,ColPos);
            break;
      default:
        break;
      }
    }

    return 0;
}