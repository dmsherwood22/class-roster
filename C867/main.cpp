//
//  main.cpp
//  C867
//
//  Created by Devon M Sherwood on 10/15/20.
//

#include <iostream>
#include "roster.h"

int main(int argc, const char * argv[]) {
    
    // Header for project information
    cout << "C867 - Scripting & Programming: Applications" << std::endl;
    cout << "Language: C++" << std::endl;
    cout << "Student ID: 000828578" << std::endl;
    cout << "Student Name: Devon Sherwood" << std::endl;
    cout << std::endl;
    
    
    const std::string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Devon,Sherwood,dsherw7@wgu.edu,25,20,40,60,SOFTWARE"};
    
    const int numStudents = 5;
  
    Roster classRoster;
    
    // Parse each student data and add them to roster
    for (int i = 0; i < numStudents; ++i) {
        classRoster.parseData(studentData[i]);
    }
    
    classRoster.printAll();
    cout << std::endl;
    
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    // Get average course days for each student in roster
    for (int i = 0; i < numStudents; ++i) {
        string studentID = classRoster.getStudentID(i);
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << std::endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    cout << std::endl;
    
    classRoster.remove("A3");
    
    return 0;
    
}
