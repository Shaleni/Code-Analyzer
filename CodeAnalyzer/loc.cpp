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


}

//Prints the verbose analysis to the file
void Loc::printToFileVerbose(ofstream&){


}

void Loc::evaluate(const char * filePath){
    //create a FileInfo object
    FileInfo currFile (filePath);

    //add to vector of FileInfo objects
    files.add(currFile);

    //fill the vectors by extension
    separateByExtension();

    sortByLines(h);
    sortByLines(cpp);

    //find and score outliers
    determineOutliers();
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

void Loc::determineOutliers(){

}

//edit to sort by lines of code
void Loc::sortByLines(Vector<FileInfo>& toSort){
    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    for (int j = 0; j < len-1; j++) {
        /* find the min element in the unsorted a[j .. n-1] */

        /* assume the min is the first element */
        int iMin = j;
        /* test against elements after j to find the smallest */
        for (int i = j+1; i < len; i++) {
            /* if this element is less, then it is the new minimum */
            if (data[i] < data[iMin]) {
                /* found new minimum; remember its index */
                iMin = i;
            }
        }

        if(iMin != j) {
            swap(j,iMin);
        }
    }
}
