#ifndef NESTING
#define NESTING
#include "metrics.h"
//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
class Nesting:public Metric{
private:
    int score;
protected:

public:
    Nesting();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate (const char *);

};

#endif // NESTING

