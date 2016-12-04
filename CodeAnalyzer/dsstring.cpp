#include "dsstring.h"
#include "vector.h"

//Constructors
String::String () {
    len=0;
    chars = new char [len+1];
    chars[len]=0;
}

String::String(const char* str) {
    //Determine the length of the string
    int count=0;
    while (str[count]!=0) {
        count++;
    }
    len=count;

    //Copy the old values into the new object
    chars = new char [len+1];

    for (int i=0; i<len;i++) {
        chars[i]=str[i];
    }

    //Null terminator
    chars[len]=0;
}

//Copy Constructor
String::String(const String& rhs){

    //@TODO Check if null

    len=rhs.len;
    chars = new char[len+1];

    //Null Terminator
    chars [len] = 0;
    //Fill new object with values from the old
    for (int i=0; i<len;i++) {
        chars[i]=rhs.chars[i];
    }
}

/*Functions*/

using namespace std;
//Split Function
Vector<String> String::split(char splitChar) {
    Vector<String> substrings;
    char * word = new char [100];
    int wordIndex = 0;
    for (int i=0; i<=len;i++) {
        if (chars[i]==splitChar || chars[i]==0){
            //Set null terminator
            word[wordIndex]=0;
            //Make into String
            String makeString (word);
            //Add to vector
            substrings.add(makeString);

            delete[] word;
            word =new char[30];
            wordIndex = 0;
            //word[0]=0;
        }
        else {
            word[wordIndex]=chars[i];
            wordIndex++;
        }
    }
    if (word[0]!=0) {
        substrings.add(String(word));

    }
    delete [] word;
    return substrings;
}


//Size Function
int String::size() const {return len;}

//Substring Function
//INCLUSIVE of first parameter, EXCLUSIVE of second
String String::substring(int start, int end) const {
    //Handle Negative start and end
    if (start<0){
        start =  start+len;
    }
    if (end<0) {
        end = end +len;
    }

    //Load create new string and fill with values
    char * c = new char [end - start +1 ];
    c[end-start]=0;

    for (int i=start;i<end;i++) {
        c[i-start]=chars[i];
    }

    String ret (c);
    delete[]c;

    return ret;
}

//Return as C String
const char* String::c_str(){
    //Only returns the pointer.
    return chars;}

//Make all characters upper case
void String::toUpperCase() {
    for (int i=0; i<len;i++) {
        chars[i]=toupper(chars[i]);

    }
}
//Make all characters lower case
void String::toLowerCase(){
    for (int i=0; i<len;i++) {
        chars[i]=tolower(chars[i]);
    }
}

/* Operators */

//Subscript Operator
char& String::operator[](const int index) const {
    //@TODO: Gracefully handle out of bounds errors

    if (index < 0) { //If given a negative index, work from the right side backwards
        return chars[index+len];
    }

    return chars[index];
}

//Assignment Operators

String& String::operator= (const String& rhs){
    if (this != &rhs) { //Check self assignment
        if (rhs.chars != NULL) { //Check null pointer

            //Clear storage space of current object
            delete [] chars;

            //Copy size and allocate new array
            len=rhs.len;
            chars = new char [len+1];

            //Null terminator
            chars [len]= 0;

            //Copy values
            strcpy(chars, rhs.chars);
        }
    }

    return *this;
}
String& String::operator=(const char * rhs)
{
    //@TODO: Don't forget self-assignment problem and null pointers

    if (rhs!=NULL) {
        delete[] chars;

        //Find the length of rhs
        int count = 0;
        while (rhs[count]!=0) {
            count++;
        }
        len=count;
        chars = new char[len+1];

        //Null terminator
        chars[len]=0;

        //Fill new object with values from the old
        strcpy(chars, rhs);
        return *this;
    }

    return *this;
}

//Addition Operators

String String::operator+ (const String& rhs) const {
    char * newchars = new char [(len + rhs.len + 1)];

    //Load characters from current object
    for (int i=0; i<len; i++) {
        newchars[i]=chars[i];
    }
    //Load characters from right hand side
    for (int k=0;k<rhs.len;k++) {
        newchars [len+k] = rhs.chars[k];
    }
    //Set null terminator
    newchars[(len + rhs.len)] = 0;

    String retstr (newchars);

    delete newchars;
    return retstr;
}
String String::operator+ (const char* rhs) const{
    int rhslen = strlen(rhs);

    char * newchars = new char [(len + rhslen + 1)];

    //Load characters from the current object
    for (int i=0; i<len; i++) {
        newchars[i]=chars[i];
    }
    //Load characters from the right hand side
    for (int k=0;k<rhslen;k++) {
        newchars [len+k] = rhs[k];
    }
    //Set null terminator
    newchars[(len + rhslen)] = 0;

    String retstr (newchars);

    delete [] newchars;
    return retstr;
}

//Comparison Operators

//Uses strcmp and therefore is case-sensitive
bool String::operator==(const String& rhs) const {
    //@TODO: Check null pointers?

    if (strcmp(rhs.chars,chars)==0){
        return true;
    }

    return false;
}
//Uses strcmp and therefore is case-sensitive
bool String::operator==(const char * rhs) const {
    //@TODO: Check null pointers?

    if (strcmp(rhs,chars)==0){
        return true;
    }

    return false;
}

//Greater Than Operator
//Uses strcmp and therefore is case-sensitive
bool String::operator> (const String& rhs) const{
    if ( strcmp(chars,rhs.chars)>0){
        return true;
    }
    return false;
}
//Uses strcmp and therefore is case-sensitive
bool String::operator> (const char* rhs) const{
    if ( strcmp(chars,rhs)>0){
        return true;
    }
    return false;
}

//Less Than Operator
//Uses strcmp and therefore is case-sensitive
bool String::operator< (const String& rhs) const{
    if ( strcmp(chars,rhs.chars)<0){
        return true;
    }
    return false;
}
//Uses strcmp and therefore is case-sensitive
bool String::operator< (const char* rhs) const{
    if ( strcmp(chars,rhs)<0){
        return true;
    }
    return false;
}

bool String::operator!=(const String & rhs) const {
    return (!(*this==rhs));
}
bool String::operator!=(const char * rhs) const {
    return (!(this->chars==rhs));
}

//Ostream Operator
std::ostream& operator<<( std::ostream &os, const String &s) {
    return os << s.chars;
}

//Destructor
String::~String(){
    if (chars != 0) {
        delete[] chars;
    }
}

