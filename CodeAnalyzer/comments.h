#ifndef COMMENTS
#define COMMENTS
#include "metrics.h"

class Comments:public Metric{
private:
    //Member variables
    int score;
    int commentLines;
    int codeLines;
    int totalLines;
    double percentageComments;
    double percentageCode;

    //Private member functions
    void prepareOutput();

public:
    //Constructor
    Comments();

    //Public member functions
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate (const char *);
};


#endif // COMMENTS

