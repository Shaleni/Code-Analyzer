#include "fileinfo.h"


FileInfo::FileInfo(){
    lines=0;
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

void FileInfo::determineLines(){
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

    lines=count;
}

int FileInfo::getLines(){
    return lines;
}
