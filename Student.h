#include <iostream>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
#include "Attendance.h"
#include "Grades.h"

class Student: public Attendance, public Grades
{
    private:
        string studentName;
        string studentEmail;
        string* studentSchedule;
        int studentID;
    public:
        Student();
        Student(string _studentName, string _studentEmail, string* _studentSchedule, int studentID);
        void setStudentName(string _studentName);
        void setStudentEmail(string _studentEmail);
        void updateSchedule(string* _studentSchedule);
        void setStudentID(int _studentID);
        string getStudentName();
        string getStudentEmail();
        string *getStudentSchedule();
        int getStudentID();
};

#endif