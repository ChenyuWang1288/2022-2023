%{
    #include<iostream>
    #include<fstream>
    #include<set>

    using namespace std;

    set<string> token_set;

    ofstream outfile;

    int rule_id = 0;

%}

token [_A-Za-z]+

%%

{token} {

      token_set.insert(string(yytext));

}

<<EOF>> {return 0;}

. {}

%%

int yywrap(){
    return 1;
}

int main(){


    outfile.open("tokens.code.txt", ios::out); 

    yylex();

    set<string>::iterator it;
    int i = 0;
    cout << endl;
    for(it=token_set.begin(); it!=token_set.end(); it++){ 
        if(i%6==0)
            outfile << endl <<"\%token ";
        i++;
        outfile << *it << " ";
    }
}


