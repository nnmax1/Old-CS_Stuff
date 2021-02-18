#ifndef _GRADEBOOK_HPP_
#define  _GRADEBOOK_HPP_


#include <vector>
#include <string>
#include <unordered_map> //to access hash table template class in STL
//string to string std::pair
typedef std::pair<std::string, std::string> pair;
//string to int pair
typedef std::pair<std::string, int> intPair;

//Student data type
struct Student {
    std::string id;
    std::string fname, lname;   
    int abs, grade;
};

class Gradebook {
    public:
    //empty default constructor
    Gradebook();
    //Init gradebook object w/ a filename 
    Gradebook(std::string);
    //does same as overloaded connstructor
    void setGradebook(std::string);
    //update gradebook w/ data sorted, class avg, and std deviation. 
    void updateGradebook();
private:
    //filename of original gradebook
    std::string filename;
    //string to string hash tables
    std::unordered_map<std::string, std::string> hashfName, hashlName, hashFull;
    //vectors of key-value pairs
    std::vector<pair> studentsLname, studentsFname, studentsFull, grades, absences, letterGrades;
    //string to int hash tables
    std::unordered_map<std::string, int>hashGrades,hashAbs;
    std::vector<std::string> titles;
    //vector<intPair> 
    std::vector<intPair>studentGrades, studentAbs;
    std::vector<double>statistics;
    double classAvg=0, stdDev=0;
    //sort methods
    void sortByValue(std::vector<pair>&);
    void sortIntsUp(std::vector<intPair>&);
    void sortIntsDown(std::vector<intPair>&) ;
    void sortById(std::vector<pair>&);
    //retrieve data from file
    void getData(std::unordered_map<std::string, std::string> &h, char) ;
    void getData(std::unordered_map<std::string,int>&, char) ;
    //write data
    void writeData( std::vector<std::vector<pair>>);
    //adjust vector if needed.
    void adjustVector(std::vector<pair>&, std::unordered_map<std::string, std::string> ) ;
    //convert vector<intPair> to vector<pair>
    std::vector<pair> convertVector(std::vector<intPair>, std::unordered_map<std::string, std::string>);
    //calculate class average
    double calcAverage() ;
    //calculate standard deviation
    double calcStdDev(double) ;
    //get letter grade
    std::string getGrade(int) ;
    //assign letter grades to student
    void assignLetterGrades(std::vector<intPair> ) ;
};

#endif