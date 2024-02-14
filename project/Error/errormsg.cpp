#include"errormsg.h"

errormsg::errormsg(string filename, ofstream &errormsgfile, int line, int col)
:filename(filename),errormsgfile(errormsgfile){
    Pos[0] = line;
    Pos[1] = col;
}

errormsg::~errormsg(){}

void errormsg::echoerror(){
    
    cout << filename << ":  " << "Error " << "in Line:" << Pos[0] << " Col:" << Pos[1] << endl;
    errormsgfile << filename << ":  " << "Error " << "in Line:" << Pos[0] << " Col:" << Pos[1] << endl;

}

void echo_error_msg(string filename, ofstream &errormsgfile, int line, int col){

    cout << filename << ":  " << "Error " << "in Line:" << line << " Col:" << col << endl;
    errormsgfile << filename << ":  " << "Error " << "in Line:" << line << " Col:" << col << endl;

}