#ifndef COMMENTS
#define COMMENTS
#include "metrics.h"

class Comments:public Metric{
private:

protected:

public:
    void printToFileShort();
    void printToFileVerbose();
    void evaluate (char *);

};


#endif // COMMENTS

