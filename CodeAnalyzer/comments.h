#ifndef COMMENTS
#define COMMENTS
#include "metrics.h"

class Comments:public Metric{
private:
    int score;
protected:

public:
    Comments();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate (const char *);

};


#endif // COMMENTS

