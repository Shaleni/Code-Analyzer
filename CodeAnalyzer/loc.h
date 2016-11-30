#ifndef LOC
#define LOC
#include "metrics.h"

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class Loc:public Metric{
private:

protected:

public:
    Loc();
    void printToFileShort();
    void printToFileVerbose();

};

#endif // LOC

