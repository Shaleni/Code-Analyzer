//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
#include "loc.h"
//constructor
Loc::Loc(){
    score=0;
    lines=0;
    th = 0;
    tcpp = 0;
    tc = 0;
    thpp = 0;
    dh=dcpp=dc=dhpp=0;
    ph=pcpp=pc=phpp=0;
}

//Prints the short analysis to the file
void Loc::printToFileShort(ofstream& out){
    prepareData();
    setScore();
    out<<"Lines of Code per File"<<endl;
    out<<"Score: " << score <<endl;
    out<<endl;
}

//Prints the verbose analysis to the file
void Loc::printToFileVerbose(ofstream& out){
    prepareData();
    setScore();
    out<<"Lines of Code per File"<<endl;
    out<<"Score: " << score <<endl;
    out<<".h files: "<<endl;
    if (h.size()>=2){
        out<<"p-value: "<< setprecision(3) << scientific << ph<<endl;
        if (ph>0.05){
            out<<"Failed to reject null hypothesis, .h files well designed"<<endl;
        } else {
            out<<"Rejected null hypothesis, .h files poorly designed"<<endl;
        }
    } else {
        out<<"Too few files to do a t-test; need 2 or more of this type"<<endl;
    }
    out<<".cpp files: "<<endl;
    if (cpp.size()>=2){
        out<<"p-value: "<<pcpp<<endl;
        if (pcpp>0.05){
            out<<"Failed to reject null hypothesis, .cpp files well designed"<<endl;
        } else {
            out<<"Rejected null hypothesis, .cpp files poorly designed"<<endl;
        }
    } else {
        out<<"Too few files to do a t-test; need 2 or more of this type"<<endl;
    }
    out<<".c files: "<<endl;
    if (c.size()>=2){
        out<<"p-value: "<<pc<<endl;
        if (pc>0.05){
            out<<"Failed to reject null hypothesis, .c files well designed"<<endl;
        } else {
            out<<"Rejected null hypothesis, .c files poorly designed"<<endl;
        }
    } else {
        out<<"Too few files to do a t-test; need 2 or more of this type"<<endl;
    }
    out<<".hpp files: "<<endl;
    if (hpp.size()>=2){
        out<<"p-value: "<< phpp<<endl;
        if (phpp>0.05){
            out<<"Failed to reject null hypothesis, .hpp files well designed"<<endl;
        } else {
            out<<"Rejected null hypothesis, .hpp files poorly designed"<<endl;
        }
    } else {
        out<<"Too few files to do a t-test; need 2 or more of this type"<<endl;
    }
    out<<endl;
    //get rid of scientific notation
    out<<fixed;
}

void Loc::evaluate(const char * filePath){
    //create a FileInfo object
    FileInfo currFile (filePath);

    //add to vector of FileInfo objects in sorted place
    insertSorted(currFile);
}

void Loc::separateByExtension(){
    //fill the two FileInfo vectors by file extension
    for(int i=0; i<files.size(); i++){
        if (files[i].getExtension()=="h"){
            h.add(files[i]);
        } else if (files[i].getExtension()=="cpp"){
            cpp.add(files[i]);
        } else if (files[i].getExtension()=="c") {
            c.add(files[i]);
        } else {
            hpp.add(files[i]);
        }
    }
}

//use p-values from files to reject/accept null hypothesis and assign score accordingly
//Ho: there is no difference in means between sample and population
//alpha = 0.05
void Loc::setScore(){
    //h file
    if (ph>0.05){
        //FTR - likely due to chance
    } else {
        score++;
    }

    //cpp file
    if (pcpp>0.05){
        //FTR - likely due to chance
    } else {
        score++;
    }

    //c file
    if (pc>0.05){
        //FTR - likely due to chance
    } else {
        score++;
    }

    //cpp file
    if (phpp>0.05){
        //FTR - likely due to chance
    } else {
        score++;
    }
}

//add to files in sorted place
void Loc::insertSorted(FileInfo toSort){
    //use insertion sort to make sure values inserted to files are sorted
    files.add(toSort);
    int temp;
    for (int i=1; i<files.size(); i++){
        int j=i;
        while (j>0 && files[j-1].getCodeLines()>files[j].getCodeLines()){
            temp = files[j].getCodeLines();
            files.swap(j, j-1);
            j--;
        }
    }
}

void Loc::prepareData(){
    //fill the vectors by extension
    separateByExtension();

    //find t-statistics
    //make sure there is more than one file before calculating
    if (h.size()>=2){
        welchTTest(h, Pmh, Psh, Pnh, th, dh, ph);
    } else {
        ph=1;
    }
    if (cpp.size()>=2){
        welchTTest(cpp, Pmcpp, Pscpp, Pncpp, tcpp, dcpp, pcpp);
    } else {
        pcpp=1;
    }
    if (c.size()>=2){
        welchTTest(c, Pmc, Psc, Pnc, tc, dc, pc);
    } else {
        pc = 1;
    }
    if (hpp.size()>=2){
        welchTTest(hpp, Pmhpp, Pshpp, Pnhpp, thpp, dhpp, phpp);
    } else {
        phpp = 1;
    }
}

void Loc::welchTTest(Vector<FileInfo>& toCalculate, const double pMean, const double pStddev, const unsigned pSize, double& tstat, double& dOF, double& pval){
    //sample mean
    double sMean = 0;
    for (int i=0; i<toCalculate.size(); i++){
        sMean += toCalculate[i].getLnCodeLines();
    }
    sMean = sMean/toCalculate.size();

    //sample standard deviation
    double variance = 0;
    double sStddev = 0;
    //find the variance
    double sumOfSquares=0;
    for(int j=0; j<toCalculate.size(); j++){
        sumOfSquares += (toCalculate[j].getLnCodeLines()-sMean)*(toCalculate[j].getLnCodeLines()-sMean);
    }

    variance = sumOfSquares/(toCalculate.size()-1);

    //find the standard deviation
    sStddev = sqrt(variance);

    // Degrees of freedom:
    dOF = pStddev * pStddev / pSize + sStddev * sStddev / toCalculate.size();
    dOF *= dOF;
    double t1 = pStddev * pStddev / pSize;
    t1 *= t1;
    t1 /=  (pSize - 1);
    double t2 = sStddev * sStddev / toCalculate.size();
    t2 *= t2;
    t2 /= (toCalculate.size() - 1);
    dOF /= (t1 + t2);

    // t-statistic:
    tstat = (pMean - sMean) / sqrt(pStddev * pStddev / pSize + sStddev * sStddev / toCalculate.size());

    //use boost
    students_t dist(dOF);
    pval = cdf(complement(dist, fabs(tstat)));
    pval*=2;
}

int Loc::getScore(){
    return score;
}
