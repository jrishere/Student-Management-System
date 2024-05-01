#include "Teacher.h"

Teacher::Teacher()
{
    teacherName = "null";
}

Teacher::Teacher(string _teacherName, string _teacherEmail, string _teacherSubject, int _teacherID)
{
    teacherName = _teacherName;
    teacherEmail = _teacherEmail;
    teacherSubject = _teacherSubject;
    teacherID = _teacherID;
}

void Teacher::setTeacherName(string _teacherName)
{
    teacherName = _teacherName;
}

void Teacher::setTeacherEmail(string _teacherEmail)
{
    teacherEmail = _teacherEmail;
}

void Teacher::setTeacherSubjects(string _teacherSubject)
{
    teacherSubject = _teacherSubject;
}

void Teacher::setTeacherID(int _teacherID)
{
    teacherID = _teacherID;
}

string Teacher::getTeacherName()
{
    return teacherName;
}

string Teacher::getTeacherEmail()
{
    return teacherEmail;
}

string Teacher::getTeacherSubjects()
{
    return teacherSubject;
}

int Teacher::getTeacherID()
{
    return teacherID;
}




