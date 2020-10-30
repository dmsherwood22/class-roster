//
//  student.h
//  C867
//
//  Created by Devon M Sherwood on 10/16/20.
//
#include <string>
#include <iostream>
#include "degree.h"

#ifndef student_h
#define student_h

using std::string;
using std::cout;

class Student {
   public:
    const static int studentArraySize = 3;
    // Constructors
    Student();
    Student(string studentID, string fName, string lName, string email, int age, int daysCourse[], DegreeProgram degree);
    
    // Destructor
    ~Student();
    
    Student(const Student& origStudent);
    
    // Getters
    string getID() const;
    string getFName() const;
    string getLName() const;
    string getEmail() const;
    int getAge() const;
    int* getDays();
    DegreeProgram getDegree() const;
    
    // Setters
    void setID(string studentID);
    void setFName(string fName);
    void setLName(string lName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysCourse(int daysCourse[]);
    void setDegree(DegreeProgram deg);
    
    void print();
    
   private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysCourse[studentArraySize];
    DegreeProgram degree;
};

#endif /* student_h */
