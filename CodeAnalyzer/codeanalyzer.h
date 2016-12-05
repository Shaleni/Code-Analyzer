#ifndef CODEANALYZER
#define CODEANALYZER

#define NUM_METRICS 6

#include "metrics.h"

class CodeAnalyzer {
public:
    CodeAnalyzer();
    void runMetrics (const char *);
    void writeOutput (const char *, bool);
    ~CodeAnalyzer();

private:
    int overallScore;
    Metric * metrics [NUM_METRICS];


    void readDirectory (const char *);
    int isDir(const char*);
    void computeOverallScore();
};


#endif // CODEANALYZER

