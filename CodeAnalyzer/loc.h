#ifndef LOC
#define LOC
#include "metrics.h"

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class loc:public Metrics{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();

};

#endif // LOC
