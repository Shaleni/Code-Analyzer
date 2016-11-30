#ifndef CODEANALYZER
#define CODEANALYZER

class CodeAnalyzer {
public:
    CodeAnalyzer();
    void runMetrics (const char *);

private:
    void readDirectory (const char *);
    int isDir(const char*);


};


#endif // CODEANALYZER

