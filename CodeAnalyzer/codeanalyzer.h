#ifndef CODEANALYZER
#define CODEANALYZER

#define NUM_METRICS 5

#include "metrics.h"

class CodeAnalyzer {
public:
    CodeAnalyzer();
    void runMetrics (const char *);

private:
    void readDirectory (const char *);
    int isDir(const char*);

    Metric * metrics [NUM_METRICS];


};


#endif // CODEANALYZER

