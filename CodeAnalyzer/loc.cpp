//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
#include "loc.h"
//constructor
Loc::Loc(){
    score=0;
    lines=0;
}

//Prints the short analysis to the file
void Loc::printToFileShort(ofstream&){
    prepareData();
    //setMetricScore();
}

//Prints the verbose analysis to the file
void Loc::printToFileVerbose(ofstream&){
    prepareData();
    //setMetricScore();
    cout<<"Metric: Lines of Code."<<endl;
    cout<<"Score: "<<endl;
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

void Loc::determineOutliers(Vector<FileInfo>& toFindOut){
    //find the median of the code
    int medIndex=0;
    int Q2=0;
    //for an even-length vector, average the two in the middle
    if (toFindOut.size()%2 == 0){
        medIndex = toFindOut.size()/2;
        Q2 = (toFindOut[medIndex].getCodeLines() + toFindOut[medIndex-1].getCodeLines())/2;
    } else {
        medIndex = (toFindOut.size()-1)/2;
        Q2 = toFindOut[medIndex].getCodeLines();
    }

    //find the lower quartile (Q1)
    int Q1=0;
    int Q1index=0;
    //even median index
    if (medIndex%2 == 0){
        Q1index = medIndex/2;
        Q1 = (toFindOut[Q1index].getCodeLines() + toFindOut[Q1index-1].getCodeLines())/2;
    } else {
        Q1index = (medIndex-1)/2;
        Q1 = toFindOut[Q1index].getCodeLines();
    }

    //find the upper quartile (Q3)
    int Q3=0;
    int Q3index=0;
    //even median index
    if (medIndex%2 == 0){
        Q3index = medIndex + (medIndex/2);
        Q3 = (toFindOut[Q3index].getCodeLines() + toFindOut[Q3index-1].getCodeLines())/2;
    } else {
        Q3index = medIndex + ((medIndex-1)/2);
        Q3 = toFindOut[Q3index].getCodeLines();
    }


    //find the IQR
    int iqr = Q3-Q1;

    //find the inner fence for minor outliers
    int innerUFence = Q3 + (iqr*1.5);
    int innerLFence = Q1 - (iqr*1.5);

    //find the outer fence for major outliers
    int outerUFence = Q3 + (iqr*3);
    int outerLFence = Q1 - (iqr*3);

    /* Finding and scoring outliers
       Major outliers get score 5,
       Minor outliers get score 4 */

    //loop through and determine outliers:
    for (int i=0; i<toFindOut.size(); i++){
        //check from low range to high range
        if (toFindOut[i].getCodeLines() <= outerLFence){
            //major outlier
            toFindOut[i].setFileScore(5);
        } else if (toFindOut[i].getCodeLines() <= innerLFence){
            //minor outlier
            toFindOut[i].setFileScore(4);
        } else if (toFindOut[i].getCodeLines() >= outerUFence){
            //major outlier
            toFindOut[i].setFileScore(5);
        } else if (toFindOut[i].getCodeLines() >= innerUFence){
            //minor outlier
            toFindOut[i].setFileScore(4);
        } else {
            //not an outlier, find score
            setScore(toFindOut, i);
        }
    }

}

//use standard deviation to rank files that are not outliers
/* 3+ std deviations away is a 3
 * 2-3 is a 2
 * 1-2 is a 1
 * <1 is a 0 */
void Loc::setScore(Vector<FileInfo> & toFindOut, int index){
    int mean=0;
    double variance=0;
    double stdDev=0;

    //find the mean
    for (int i=0; i<toFindOut.size(); i++){
        mean+=toFindOut[i].getCodeLines();
    }
    mean = mean/toFindOut.size();

    //find the variance
    int sumOfSquares=0;
    for(int j=0; j<toFindOut.size(); j++){
        sumOfSquares += (toFindOut[j].getCodeLines()-mean)*(toFindOut[j].getCodeLines()-mean);
    }
    variance = sumOfSquares/(toFindOut.size()-1);

    //find the standard deviation
    stdDev = sqrt(variance);

    //assign scores
    double difference = abs(toFindOut[index].getCodeLines()-mean);

    //compare to std deviations away starting high
    if (difference >= (stdDev*3)){
        toFindOut[index].setFileScore(3);
    } else if (difference >= (stdDev*2)){
        toFindOut[index].setFileScore(2);
    } else if (difference >= stdDev){
        toFindOut[index].setFileScore(1);
    } else {
        toFindOut[index].setFileScore(0);
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

    //find outliers and score files
    determineOutliers(h);
    determineOutliers(cpp);
    determineOutliers(c);
    determineOutliers(hpp);
}
