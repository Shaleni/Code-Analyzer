#ifndef CODEANALYZER
#define CODEANALYZER

#include "metrics.h"

class CodeAnalyzer {
public:
    CodeAnalyzer();
    void runMetrics (const char *);

private:
    void readDirectory (const char *);
    int isDir(const char*);

    Metric * metrics [5];


};


#endif // CODEANALYZER

