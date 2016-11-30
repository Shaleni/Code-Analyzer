#include <iostream>
#include "codeanalyzer.h"

using namespace std;

int main( int argc, char* const argv[] )
{
    if (argc==4){
        CodeAnalyzer myAnalyzer;
        myAnalyzer.runMetrics(argv[2]);

    }
    else {
        cout << "Incorrect number of arguments. Please enter a single fully-qualified path name." <<endl;
    }
    return 0;
}



