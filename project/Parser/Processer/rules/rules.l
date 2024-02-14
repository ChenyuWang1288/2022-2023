%{
    #include<iostream>
    #include<fstream>

    using namespace std;
    
    ofstream outfile;

    int rule_id = 0;

%}

token ([_A-Za-z]+)|(\'.\')

rule \t+((\|)|{token}).*  

%%

{rule} { 
    rule_id++;
    outfile << yytext;
    outfile << "\t {  printf(\"Reduced by rule: " << rule_id << "\");  }" ;
}

<<EOF>> {return 0;}

.|\n { outfile << yytext;}

%%

int yywrap(){
    return 1;
}

int main(){

    outfile.open("grammar.code.txt", ios::out); 
    yylex();

}


