#ifndef FILEINFO
#define FILEINFO

#include "vector.h"
#include "dsstring.h"
#include <fstream>
#include <cmath>

using namespace std;

//class that contains the filePath, the fileName, and the number of lines of
//code in each file

class FileInfo{
private:
    int fileScore;
    int lnFileScore;
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
    void setFileScore(int);
    String getPath();
    String getExtension();
    String getName();

    int getCodeLines();
    int getCommentLines();
    int getFileScore();
    int getLnCodeLines();
};

#endif // FILEINFO

