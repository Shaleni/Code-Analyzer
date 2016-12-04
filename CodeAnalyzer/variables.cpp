//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
#include "variables.h"

//Constructors
Variables::Variables(){

}


//Prints the short analysis to the file
void Variables::printToFileShort(ofstream& out){
    out << "Printing variables short" <<endl;
    generateScore();

}

//Prints the verbose analysis to the file
void Variables::printToFileVerbose(ofstream& out){
    out << "Printing variables verbose" <<endl;
    generateScore();

}

void Variables::evaluate(const char * filePath){
    //variable to hold a line of code
    char codeBlock[100];
    char className[100];

    fstream fin;
    fin.open(filePath);

    if (fin.is_open()){
        while (!fin.eof()){
            fin>>codeBlock;
            String cB(codeBlock);
            if (cB == "class"){
                fin>>className;
                String cName(className);
                //remove trailing semicolons
                if (cName[cName.size()-1]==';'){
                    cName = cName.substring(0, cName.size()-1);
                }
                //remove anything after (and including) a colon
                int i=0;
                while (cName[i] != ':' && i<cName.size()){
                    i++;
                }
                if (cName[i] == ':'){
                    cName = cName.substring(0, i);
                }

                //add class name to the vector of classNames
                classNames.add(cName);
            }
        }

        fin.close();
    } else {
        cout<<"Error. File failed to open"<<endl;
    }

}

void Variables::generateScore(){

}

// See txt file for standards on variable name quality
