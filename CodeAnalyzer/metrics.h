#ifndef METRICS
#define METRICS

#include <fstream>
#include "dsstring.h"
#include "vector.h"

using namespace std;

//Abstract metrics class
//All individual metrics must inherit from this class
class Metric {
private:
    int score;
public:
    virtual void printToFileShort(ofstream&)=0;
    virtual void printToFileVerbose(ofstream&)=0;
    virtual void evaluate(const char *)=0;
    int getScore() {
        return score;
    }
};

#endif // METRICS

