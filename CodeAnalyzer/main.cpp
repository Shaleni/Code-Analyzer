#include <iostream>

using namespace std;

int main( int argc, char* const argv[] )
{
    if (argc=2){
        cout << "Analyzing Directory: " << argv [1] <<endl;
    }
    else {
        cout << "Incorrect number of arguments. Please enter a single fully-qualified path name." <<endl;
    }
    return 0;
}

