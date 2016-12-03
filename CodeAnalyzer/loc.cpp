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

}

//Prints the verbose analysis to the file
void Loc::printToFileVerbose(ofstream&){
    prepareData();

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
        } else{
            cpp.add(files[i]);
        }
    }
}

void Loc::determineOutliers(Vector<FileInfo>& toFindOut){
    //find the median of the code
    int Q2;
    //for an even-length vector, average the two in the middle
    if (toFindOut.size()%2 == 0){
        Q2 = ((toFindOut[(toFindOut.size()/2)-1].getCodeLines()+toFindOut[(toFindOut.size()/2)].getCodeLines())/2);
    } else {
        Q2 = toFindOut[(toFindOut.size()-1/2)].getCodeLines();
    }

    //find the lower quartile (Q1)
    int Q1;
    //even-length vector
    if (toFindOut.size()%2 == 0){
        Q1 = (toFindOut[((toFindOut.size()/2)/2)-2].getCodeLines() + toFindOut[((toFindOut.size()/2)/2)-1].getCodeLines())/2;
    } else {
        Q1 = (toFindOut[(((toFindOut.size()-1)/2)/2)].getCodeLines() + toFindOut[(((toFindOut.size()-1)/2)/2)-1].getCodeLines())/2;
    }

    //find the upper quartile (Q3)
    int Q3;


    //find the IQR
    //int iqr = Q3-Q1;

    //find the inner fence for minor outliers
    int innerUFence = Q3 + (IQR*1.5);
    int innerLFence = Q1 - (IQR*1.5);

    //find the outer fence for major outliers
    int outerUFence = Q3 + (IQR*3);
    int outerLFence = Q1 - (IQR*3);

    /* Finding and scoring outliers
       Major outliers get score 5,
       Minor outliers get score 4 */

    //loop through and determine outliers:


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

    for(int k = 0; k<files.size(); k++){
        cout<<"Sorted Vector\n";
        cout<<"lines of code: "<<files[k].getCodeLines()<<endl;
    }
}

void Loc::prepareData(){
    //fill the vectors by extension
    separateByExtension();

    //find and score outliers
    determineOutliers(h);
    determineOutliers(cpp);
}
