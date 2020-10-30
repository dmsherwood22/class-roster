//
//  roster.cpp
//  C867
//
//  Created by Devon M Sherwood on 10/15/20.
//
#include "roster.h"

using namespace std;

Roster::Roster() {}

void Roster::parseData(string studentData) {
    // Get student ID
        int commaIndex;
        commaIndex = studentData.find(",");
        string studID = studentData.substr(0, commaIndex);
        
        // Get first name
        int startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string fName = studentData.substr(startIndex, commaIndex - startIndex);
        
        // Get last name
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string lName = studentData.substr(startIndex, commaIndex - startIndex);
        
        // Get email
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string email = studentData.substr(startIndex, commaIndex - startIndex);
        
        // Get age
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string years = (studentData.substr(startIndex, commaIndex - startIndex));
        int age = stoi(years);
        
        // Get Days in Course 1
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string day1 = (studentData.substr(startIndex, commaIndex - startIndex));
        int daysCourse1 = stoi(day1);
        
        // Get Days in Course 2
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string day2 = (studentData.substr(startIndex, commaIndex - startIndex));
        int daysCourse2 = stoi(day2);
        
        // Get Days in Course 3
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string day3 = (studentData.substr(startIndex, commaIndex - startIndex));
        int daysCourse3 = stoi(day3);
        
        // Get Degree Program
        startIndex = commaIndex + 1;
        commaIndex = studentData.find(",", startIndex);
        string degree = (studentData.substr(startIndex, commaIndex - startIndex));
        // Find degree program
        int degreeNum = 0;
        for(int j = 0; j < sizeof(degreeProgramNames); ++j) {
            if ((degree.compare(degreeProgramNames[j])) == 0) {
                degreeNum = j;
                break;
            }
        }
        DegreeProgram degreeProg = DegreeProgram(degreeNum);
        
        // Add student to roster with parsed data
        this->add(studID, fName, lName, email, age, daysCourse1, daysCourse2, daysCourse3, degreeProg);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    // Place days in course into array needed for student object
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    // Create new student object and add them to next spot in array
    ++studentArrayNum;
    classRosterArray[studentArrayNum] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
    
}

void Roster::remove(string studentID) {
    if (studentArrayNum > -1) {
        // Track if student with ID found in roster
        int foundStudent = 0;
        
        for (int i = 0; i <= studentArrayNum; ++i) {
            string tempID = classRosterArray[i]->getID();
            
            // Check for student with corresponding ID in roster
            if (tempID.compare(studentID) == 0) {
                ++foundStudent;
                for(int j = i; j < studentArrayNum; ++j) {
                    classRosterArray[j] = classRosterArray[j + 1];
                }
                --studentArrayNum;
            }
        }
        
        // Error message if student not found in roster
        if (foundStudent == 0) {
            cout << "Student with ID " << studentID << " not found in roster." << endl;
        }
    }
    else {
        cout <<  "No students in roster" << endl;
    }
    
}

void Roster::printAll() {
    cout << "Displaying all students: " << endl;
    
    // Error message if no students in roster
    if (studentArrayNum == -1) {
        cout << "Not students found.";
    }
    else{
        // Print data of each student in roster
        for (int i = 0; i <= studentArrayNum; ++i) {
           classRosterArray[i]->print();
        }
    }
}
           

void Roster::printAverageDaysInCourse(string studentID) {
    int foundStudent = 0; // Track if student with ID found in roster
    
    // Look for matching student with studentID in roster
    for (int i = 0; i <= studentArrayNum; ++i) {
        string tempID = classRosterArray[i]->getID();
        
        if (tempID.compare(studentID) == 0) {
            ++foundStudent;
            int totalDays = classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2];
            double avg = totalDays / 3.0;
            cout << "Average days in course for student: " << avg << endl;
            
        }
    }
    // Error message if student not found in roster
    if (foundStudent == 0) {
        cout << "Student with ID " << studentID << " not found in roster" << endl;
    }
}

void Roster::printInvalidEmails() {
    int trackInvalid = 0;
    cout << "Displaying invalid emails: " << endl;
    
    /* Check if email is missing an at symbol (@) or period (.) or includes a space */
    for (int i = 0; i <= studentArrayNum; i++) {
        string tempEmail = classRosterArray[i]->getEmail();
        if ( tempEmail.find('@') == string::npos || tempEmail.find('.') == string::npos || tempEmail.find(' ') != string::npos ) {
            ++trackInvalid;
            
            if (tempEmail.find('@') == string::npos) {
                cout << tempEmail << " - Missing an @ symbol" << endl;
            }
            if (tempEmail.find('.') == string::npos) {
                cout << tempEmail << " - Missing a period" << endl;
            }
            if (tempEmail.find(' ') != string::npos) {
                cout << tempEmail << " - No spaces allowed" << endl;
            }
        }
    }
    
    if (trackInvalid == 0) {
        cout << "No invalid emails found." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Showing students in degree program: ";
    cout << degreeProgramNames[degreeProgram] << endl;
    
    /* Look for students in entered degree program and print students' data */
    for (int i = 0; i <= studentArrayNum ; i++) {
        if (classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

string Roster::getStudentID(int num) const {
    return classRosterArray[num]->getID();
}

Roster::~Roster() {
    cout << "Destructor called." << endl;
    
    for (int i = 0; i < numStudents - 1; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

Roster::Roster(const Roster& origRoster) {
    for (int i = 0; i < numStudents; ++i) {
        classRosterArray[i] = new Student;
        *classRosterArray[i] = *(origRoster.classRosterArray[i]);
    }
}

Roster& Roster::operator=(const Roster& objToCopy) {
    if (this != &objToCopy) {
        for (int i = 0; i < numStudents; ++i) {
            delete classRosterArray[i];
            classRosterArray[i] = new Student;
            *classRosterArray[i] = *(objToCopy.classRosterArray[i]);
        }
    }
    return *this;
}



