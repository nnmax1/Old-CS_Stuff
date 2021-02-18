#include "gradebook.hpp"
#include <fstream>
#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <math.h>
    Gradebook::Gradebook() {
        filename = "nofile";
    }
    Gradebook::Gradebook(std::string f) {
        filename = f;
        titles = {"Sorted by first name","Sorted by last name","Sorted by highest to lowest grade", "Sorted by least to most absences","Sorted by id number"};
        //get data and store into hash tables
        getData(hashfName, 'F');
        getData(hashlName, 'L');
        getData(hashFull, 'f');
        getData(hashGrades, 'g');
        getData(hashAbs, 'a');
        //use std::copy to hash tables to vectors 
        //I do this b/c I use std::sort() which sorts a vector by using the std::vector iterators
        std::copy(hashfName.begin(), hashfName.end(),std::back_inserter<std::vector<pair>>(studentsFname));
        std::copy(hashlName.begin(), hashlName.end(),std::back_inserter<std::vector<pair>>(studentsLname));
        std::copy(hashFull.begin(), hashFull.end(),std::back_inserter<std::vector<pair>>(studentsFull));
        std::copy(hashGrades.begin(), hashGrades.end(),std::back_inserter<std::vector<intPair>>(studentGrades));
        std::copy(hashAbs.begin(), hashAbs.end(),std::back_inserter<std::vector<intPair>>(studentAbs));
        //class avg and std dev.
        classAvg = calcAverage();
        stdDev = calcStdDev(classAvg);
        statistics = {classAvg, stdDev};
    }
    void Gradebook::setGradebook(std::string f) {
        filename = f;
        titles = {"Sorted by first name","Sorted by last name","Sorted by highest to lowest grade", "Sorted by least to most absences","Sorted by id number"};
        //get data and store into hash tables
        getData(hashfName, 'F');
        getData(hashlName, 'L');
        getData(hashFull, 'f');
        getData(hashGrades, 'g');
        getData(hashAbs, 'a');
        //use std::copy to hash tables to vectors 
        //I do this b/c I use std::sort() which sorts a vector by using the std::vector iterators
        std::copy(hashfName.begin(), hashfName.end(),std::back_inserter<std::vector<pair>>(studentsFname));
        std::copy(hashlName.begin(), hashlName.end(),std::back_inserter<std::vector<pair>>(studentsLname));
        std::copy(hashFull.begin(), hashFull.end(),std::back_inserter<std::vector<pair>>(studentsFull));
        std::copy(hashGrades.begin(), hashGrades.end(),std::back_inserter<std::vector<intPair>>(studentGrades));
        std::copy(hashAbs.begin(), hashAbs.end(),std::back_inserter<std::vector<intPair>>(studentAbs));
        //class avg and std dev.
        classAvg = calcAverage();
        stdDev = calcStdDev(classAvg);
        statistics = {classAvg, stdDev};
    }
   //call this function to create a new gradebook with updated information
    void Gradebook::updateGradebook() {
        if(filename == "nofile") {
            std::cout<<"Could not get data from gradebook.\n";
            std::cout<<"exiting w/ code 1\n";
            exit(1); 
        }
        //sort vectors
        sortByValue(studentsFname);
        sortByValue(studentsLname);
        sortById(studentsFull);
        sortIntsUp(studentGrades);
        sortIntsDown(studentAbs);
        assignLetterGrades(studentGrades);
        //adjust studentsFname and studentsLname to include full student names (first + last name)
        adjustVector(studentsFname, hashFull);
        adjustVector(studentsLname, hashFull);
        grades = convertVector(studentGrades, hashFull);
        absences = convertVector(studentAbs, hashFull);
        //class avg and std dev.
        classAvg = calcAverage();
        stdDev = calcStdDev(classAvg);
        statistics = {classAvg, stdDev};
        //write sorted data to new file
        std::vector<std::vector<pair>> data = {studentsFname, studentsLname, grades, absences, studentsFull};
         writeData(data);
    }
    

