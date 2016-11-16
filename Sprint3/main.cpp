#include <iostream>
#include <fstream>
#include <DSString.h>
#include <queue.h>
#include <vector.h>

using namespace std;

void radixSort(Vector<String>& strings, int offset, int maxlen, Queue<String> * buckets){
    if (offset <=maxlen){
        //Add all strings to buckets
        for (int i=0;i<strings.size();i++){
            //Force null bucket
            if (strings[i].size()<offset)buckets[0].enqueue(strings[i]);
            else buckets[(int)strings[i][-offset]].enqueue(strings[i]);
        }

        strings.clear();

        //Dequeue all queues in order
        for (int j=1;j<128;j++){
            while (!buckets[j].isEmpty()){
                strings.add(buckets[j].dequeue());
            }
        }
        radixSort(strings, ++offset, maxlen, buckets);
    }
}

int sasint (char* s){
    int val = 0;
    int i=0;
    while (s[i]!=0){
        val *=10;
        val += (s[i]-48);
        // cout << val <<endl;
        i++;
    }
    return val;
}

int main(int argc, char* const argv[]){
    if (argc!=3){
        cout << "Incorrect number of arguments" <<endl;
        return 1;
    }

    //buffer
    char* buffer = new char[100];

    ifstream readFile;
    readFile.open(argv[1]);

    int number_of_solutions;
    int length_of_file;
    int max_word_length =0;

    if (readFile.is_open()){

        //First line contains length of file
        readFile.getline(buffer, 100);

    }
    length_of_file = sasint(buffer);

    //Create vector of words
    Vector<String> words (length_of_file);

    if(readFile.is_open()){
        //Second line contains length of solution list
        readFile.getline(buffer, 100);
        number_of_solutions = sasint(buffer);

        //Read in the words
        for (int i=0; i<length_of_file;i++){
            readFile >> buffer;
            String currentLine = buffer;
            words.add(currentLine);
            //Update max length
            if (currentLine.size()>max_word_length) max_word_length=currentLine.size();
        }
        readFile.close();
    }
    else cout << "Failed to open file" << endl;
    delete[] buffer;

     //Create buckets
    Queue<String> buckets[128];

    //Sort the vector
    radixSort(words,1,max_word_length, buckets);

    for (int j=0; j<128;j++){
        while (!buckets[j].isEmpty()){
            words.add(buckets[j].dequeue());
        }
    }

    String temp = words[0];
    words.remove(0);
    words.add(temp);

    //Write output file



    ofstream out;
    out.open(argv[2]);
    if (out.is_open()){
        for (int i=0; i<number_of_solutions; i++){
            out << words[i] <<endl;
        }
        out.close();
    }
    else cout << "Failed to write output file" <<endl;

    return 0;
}
