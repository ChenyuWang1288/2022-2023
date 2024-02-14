#include<ctype.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;


struct errormsg {
     
     errormsg(string filename, ofstream &errormsgfile, int line, int col);

     ~errormsg();

     ofstream &errormsgfile;

     string filename;
    
     int Pos[2];

     void echoerror();

};

void echo_error_msg(string filename, ofstream &errormsgfile, int line, int col);