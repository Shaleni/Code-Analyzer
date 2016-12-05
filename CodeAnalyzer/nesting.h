#ifndef NESTING
#define NESTING

#include "metrics.h"
#include "vector.h"

//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
class Nesting:public Metric{
private:
    int score;
    Vector<int> fileScores;
    int worstScore;
    String worstFile;
protected:

public:
    Nesting();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate (const char *);

    void prepareOutput ();

};

#endif // NESTING

