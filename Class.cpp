#include "Class.h"

Class::Class()
{}

Class::Class(string _className, string _classTeacher, string* _classStudents, int _classID)
{
    className = _className;
    classTeacher = _classTeacher;
    classStudents = _classStudents;
    classID = _classID;
}

void Class::setClassName(string _className)
{
    className  = _className;
}

void Class::setClassTeacher(string _classTeacher)
{
    classTeacher = _classTeacher;
}

void Class::setClassStudents(string* _classStudents)
{
    classStudents = _classStudents;
}

void Class::setClassID(int _classID)
{
    classID = _classID;
}

string Class::getClassName()
{
    return className;
}

string Class::getClassTeacher()
{
return classTeacher;
}

string* Class::getClassStudents()
{
    return classStudents;
}

int Class::getClassID()
{
    return classID;
}