//sort vector<pair> in ascending order
void Gradebook::sortByValue(std::vector<pair> &stu) {
	std::sort(stu.begin(), stu.end(),
			[](const pair& l, const pair& r) {
				if (l.second != r.second)
					return l.second < r.second;

				return l.first < r.first;
		    });
}
//sort vector<pair> in ascending order
void Gradebook::sortIntsUp(std::vector<intPair> &stu) {
	std::sort(stu.begin(), stu.end(),
			[](const intPair& l, const intPair& r) {
				if (l.second != r.second)
					return l.second > r.second;

				return l.first > r.first;
		    });
}
//sort vector<pair> in descending order
void Gradebook::sortIntsDown(std::vector<intPair> &stu) {
	std::sort(stu.begin(), stu.end(),
			[](const intPair& l, const intPair& r) {
				if (l.second != r.second)
					return l.second < r.second;

				return l.first < r.first;
		    });
}
void Gradebook::sortById(std::vector<pair> &stu) {
    std::sort(stu.begin(), stu.end(),
		[](const pair& l, const pair& r) {
			if (l.first != r.first)
				return l.first < r.first;
			return l.second < r.second;
		});
}
//get data and store in hash table
void Gradebook::getData(std::unordered_map<std::string, std::string> &h, char choice) {
    std::ifstream read;
    read.open(filename);
    if(read.fail()){std::cout<<"students.info file failed to open for reading. exited w/ code 1.\n"; exit(1);}

    while(!read.eof()) {
        Student s;
        read >> s.id >> s.fname>>s.lname;
        read >> s.grade >> s.abs;
        if(choice == 'F'){
            h[s.id] = s.fname;
        }else if(choice == 'L') {
            h[s.id] = s.lname;
        }else if(choice == 'f') {
            h[s.id] = s.fname + " " + s.lname + " " + std::to_string(s.grade)+ " " + std::to_string(s.abs);
        }
    }
    read.close();    
}
//get data and store in hash table
void Gradebook::getData(std::unordered_map<std::string, int> &h, char choice) {
    std::ifstream read;
    read.open(filename);
    if(read.fail()){std::cout<<"students.info file failed to open for reading. exited w/ code 1.\n"; exit(1);}

    while(!read.eof()) {
        Student s;
        read >> s.id >> s.fname>>s.lname;
        read >> s.grade >> s.abs;
        if(choice == 'g') {
            h[s.id] = s.grade;
        }else if(choice == 'a') {
            h[s.id] = s.abs;
        }
    }
    read.close();    
}
//write sorted student data to a new file
void Gradebook::writeData(std::vector< std::vector<pair> > data) {
    std::ofstream write;
    write.open("new_"+filename);
    if(write.fail()){std::cout<<"File failed to open for writing. exited w/ code 1.\n"; exit(1);}
    int i=0;
    for(auto v : data) {
        write<<"--------------------------------------\n";
        write<<titles[i++]<<"\n";
        write<<"--------------------------------------\n";
        int i=0;
        for (auto const &pair: v) {
		    write<<pair.first<<" "<<pair.second<<" ";
            for(auto g : letterGrades) {
                if(g.first == pair.first) {
                    write<<g.second<<"\n";
                }
            }
	    }

    }
        write<<"--------------------------------------\n";
    write<<"Statistics: \n";
    write<<"Class Average: "<<statistics[0]<<"\n";
    write<<"Standard Deviation: "<<statistics[1]<<"\n";
    write.close();
}

//add first or last names if necessary
void Gradebook::adjustVector(std::vector<pair>&stu, std::unordered_map<std::string, std::string> h ) {
  for(auto &pair : stu) {
    std::string key = pair.first;    
    pair.second = h[key];
   }
}
std::vector<pair> Gradebook::convertVector(std::vector<intPair>stu, std::unordered_map<std::string, std::string> h ) {
  std::vector<pair>res;
  for(auto &e : stu) {
    pair p;
    p.first = e.first;    
    p.second = h[p.first];
    res.push_back(p);
   }
   return res;
}

double Gradebook::calcAverage() {
    int total=0;
    int i=0;
    for(auto &p : hashGrades) {
        total += hashGrades[p.first];
        i++;
    }
    return total/i;
}
double Gradebook::calcStdDev(double avg) {
    double total=0, i=0;
    for(auto &p : hashGrades) {
        total += pow(hashGrades[p.first] - avg, 2);
        i++;
    }
    return sqrt(total / i);
}
std::string Gradebook::getGrade(int grade) {
    if(grade == 100) return "A+";
    else if(grade <100 && grade > 93) return "A";
    else if(grade <= 93 && grade >= 90) return "A-";
    else if(grade <= 90 && grade >= 87) return "B+";
    else if(grade <= 87 && grade >= 83) return "B";
    else if(grade <= 83 && grade >= 80) return "B-";
    else if(grade <= 80 && grade >= 77) return "C+";
    else if(grade <= 77 && grade >= 73) return "C";
    else if(grade <= 73 && grade >= 70) return "C-";
    else if(grade <= 70 && grade >= 67) return "D+";
    else if(grade <= 67 && grade >= 63) return "D";
    else if(grade <= 63 && grade >= 60) return "D-";
    else return "F";
}
void Gradebook::assignLetterGrades(std::vector<intPair> grades) {
    pair p;
    for(auto g: grades) {
        p.first = g.first;
        p.second = getGrade(g.second);
        letterGrades.push_back(p);
    }

}
