//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
#include "nesting.h"


//constructor
Nesting::Nesting(){

}

//Prints the short analysis to the file
void Nesting::printToFileShort(ofstream& out){
    out << "Printing nesting short" << endl;

}

//Prints the verbose analysis to the file
void Nesting::printToFileVerbose(ofstream& out){
    out << "Printing nesting verbose" << endl;

}

void Nesting::evaluate(const char *){

}

/* There should not be excessive use of nesting in a project
 * Excessive meaning: multiple (more than 2) nested if statements
 * More than 4 nested loops of any kind
 */


