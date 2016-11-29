#include <iostream>
#include <dirent.h>
#include <dsstring.h>
#include <sys/stat.h>
//#include <boost/filesystem.hpp>
//#include <boost/foreach.hpp>
//#include <boost/system/system_error.hpp>



using namespace std;


int isDir(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void readDirectory (const char * loc){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (loc)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0){
                //Don't do anything with directories named "." or ".." to avoid infinite loops
            }
            else{
                String fileDir (loc);
                fileDir = fileDir + "/" + String(ent->d_name);
                //cout << isDir(fileDir.c_str()) << ": " <<fileDir <<endl;
                if (isDir(fileDir.c_str())){
                    readDirectory (fileDir.c_str());
                }
                else{
                    //Run the metrics on the file here

                }
            }
        }
        closedir (dir);
    } else {
        cout << "Failed to open directory." <<endl;
    }
}

int main( int argc, char* const argv[] )
{
    if (argc==2){
        //cout << "Analyzing Directory: " << argv [1] <<endl;
        readDirectory(argv[1]);

    }
    else {
        cout << "Incorrect number of arguments. Please enter a single fully-qualified path name." <<endl;
    }
    return 0;
}



