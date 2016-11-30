#ifndef NESTING
#define NESTING
#include "metrics.h"
//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
class nesting:public Metrics{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();

};

#endif // NESTING

