//Class to determine the the proportion of code in main vs elsewhere in the project
//Inherits from abstract class Metrics

#include "codeinmain.h"


using namespace std;

//constructor
CodeInMain::CodeInMain(){

}

//evaluates the metric
void CodeInMain::evaluate(const char* filePath){

    //convert to string
    String fullPath(filePath);

    //split function is buggy
    //    //split by the character /
    //    Vector<String>pathParts = fullPath.split('/');

    //    //get the file name, will be the last part in the vector
    //    String fileName = pathParts[pathParts.size()-1];

    //check if the file name is either main.cpp or main.c
    if (fullPath.substring(fullPath.size()-8, fullPath.size())=="main.cpp" ||
            fullPath.substring(fullPath.size()-6, fullPath.size())=="main.c"){
        cout<<"is main"<<endl;
    }

    //check if the current file is main.

    //if it is main, total the lines of code in main into the variable linesInMain
    //for main, the number of lines is equivalent to the number of semicolons
    //in that file plus the number of open braces.

    //otherwise, sum lines of code into totalLines
    //calculate the percent
    //score based on score table
}

//Prints the short analysis to the file
void CodeInMain::printToFileShort(ofstream&){


}

//Prints the verbose analysis to the file
void CodeInMain::printToFileVerbose(ofstream&){


}


/* The percentage of code in main should not exceed 2% of the
 * total amount of code in the project */
