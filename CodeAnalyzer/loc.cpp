//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
#include "loc.h"
//constructor
Loc::Loc(){
    score=0;
    lines=0;
}

//Prints the short analysis to the file
void Loc::printToFileShort(ofstream&){


}

//Prints the verbose analysis to the file
void Loc::printToFileVerbose(ofstream&){


}


/* Primarily focusing on right tailed distributions/outliers being
 * "bad".
 * A normal distribution is optimal.
 * Left tailed is "average"
 */

void Loc::evaluate(const char * filePath){
    //create a FileInfo object
    FileInfo currFile (filePath);

    //add to vector of FileInfo objects
    files.add(currFile);

    cout<<currFile.getLines()<<endl;
}

