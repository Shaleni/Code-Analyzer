#ifndef LOC
#define LOC
#include "metrics.h"

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class Loc:public Metric{
private:
    int score;
protected:

public:
    Loc();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);

};

#endif // LOC

