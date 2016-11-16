//Abstract metrics class
class Metrics {
private:

protected:

public:
    virtual void printToFile();
};

void Metrics::printToFile(){


}
//Class to determine the the proportion of code in main vs elsewhere in the project
//Inherits from abstract class Metrics
class codeInMain:public Metrics{
private:

protected:

public:
    void printToFile(){}

};

//Class to determine the quality of comments in the project
//Inherits from abstract class Metrics
class comments:public Metrics{
private:

protected:

public:
    void printToFile(){}

};

//Class to determine the variable name quality in the project
//Inherits from abstract class Metrics
class variables:public Metrics{
private:

protected:

public:
    void printToFile(){}

};

//Class to determine the nesting (control statement quality) in the project
//Inherits from abstract class Metrics
class nesting:public Metrics{
private:

protected:

public:
    void printToFile(){}

};

//Class to determine the lines of code per file in the project
//Inherits from abstract class Metrics
class loc:public Metrics{
private:

protected:

public:
    void printToFile(){}

};
