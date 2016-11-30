//Class to determine the the proportion of code in main vs elsewhere in the project
//Inherits from abstract class Metrics

#include "codeinmain.h"


using namespace std;

//constructor
CodeInMain::CodeInMain(){
    linesInMain=0;
    totalLines=0;
    score=0;
    percent=0;
}
//calculates the percent of code in main
void CodeInMain::calculatePercent(){
    percent=(linesInMain/totalLines)*100;
}

//determines the score of the file based on the following scale:
/* Scoring:
    5 - 75+% in main
    4 - [50-75)%
    3 - [20-50)%
    2 - [5-20)%
    1 - [2-5)%
    0 - [0-2)% */
void CodeInMain::determineScore(){
    if (percent>=75){
        score=5;
    } else if (percent >= 50){
        score=4;
    } else if (percent >= 20){
        score=3;
    } else if (percent >= 5){
        score=2;
    } else if (percent>=2){
        score=1;
    } else {
        score=0;
    }
}

//Prints the short analysis to the file
void CodeInMain::printToFileShort(ofstream& out){
    out<<"Score for percent of code in main: "<<score<<endl;
}

//Prints the verbose analysis to the file
void CodeInMain::printToFileVerbose(ofstream& out){
    out<<"Metric: Percent of Code in Main"<<endl;
    out<<"Number of lines of code in main: "<<linesInMain<<endl;
    out<<"Total lines of code in the project: "<<totalLines<<endl;
    out<<"Percent of code in main: "<<percent<<"%"<<endl;
    out<<"Score: "<<score<<endl;
    out<<endl;
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
    //check if the file name is either main.cpp or main.c
    if (fullPath.substring(fullPath.size()-8, fullPath.size())=="main.cpp" ||
            fullPath.substring(fullPath.size()-6, fullPath.size())=="main.c"){
        linesInMain = count;
        totalLines += count;
    } else {
        totalLines += count;
        calculatePercent();
        determineScore();
    }
}

