#ifndef METRICS
#define METRICS
//Abstract metrics class
class Metrics {
private:

protected:

public:
    virtual void printToFileShort(){}
    virtual void printToFileVerbose(){}
    virtual int evaluate(){}
};






#endif // METRICS

