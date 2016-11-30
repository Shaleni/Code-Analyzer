#ifndef CODEINMAIN
#define CODEINMAIN
#include "metrics.h"
#include "dsstring.h"

/* Scoring:
    0 - 75+% in main
    1 - 50-75%
    2 - 20-50%
    3 - 5-20%
    4 - 2-5%
    5 - 0-2% */

using namespace std;

class CodeInMain:public Metric{
private:
    int linesInMain;
    int totalLines;
    double percent;
    int score;

protected:

public:
    CodeInMain();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);
};




#endif // CODEINMAIN

