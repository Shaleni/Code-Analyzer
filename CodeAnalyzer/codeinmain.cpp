//Class to determine the the proportion of code in main vs elsewhere in the project
//Inherits from abstract class Metrics

#include "codeinmain.h"


using namespace std;

//constructor
CodeInMain::CodeInMain(){
    linesInMain=0;
    totalLines=0;
}

//evaluates the metric
void CodeInMain::evaluate(const char* filePath){

    //convert to string
    String fullPath(filePath);

    int count=0;
    char ch;
    fstream fin;
    fin.open(filePath);

    //count the number of lines in a file. a line is counted for every ; and {
    if (fin.is_open()){
        cout<<"File opened successfully"<<endl;
        //read file character by character.
        while (fin>>ch){
            if (ch==';' || ch=='{'){
                count++;
            }
        }
    } else {
        cout<<"Error. File failed to open"<<endl;
    }
    fin.close();
    cout<<"count: "<<count<<endl;
    //check if the file name is either main.cpp or main.c
    if (fullPath.substring(fullPath.size()-8, fullPath.size())=="main.cpp" ||
            fullPath.substring(fullPath.size()-6, fullPath.size())=="main.c"){
        linesInMain = count;
    } else {
        totalLines += count;
    }

    cout<<"Lines in main: "<<linesInMain<<endl;
    cout<<"total lines of code: "<<totalLines<<endl;
}

//calculates the percent of code in main
void CodeInMain::calculatePercent(){
    percent=(linesInMain/totalLines)*100;
}

//Prints the short analysis to the file
void CodeInMain::printToFileShort(ofstream&){


}

//Prints the verbose analysis to the file
void CodeInMain::printToFileVerbose(ofstream&){


}


/* The percentage of code in main should not exceed 2% of the
 * total amount of code in the project */
