#ifndef CODEINMAIN
#define CODEINMAIN
#include "metrics.h"
#include "dsstring.h"

/* Scoring:
    5 - 75+% in main
    4 - 50-75%
    3 - 20-50%
    2 - 5-20%
    1 - 2-5%
    0 - 0-2% */

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
    void calculatePercent();
    void determineScore();

};

#endif // CODEINMAIN

