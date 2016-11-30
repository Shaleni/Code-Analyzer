#include <iostream>
#include <cstring>
#include "codeanalyzer.h"

using namespace std;

/*  Arguments for main
 *
 * argv[1]: -v or -b flag for verbose or brief output
 * argv[2]: Directory that is root of project
 * argv[3]: location of output file
 */


int main( int argc, char* const argv[] )
{
    if (argc==4){
        //Check for "verbose" flag
        bool verbose = strcmp(argv[1],"-v")==0;

        //Create CodeAnalyzer object and run metrics
        CodeAnalyzer myAnalyzer;
        myAnalyzer.runMetrics(argv[2], argv[3], verbose);
    }
    else {
        cout << "Incorrect number of arguments. Please enter a single fully-qualified path name." <<endl;
    }
    return 0;
}



