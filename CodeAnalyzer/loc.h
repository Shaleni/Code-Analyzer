#ifndef LOC
#define LOC
#include "metrics.h"
#include "fileinfo.h"

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class Loc:public Metric{
private:
    int score;
    int lines;
    Vector<FileInfo> files;
    Vector<FileInfo> h;
    Vector<FileInfo> cpp;

    void separateByExtension();
    void determineOutliers();
    void sortByLines();
protected:

public:
    Loc();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);

};

#endif // LOC

