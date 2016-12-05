//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
#include "nesting.h"
#include "stack.hpp"

using namespace std;

//Constructor
Nesting::Nesting(){

}

//Prints the short analysis to the file
void Nesting::printToFileShort(ofstream& out){
    out << "Printing nesting short" << endl;

}

//Prints the verbose analysis to the file
void Nesting::printToFileVerbose(ofstream& out){
    out << "Printing nesting verbose" << endl;

}

void Nesting::evaluate(const char * path){
    int deepestNesting = 0;
    Stack<char> nestStack;
    char current;
    ifstream fin;
    fin.open (path);
    if (fin.is_open()) {
        while (fin >> current) {
            //If open brace, push onto stack
            if (current=='{') nestStack.push(current);
            //If close brace, pop off stack
            else if (current == '}') nestStack.pop();
            //If not a brace, do nothing
            else{}

            //Update deepest nesting variable
            deepestNesting = deepestNesting > nestStack.size() ? deepestNesting : nestStack.size() ;

        }
    }
    else cout << "Failed to open file." <<endl;

    cout << deepestNesting << endl;
}

/* There should not be excessive use of nesting in a project
 * Excessive meaning: multiple (more than 2) nested if statements
 * More than 4 nested loops of any kind
 */


