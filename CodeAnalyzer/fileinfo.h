#ifndef FILEINFO
#define FILEINFO

#include "vector.h"
#include "dsstring.h"
#include <fstream>

using namespace std;

//class that contains the filePath, the fileName, and the number of lines of
//code in each file

class FileInfo{
private:
    int lines;
    String fileName;
    String filePath;

public:
    FileInfo();
    void setPath(const char *);
    String getPath();
    void determineName();
    String getName();
    void determineLines();
    int getLines();
};

#endif // FILEINFO

