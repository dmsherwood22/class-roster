//
//  student.cpp
//  C867
//
//  Created by Devon M Sherwood on 10/15/20.
//
#include "student.h"

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    
    for (int i = 0; i < studentArraySize; ++i) {
        this->daysCourse[i] = 0;
    }
    this->degree = DegreeProgram::UNDECLARED;
}

Student::Student(string studentID, string fName, string lName, string email, int age, int daysCourse[], DegreeProgram degree) {
    this->studentID = studentID;
    this->firstName = fName;
    this->lastName = lName;
    this->email = email;
    this->age = age;
    
    for (int j = 0; j < studentArraySize; ++j) {
        this->daysCourse[j] = daysCourse[j];
    }
    this->degree = degree;
}

Student::~Student() {}

string Student::getID() const {  return this->studentID;  }
string Student::getFName() const { return this->firstName;  }
string Student::getLName() const {  return this->lastName;  }
string Student::getEmail() const {  return this->email;  }
int Student::getAge() const {  return this->age;  }
int* Student::getDays() {  return this->daysCourse;  }
DegreeProgram Student::getDegree() const {  return this->degree;  }

void Student::setID(string id) {  this->studentID = id;  }
void Student::setFName(string fName) {  this->firstName = fName;  }
void Student::setLName(string lName) {  this->lastName = lName;  }
void Student::setEmail(string email) {  this->email = email;  }
void Student::setAge(int age) {  this->age = age;  }
void Student::setDaysCourse(int daysCourse[]) {
    for(int k = 0; k < studentArraySize; ++k) {
        this->daysCourse[k] = daysCourse[k];
    }
}
void Student::setDegree(DegreeProgram deg) {  this->degree = deg;  }

void Student::print() {
    cout << "Student ID: " << this->getID() << '\t';
    cout << "First Name: " << this->getFName() << '\t';
    cout << "Last Name: " << this->getLName() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "Days in Course: (";
    for (int i = 0; i < studentArraySize; ++i) {
        if(i == (studentArraySize - 1)) {
            cout << this->getDays()[i] << ")" << '\t';
        }
        else {
            cout << this->getDays()[i] << ", ";
        }
    }
    cout << "Degree Program: " << degreeProgramNames[this->getDegree()] << std::endl;
}
