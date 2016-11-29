#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include "vector.h"

class String{

public:
    //Constructors
    String();
    String(const char*);

    String(const String&);

    //Assignment Operators
    String& operator= (const char*);
    String& operator= (const String&);

    //Addition Operators
    String operator+ (const String&) const;
    String operator+ (const char*) const;

    //Comparison Operators
    bool operator== (const char*) const;
    bool operator== (const String&) const;
    bool operator> (const String&) const;
    bool operator> (const char*) const;
    bool operator< (const String&) const;
    bool operator< (const char*) const;
    bool operator!=(const String&) const;
    bool operator!=(const char*) const;

    //Subscript Operator
    char& operator[] (const int) const;

    //Methods
    int size() const;
    String substring(int, int) const;
    const char* c_str();
    void toUpperCase();
    void toLowerCase();
    Vector<String> split(char);

    friend std::ostream& operator<< (std::ostream&, const String&);

    ~String();

private:
    //@TODO: Make unsigned?
    int len;
    char * chars;
};


#endif
