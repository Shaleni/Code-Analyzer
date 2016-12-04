#ifndef VARIABLES
#define VARIABLES
#include "metrics.h"

//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
class Variables:public Metric{
private:
    int score;
    Vector<String> classNames;
protected:

public:
    Variables();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);

};

#endif // VARIABLES

