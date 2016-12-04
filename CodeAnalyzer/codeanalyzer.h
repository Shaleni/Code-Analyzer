#ifndef CODEANALYZER
#define CODEANALYZER

#define NUM_METRICS 5

#include "metrics.h"

class CodeAnalyzer {
public:
    CodeAnalyzer();
    void runMetrics (const char *);
    void writeOutput (const char *, bool);

private:

    void readDirectory (const char *);
    int isDir(const char*);

    Metric * metrics [NUM_METRICS];


};


#endif // CODEANALYZER

