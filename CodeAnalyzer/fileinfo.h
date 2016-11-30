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
    int codeLines;
    int commentLines;
    String fileName;
    String filePath;
    String fileExtension;

    void countCodeLines();
    void countCommentLines();
    void determineName();
    void determineExtension();

public:
    FileInfo();
    FileInfo (const char *);
    void setPath(const char *);
    String getPath();

    String getName();

    int getCodeLines();
    int getCommentLines();
};

#endif // FILEINFO

