//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
#include "classname.h"

//Constructors
ClassName::ClassName(){
    score=0;
    //initialize scoreTracker to 0
    for (int i=0; i<6; i++){
        scoreTracker[i]=0;
    }

}


//Prints the short analysis to the file
void ClassName::printToFileShort(ofstream& out){
    generateScore();
    out <<"Class Name Quality" <<endl;
    out<<"Score: "<<score<<endl;
    out<<endl;
}

//Prints the verbose analysis to the file
void ClassName::printToFileVerbose(ofstream& out){
    generateScore();
    out <<"Class Name Quality" <<endl;
    out<<"Overall score: "<<score<<endl;
    out<<"Score breakdown: "<<endl;
    out<<"Number of class names that scored a 0: "<<scoreTracker[0]<<endl;
    out<<"Number of class names that scored a 1: "<<scoreTracker[1]<<endl;
    out<<"Number of class names that scored a 2: "<<scoreTracker[2]<<endl;
    out<<"Number of class names that scored a 3: "<<scoreTracker[3]<<endl;
    out<<"Number of class names that scored a 4: "<<scoreTracker[4]<<endl;
    out<<"Number of class names that scored a 5: "<<scoreTracker[5]<<endl;
    out<<endl;
}

void ClassName::evaluate(const char * filePath){


    //variable to hold a line of code
    char codeBlock[100];
    char className[100];

    fstream fin;
    fin.open(filePath);

    if (fin.is_open()){
        while (!fin.eof()){
            fin>>codeBlock;
            String comment;
            if (codeBlock[0]=='/' && codeBlock[1]=='*'){
                //open comment
                do{
                    fin>>codeBlock;
                    comment=codeBlock;
                    while(comment.size()<2){
                        fin>>codeBlock;
                        comment=codeBlock;
                    }
                }
                while (comment[comment.size()-1]!='/' && comment[comment.size()-2]!='*');
            }

            String cB(codeBlock);
            if (cB == "class"){
                fin>>className;
                String cName(className);
                //remove trailing semicolons
                if (cName[cName.size()-1]==';'){
                    cName = cName.substring(0, cName.size()-1);
                }

                //remove '{'
                if (cName[cName.size()-1]=='{'){
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
                //make sure not a templated one
                if (cName=="class" || cName=="and" || cName=="name" || cName=="names"
                        || cName=="//All" || cName=="extends"){
                    //do nothing
                } else {
                    classNames.add(cName);
                    cout<<cName<<endl;
                }
            }
        }

        fin.close();
    } else {
        cout<<"Error. File failed to open"<<endl;
    }
    //cout << "Class Name" <<endl;

}

/* Go through each class nameT and score it. Count the number
 * of each score type in an int array, with the index being the
 * score */
//consider using a somewhat trivial hashtable instead of an array
void ClassName::generateScore(){
    int nameScore = 0;
    //loop through vector of class names
    for (int i=0; i<classNames.size(); i++){
        nameScore = evaluateClassName(classNames[i]);
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
int ClassName::evaluateClassName(String cname){
    int cnameScore=0;
    //check if it starts with an uppercase letter
    String firstLetter(cname);
    firstLetter.toLowerCase();
    if (firstLetter[0]!=cname[0]){
        //changing to lowercase changed the ascii value
        //this means that the letter must have been uppercase
        //score remains 0
    } else {
        //if the lowercase version equals the first letter,
        //was not capitalized. Add one to the score
        cnameScore++;
    }

    //check the length of the class name
    if (cname.size()>=20){
        //too long, add to the score
        cnameScore++;
    }

    //make sure the class name contains no symbols ($)
    int j=0;
    while (cname[j] != '$' && j<cname.size()){
        j++;
    }
    if(cname[j]=='$'){
        //contains a symbol. increment score
        cnameScore++;
    }

    //make sure the class name contains no numbers
    bool numFlag=false;
    for (int i=0; i<cname.size(); i++){
        if (cname[i]=='0' || cname[i]=='1' || cname[i]=='2' ||
                cname[i]=='3' || cname[i]=='4' || cname[i]=='5' ||
                cname[i]=='6' || cname[i]=='7' || cname[i]=='8' ||
                cname[i]=='9'){
            //contains a number
            numFlag=true;
        }
    }
    if (numFlag){
        //contains a number
        cnameScore++;
    }

    //check for all caps

    return cnameScore;
}

// See txt file for standards on variable name quality
