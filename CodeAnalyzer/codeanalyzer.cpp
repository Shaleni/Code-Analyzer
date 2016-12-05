//Libraries
#include <dirent.h>
#include <sys/stat.h>
#include <fstream>

//My header files
#include "codeanalyzer.h"
#include "dsstring.h"
#include "vector.h"

//Include Metrics class and subclasses for each metric
#include "metrics.h"
#include "codeinmain.h"
#include "loc.h"
#include "nesting.h"
#include "classname.h"
#include "comments.h"
#include "functionname.h"

CodeAnalyzer::CodeAnalyzer (){
    //Initialize metrics
    metrics[0] = new CodeInMain;
    metrics[1] = new Loc;
    metrics[2] = new Comments;
    metrics[3] = new ClassName;
    metrics[4] = new Nesting;
    metrics[5] = new FunctionName;
}

void CodeAnalyzer::runMetrics(const char * root) {
    readDirectory (root);
}

void CodeAnalyzer::writeOutput(const char * file, bool verbose){
    computeOverallScore();

    ofstream out;
    out.open(file);
    if (out.is_open()){

        //Print the overall score for the whole project
        out << "Average score: " << overallScore << endl <<endl;

        //Loop over the array of metrics, printing the output each time
        for (int i=0; i<NUM_METRICS;i++){
            //Check if verbose flag has been set
            if (verbose) metrics[i]->printToFileVerbose(out);
            else metrics[i]->printToFileShort(out);
        }
    }
    else cout <<"Unable to open output file" <<endl;
}

int CodeAnalyzer::isDir(const char *path) {
    //Detect if an address is a directory
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) return 0;
    return S_ISDIR(statbuf.st_mode);
}

void CodeAnalyzer::readDirectory (const char * loc){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (loc)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {

            //Create fully qualified filename
            String fullyQualifiedFilename (loc);
            fullyQualifiedFilename = fullyQualifiedFilename + "/" + String(ent->d_name);

            //Split into substrings based on '.' character, then examine final substring
            //Determines if file has a permitted ending: .h .hpp .c .cpp

            Vector<String> splits = String(ent->d_name).split('.');
            String fileExtension = splits[1];

            if (strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0){
                //Don't do anything with directories named "." or ".." to avoid infinite loops
            }
            else if (isDir(fullyQualifiedFilename.c_str())){
                //If path represents a directory, recursively examine that directory
                readDirectory (fullyQualifiedFilename.c_str());
            }
            else if (fileExtension=="h" || fileExtension=="hpp" || fileExtension=="c" || fileExtension=="cpp"){
                //If file is one of the four recognized filetypes
                //Loop through the array of metrics, calling evaluate() for each one
                for (int i=0; i<NUM_METRICS; i++){
                    metrics[i]->evaluate(fullyQualifiedFilename.c_str());
                }
            }
            else{} //Is a non-code file. Do nothing.
        }
        closedir (dir);
    } else std::cout << "Failed to open directory." <<std::endl;

}

void CodeAnalyzer::computeOverallScore(){
    int sumScore=0;

     for (int i=0; i<NUM_METRICS;i++) {
        sumScore+=metrics[i]->getScore();
     }
     overallScore=sumScore/NUM_METRICS;
     cout << overallScore <<endl;
}

CodeAnalyzer::~CodeAnalyzer(){
    for (int i=0; i<NUM_METRICS;i++) delete metrics[i];
}
