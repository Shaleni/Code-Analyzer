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
    prepareOutput();
    out << "Code Depth" << endl;
    out << "Score: " << score <<endl<<endl;
}

//Prints the verbose analysis to the file
void Nesting::printToFileVerbose(ofstream& out){
    prepareOutput();
    out << "Code Depth" << endl;
    out << "Score: " << score <<endl;
    out << "Deepest level in project: " << (worstScore+4) <<endl;
    out << "In file: " <<worstFile <<endl;
    out << endl;
}

void Nesting::evaluate(const char * path){
    int nestScore;
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

    //Score the individual file and add to vector of all scores
    nestScore = (deepestNesting-4) > 0 ? (deepestNesting-4):0;
    fileScores.add(nestScore);

    //Check if worst file
    if (nestScore>worstScore){
        worstScore=nestScore;
        worstFile = path;
    }

}

void Nesting::prepareOutput(){
    int total=0;
    //Average the squared scores
    for (int i=0;i<fileScores.size();i++){
        fileScores[i]*=fileScores[i];
        total+=fileScores[i];
    }
    //Divide total by the number of files
    score = total/fileScores.size();

}


