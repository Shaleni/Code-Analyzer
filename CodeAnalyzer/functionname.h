#ifndef FUNCTIONNAME
#define FUNCTIONNAME
#include "metrics.h"

//Class to determine the function name quality in the project
//Inherits from abstract class Metrics
class FunctionName:public Metric{
private:
    int score;
    int scoreTracker[6];
    Vector<String> functionNames;
    void generateScore();

    int evaluateFunctionName(String);
protected:

public:
    FunctionName();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);
};


#endif // FUNCTIONNAME

