#include <iostream>
#include "codeanalyzer.h"

using namespace std;

int main( int argc, char* const argv[] )
{
    if (argc==2){
        CodeAnalyzer myAnalyzer;
        myAnalyzer.runMetrics(argv[1]);

    }
    else {
        cout << "Incorrect number of arguments. Please enter a single fully-qualified path name." <<endl;
    }
    return 0;
}



