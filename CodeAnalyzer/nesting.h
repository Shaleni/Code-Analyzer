#ifndef NESTING
#define NESTING
#include "metrics.h"
//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
class Nesting:public Metric{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();
    void evaluate (char *);

};

#endif // NESTING

