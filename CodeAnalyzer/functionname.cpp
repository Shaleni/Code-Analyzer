
//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
#include "functionname.h"

//Constructors
FunctionName::FunctionName(){
    score=0;
    //initialize scoreTracker to 0
    for (int i=0; i<6; i++){
        scoreTracker[i]=0;
    }

}


//Prints the short analysis to the file
void FunctionName::printToFileShort(ofstream& out){
    generateScore();
    out <<"Function Name Quality" <<endl;
    out<<"Score: "<<score<<endl;
    out<<endl;
}

//Prints the verbose analysis to the file
void FunctionName::printToFileVerbose(ofstream& out){
    generateScore();
    out <<"Function Name Quality" <<endl;
    out<<"Overall score: "<<score<<endl;
    out<<"Score breakdown: "<<endl;
    out<<"Number of function names that scored a 0: "<<scoreTracker[0]<<endl;
    out<<"Number of function names that scored a 1: "<<scoreTracker[1]<<endl;
    out<<"Number of function names that scored a 2: "<<scoreTracker[2]<<endl;
    out<<"Number of function names that scored a 3: "<<scoreTracker[3]<<endl;
    out<<"Number of function names that scored a 4: "<<scoreTracker[4]<<endl;
    out<<"Number of function names that scored a 5: "<<scoreTracker[5]<<endl;
    out<<endl;
}

void FunctionName::evaluate(const char * filePath){
    //variable to hold a line of code
    char codeBlock[100];
    char FunctionName[100];

    fstream fin;
    fin.open(filePath);

    if (fin.is_open()){
        while (!fin.eof()){
            fin>>codeBlock;
            String cB(codeBlock);
            if (cB[cB.size()]=='{'){
                //is some sort of structure
                cout<<"code block: "<<cB<<endl;

//                //remove trailing semicolons
//                if (cName[cName.size()-1]==';'){
//                    cName = cName.substring(0, cName.size()-1);
//                }
//                //remove anything after (and including) a colon
//                int i=0;
//                while (cName[i] != ':' && i<cName.size()){
//                    i++;
//                }
//                if (cName[i] == ':'){
//                    cName = cName.substring(0, i);
//                }

//                //add class name to the vector of FunctionNames
//                functionNames.add(cName);
            }
        }

        fin.close();
    } else {
        cout<<"Error. File failed to open"<<endl;
    }

}

/* Go through each class name and score it. Count the number
 * of each score type in an int array, with the index being the
 * score */
//consider using a somewhat trivial hashtable instead of an array
void FunctionName::generateScore(){
     int nameScore = 0;
     //loop through vector of class names
     for (int i=0; i<functionNames.size(); i++){
         nameScore = evaluateFunctionName(functionNames[i]);
         //statement to assign score to int array
         scoreTracker[nameScore]++;
     }

     //use the mode of file scores for the overall metric score
     score=0;

     for (int i=0; i<5; i++){
         if (scoreTracker[i+1]>scoreTracker[i]){
             score = i+1;
         }
     }
}

//evaluate a class name
/* Class names should:
 * start with an uppercase letter
 * not be longer than 20 characters
 * contain no symbols (e.g. $)
 * contain no numbers
 * not be in all caps
 */
int FunctionName::evaluateFunctionName(String fname){
    int fnameScore=0;
    //check if it starts with an uppercase letter
    String firstLetter(fname);
    firstLetter.toLowerCase();
    if (firstLetter[0]!=fname[0]){
        //changing to lowercase changed the ascii value
        //this means that the letter must have been uppercase
        //add one to score
         fnameScore++;
    } else {
        //if the lowercase version equals the first letter,
        //was not capitalized. score remains 0
    }

    //check the length of the function name
    if (fname.size()>=20){
        //too long, add to the score
        fnameScore++;
    }

    //make sure the function name contains no symbols ($)
    int j=0;
    while (fname[j] != '$' && j<fname.size()){
        j++;
    }
    if(fname[j]=='$'){
        //contains a symbol. increment score
        fnameScore++;
    }

    //make sure the function name contains no numbers
    bool numFlag=false;
    for (int i=0; i<fname.size(); i++){
        if (fname[i]=='0' || fname[i]=='1' || fname[i]=='2' ||
            fname[i]=='3' || fname[i]=='4' || fname[i]=='5' ||
            fname[i]=='6' || fname[i]=='7' || fname[i]=='8' ||
            fname[i]=='9'){
            //contains a number
            numFlag=true;
        }
    }
    if (numFlag){
        //contains a number
        fnameScore++;
    }

    //check for all caps

    return fnameScore;
}

