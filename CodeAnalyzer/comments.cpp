//Class to determine the quality of comments in the project
//Inherits from abstract class Metrics

#include "comments.h"
#include "fileinfo.h"

//construtor
Comments::Comments(){

}

//Prints the short analysis to the file
void Comments::printToFileShort(ofstream&){


}

//Prints the verbose analysis to the file
void Comments::printToFileVerbose(ofstream&){


}

void Comments::evaluate(const char * filePath){
    FileInfo info (filePath);

    codeLines = info.getCodeLines();
    commentLines = info.getCommentLines();
    percentageCode = codeLines/(codeLines+commentLines);
    percentageComments = commentLines/(codeLines+commentLines);

}
