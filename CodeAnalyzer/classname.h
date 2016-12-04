#ifndef CLASSNAME
#define CLASSNAME
#include "metrics.h"

//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
class ClassName:public Metric{
private:
    int score;
    int scoreTracker[6];
    Vector<String> classNames;
    void generateScore();

    int evaluateClassName(String);
protected:

public:
    ClassName();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);
};

#endif // CLASSNAME

