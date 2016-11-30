//Class to determine the the proportion of code in main vs elsewhere in the project
//Inherits from abstract class Metrics

#include "codeinmain.h"
    //evaluates the metric
    void codeInMain::evaluate(char* filePath){
        //convert to string
        String fullPath(filePath);

        //split by the character /
        Vector<String>pathParts = fullpath.split('/');

        //get the file name, will be the last part in the vector
        String fileName = partParts[pathParts.size()-1];

        //check if the current file is main.

        //if it is main, total the lines of code in main into the variable linesInMain
        //for main, the number of lines is equivalent to the number of semicolons
        //in that file plus the number of open braces.

        //otherwise, sum lines of code into totalLines
        //calculate the percent
        //score based on score table
    }

//Prints the short analysis to the file
void CodeInMain::printToFileShort(){


}

//Prints the verbose analysis to the file
void CodeInMain::printToFileVerbose(){


}

void CodeInMain::evaluate(char *){

}

/* The percentage of code in main should not exceed 2% of the
 * total amount of code in the project */
