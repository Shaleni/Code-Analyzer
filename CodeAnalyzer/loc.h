#ifndef LOC
#define LOC
#include "metrics.h"
#include "fileinfo.h"
#include "cmath"

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class Loc:public Metric{
private:
    //population means (from SAS)
    const double Pmh = 3.2465;
    const double Pmcpp = 4.5481;
    const double Pmc = 4.4394;
    const double Pmhpp = 3.4497;
    //population standard deviations (from SAS)
    const double Psh = 1.2686;
    const double Pscpp = 1.3736;
    const double Psc = 1.6074;
    const double Pshpp = 1.7677;
    //population sizes
    const unsigned Pnh = 9349;
    const unsigned Pncpp = 5211;
    const unsigned Pnc = 2237;
    const unsigned Pnhpp = 36;

    //significance level 0.05 for 95% CI
    const double alpha = 0.05;

    //tstatistics will be calculated
    double th;
    double tcpp;
    double tc;
    double thpp;

    int score;
    int lines;
    Vector<FileInfo> files;
    Vector<FileInfo> h;
    Vector<FileInfo> c;
    Vector<FileInfo> hpp;
    Vector<FileInfo> cpp;

    void separateByExtension();
    void determineOutliers(Vector<FileInfo>&);
    void welchTTest(Vector<FileInfo>&, const double, const double, const unsigned, double&);
    void setScore(Vector<FileInfo>&, int);
    void insertSorted(FileInfo);
    void prepareData();
    void setMetricScore();
protected:

public:
    Loc();
    void printToFileShort(ofstream&);
    void printToFileVerbose(ofstream&);
    void evaluate(const char *);

};

#endif // LOC

