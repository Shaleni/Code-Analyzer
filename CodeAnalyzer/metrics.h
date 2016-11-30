#ifndef METRICS
#define METRICS

#include <fstream>

using namespace std;
//Abstract metrics class
class Metric {
private:
    int score;
protected:

public:
    virtual Metric()=0;
    virtual void printToFileShort(ofstream&)=0;
    virtual void printToFileVerbose(ofstream&)=0;
    virtual void evaluate(char *)=0;
};






#endif // METRICS

