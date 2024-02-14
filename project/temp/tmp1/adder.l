%{
     #include<stdio.h>
     #include<iostream>
     #include<fstream>

     using namespace std;

     ofstream outfile;
%}

point [0-9]\"

%%

{point} { outfile << yytext[0] << '\\'<< 'n' << yytext[1];}

<<EOF>> { return 0; }

.|\n|\t {
     outfile << yytext;
}

%%

int yywrap(){
     return 1;
}

int main(){

     outfile.open("cparser.c", ios::out);
     yylex();
}