#include "fileinfo.h"

FileInfo::FileInfo(){
    //Initalize values
    codeLines=0;
    commentLines=0;
    fileScore=0;
}

FileInfo::FileInfo(const char * path){
    //Initialize values
    codeLines=0;
    commentLines=0;
    fileScore = 0;
    filePath = path;

    //Call private function to initialize further values
    determineName();
    determineExtension();

    //Count code and comment lines when object is created
    countCodeLines();
    countCommentLines();
}

void FileInfo::setPath(const char* fullPath){
    filePath = fullPath;
}

String FileInfo::getPath(){
    return filePath;
}

String FileInfo::getName(){
    return fileName;
}

int FileInfo::getCodeLines(){
    return codeLines;
}
int FileInfo::getCommentLines(){
    return commentLines;
}

void FileInfo::determineName(){
    int loc=filePath.size()-1;
    while (filePath[loc]!='/'){
        loc-=1;
    }
    fileName = filePath.substring(loc+1, filePath.size());
}

void FileInfo::determineExtension(){
    //Beginning at the end of the filename loops backwards until a period is found
    int loc=filePath.size()-1;
    while (filePath[loc]!='.'){
        loc-=1;
    }
    //Returns everything from the period to the end of the string
    fileExtension = filePath.substring(loc+1, filePath.size());
}

String FileInfo::getExtension(){
    return fileExtension;
}

void FileInfo::countCodeLines(){
    int count=0;
    char ch;
    fstream fin;
    fin.open(filePath.c_str());

    //count the number of lines in a file. a line is counted for every ; and {
    if (fin.is_open()){
        //read file character by character.
        while (fin>>ch){
            if (ch==';' || ch=='{'){
                count++;
            }
        }
        fin.close();
    } else cout<<"Error. File failed to open"<<endl;

    codeLines=count;
}

void FileInfo::countCommentLines(){
    int count=0;
    fstream fin;
    fin.open(filePath.c_str());

    //Track the current and previous character
    //Need to detect two-character sequences: /* and //
    char current, previous;

    if (fin.is_open()){
        //read file character by character.
        while (!fin.eof()){
            current = fin.get();
            if (current=='/' && previous=='/'){
                //If a double slash is reached, increment count by one
                count++;
                previous = current;
            }
            else if (previous == '/' && current=='*'){
                /*
                 * If the beginning of a comment block is reached,
                 * count the number of newlines encountered until the end of the block
                 */
                previous = current;

                while (!fin.eof()){
                    current = fin.get();

                    //Increment count for each newline
                    if (current == '\n') count++;

                    //Reached the end of the block
                    else if (previous == '*' && current == '/') {
                        //Increment count one last time
                        //Accounts for the final line of the code block
                        count++;
                        break;
                    }
                    else{} //Continue Loop
                    previous = current;
                }
            }
            else previous = current;
        }
        fin.close();
    } else {
        cout<<"Error. File failed to open"<<endl;
    }

    commentLines=count;
}

void FileInfo::setFileScore(int setScore){
    fileScore = setScore;
}

int FileInfo::getFileScore(){
    return fileScore;
}

int FileInfo::getLnCodeLines(){
    return log(codeLines);
}
