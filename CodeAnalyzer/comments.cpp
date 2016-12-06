//Class to determine the quality of comments in the project
//Inherits from abstract class Metrics

#include "comments.h"
#include "fileinfo.h"

//construtor
Comments::Comments(){
    percentageCode = 0;
    percentageComments = 0;
    codeLines=0;
    commentLines=0;
}

//Prints the short analysis to the file
void Comments::printToFileShort(ofstream& out){
    prepareOutput();
    out << "Comment Quality" <<endl;
    out << "Score: " << score <<endl <<endl;
}

//Prints the verbose analysis to the file
void Comments::printToFileVerbose(ofstream& out){
    prepareOutput();
    out << "Comment Quality" <<endl;
    out << "Score: " << score <<endl;

    out << "Lines of code: " << codeLines <<endl;
    out << "Lines of comments: " << commentLines <<endl;

    out << "Percentage code: " << (percentageCode*100)<<"%" <<endl;
    out << "Percentage comments: " << (percentageComments*100) <<"%" <<endl <<endl;
}

void Comments::evaluate(const char * filePath){

    //Get FileInfo, which will include the number of lines of code and of comments
    FileInfo info (filePath);

    //Add lines of code and comments in the current file to the total
    codeLines += info.getCodeLines();
    commentLines += info.getCommentLines();
}

void Comments::prepareOutput() {
    //total lines does not include #include or #define directives
    totalLines = codeLines+commentLines;

    //Avoids divide by zero error
    if (totalLines!=0){
        percentageCode = double (codeLines)/totalLines;
        percentageComments = double (commentLines)/totalLines;
    }    
    //If the denominator is zero, set the percentage to -1
    else {
        percentageCode = -1;
        percentageComments = -1;
    }

    //Scoring table
    if (percentageComments>.6)          score=5;
    else if (percentageComments>.5)     score=2;
    else if (percentageComments>.4)     score=1;
    else if (percentageComments<.05)    score=5;
    else if (percentageComments<.1)     score=4;
    else if (percentageComments<.15)    score=3;
    else if (percentageComments<.2)     score=2;
    else if (percentageComments<.25)    score=1;
    else                                score=0;
}
