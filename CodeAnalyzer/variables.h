#ifndef VARIABLES
#define VARIABLES
#include "metrics.h"

//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
class Variables:public Metric{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();
    void evaulate(char *);

};

#endif // VARIABLES

