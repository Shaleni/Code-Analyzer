#include "codeanalyzer.h"
#include "dsstring.h"
#include <dirent.h>
#include <sys/stat.h>
#include "vector.h"

CodeAnalyzer::CodeAnalyzer (){

}

void CodeAnalyzer::runMetrics(const char * root) {
    readDirectory (root);
}

int CodeAnalyzer::isDir(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void CodeAnalyzer::readDirectory (const char * loc){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (loc)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            //Create fully qualified filename
            String fullyQualifiedFilename (loc);
            fullyQualifiedFilename = fullyQualifiedFilename + "/" + String(ent->d_name);

            //Split into substrings based on '.' character, then examine final substring
            //Determines if file has a permitted ending: .h .hpp .c .cpp
            Vector<String> splits = String(ent->d_name).split('.');
            String fileExtension = splits[1];

            if (strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0){
                //Don't do anything with directories named "." or ".." to avoid infinite loops
                //std::cout << "Has a period." << std::endl;
            }
            else if (isDir(fullyQualifiedFilename.c_str())){
                //If path represents a directory, recursively examine that directory
                readDirectory (fullyQualifiedFilename.c_str());
            }
            else if (fileExtension=="h" || fileExtension=="hpp" || fileExtension=="c" || fileExtension=="cpp"){
                std::cout << fullyQualifiedFilename <<std::endl;


                //Run metrics


            }
            else{
                //Is a non-code file. Do nothing.
            }
        }
        closedir (dir);
    } else {
        std::cout << "Failed to open directory." <<std::endl;
    }
}
