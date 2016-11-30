#ifndef VARIABLES
#define VARIABLES
#include "metrics.h"

//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
class variables:public Metrics{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();
    int evaulate();

};

#endif // VARIABLES

