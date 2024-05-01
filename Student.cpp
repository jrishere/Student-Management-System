#include "Student.h"
#include "Attendance.h"
#include "Grades.h"
#include <iostream>
using namespace std;

Student::Student()
{
    studentName = "null";
}

Student::Student(string _studentName, string _studentEmail, string* _studentSchedule, int _studentID):Attendance(), Grades()
{
    studentName = _studentName;
    studentEmail = _studentEmail;
    studentSchedule = _studentSchedule;
    studentID = _studentID;
}

void Student::setStudentName(string _studentName)
{
    studentName = _studentName;
}

void Student::setStudentEmail(string _studentEmail)
{
    studentEmail = _studentEmail;
}

void Student::updateSchedule(string* _studentSchedule)
{
    studentSchedule = _studentSchedule;
}

void Student::setStudentID(int _studentID)
{
    studentID = _studentID;
}

string Student::getStudentName()
{
    return studentName;
}

string Student::getStudentEmail()
{
    return studentEmail;
}

string* Student::getStudentSchedule()
{
    return studentSchedule;
}

int Student::getStudentID()
{
    return studentID;
}