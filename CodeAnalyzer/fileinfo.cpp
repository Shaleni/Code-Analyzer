#include "fileinfo.h"


FileInfo::FileInfo(){
    codeLines=0;
    commentLines=0;
}

FileInfo::FileInfo(const char * path){
    filePath = path;
    determineName();
    countCodeLines();
    countCommentLines();
}

void FileInfo::setPath(const char* fullPath){
    filePath = fullPath;
}

String FileInfo::getPath(){
    return filePath;
}

void FileInfo::determineName(){
    int loc=filePath.size()-1;

    while (filePath[loc]!='/'){
        loc-=1;
    }

    fileName = filePath.substring(loc+1, filePath.size());
}

String FileInfo::getName(){
    return fileName;
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
    } else {
        cout<<"Error. File failed to open"<<endl;
    }
    fin.close();

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
    cout << commentLines <<endl;
}

int FileInfo::getCodeLines(){
    return codeLines;
}
int FileInfo::getCommentLines(){

    return commentLines;
}
