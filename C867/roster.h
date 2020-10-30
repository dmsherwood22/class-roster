//
//  roster.h
//  C867
//
//  Created by Devon M Sherwood on 10/16/20.
//
#ifndef roster_h
#define roster_h
#include "student.h"

class Roster {
   public:
    Roster();
    
    /* Extract student data from studentData Table using commas as delimiters */
    void parseData(string studentData);
    
    /* Set Student object with parsed info and add them to roster */
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);
    
    /* Remove student from roster by their Student ID */
    void remove(string studentID);
    
    /* Print list of all student data in Roster */
    void printAll();
    
    /* Print a student's average day in the 3 courses */
    void printAverageDaysInCourse(string studentID);
    
    /* Verfies student email addresses and print any invalid emails */
    void printInvalidEmails();
    
    /* Prints out student information for specific degree program */
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    string getStudentID(int num) const;
    
    ~Roster();
    
    Roster(const Roster& origRoster);
    
    Roster& operator=(const Roster& objToCopy);
   
   private:
    int studentArrayNum = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
};


#endif /* roster_h */
