//Class to determine the variable name quality in the project
//Inherits from abstract class Metricss
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

void Variables::evaluate(const char *){

}


// See txt file for standards on variable name quality
