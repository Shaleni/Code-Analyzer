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

class codeInMain:public Metrics{
private:
    int linesInMain;
    int totalLines;
    double percent;

protected:

public:
    void printToFileShort();
    void printToFileVerbose();
    void evaluate(char *);
};




#endif // CODEINMAIN

