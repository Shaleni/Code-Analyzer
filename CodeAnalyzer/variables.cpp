//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
#include "variables.h"

//Constructors
Variables::Variables(){

}


//Prints the short analysis to the file
void Variables::printToFileShort(ofstream& out){
    out << "Printing variables short" <<endl;

}

//Prints the verbose analysis to the file
void Variables::printToFileVerbose(ofstream& out){
    out << "Printing variables verbose" <<endl;

}

void Variables::evaluate(const char * filePath){
    //variable to hold a line of code
    char codeBlock[256];

    fstream fin;
    fin.open(filePath);

    if (fin.is_open()){
       // while () {
            fin.getline(codeBlock, 256, '{');
            String cB(codeBlock);
            cout<<"codeBlock: "<<cB<<endl;
       // }
    } else {
        cout<<"Error. File failed to open"<<endl;
    }
    fin.close();
}


// See txt file for standards on variable name quality
