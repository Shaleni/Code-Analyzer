#ifndef METRICS
#define METRICS

#include <fstream>
#include "dsstring.h"
#include "vector.h"

using namespace std;
//Abstract metrics class
class Metric {
private:
    int score;
protected:

public:
    virtual void printToFileShort(ofstream&)=0;
    virtual void printToFileVerbose(ofstream&)=0;
    virtual void evaluate(const char *)=0;
};






#endif // METRICS

