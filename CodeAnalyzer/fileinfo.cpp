#include "fileinfo.h"


FileInfo::FileInfo(){
    codeLines=0;
    commentLines=0;
    fileScore=0;
}

FileInfo::FileInfo(const char * path){
    codeLines=0;
    commentLines=0;
    filePath = path;
    determineName();
    determineExtension();

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
    int loc=filePath.size()-1;
    while (filePath[loc]!='.'){
        loc-=1;
    }
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
    } else {
        cout<<"Error. File failed to open"<<endl;
    }


    codeLines=count;

}

void FileInfo::countCommentLines(){
    int count=0;
    char current;
    char previous;
    fstream fin;
    fin.open(filePath.c_str());

    //count the number of lines in a file. a line is counted for every ; and {
    if (fin.is_open()){
        //read file character by character.
        while (fin>>current){
            if (current=='/' && previous=='/'){
                count++;

            }
            else{

            }
            previous = current;
        }
        fin.close();
    } else {
        cout<<"Error. File failed to open"<<endl;
    }

    commentLines=count;
    //cout << commentLines <<endl;
}


