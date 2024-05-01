#include <iostream>
using namespace std;

#ifndef CLASS_H
#define CLASS_H

class Class
{
    protected:
        string className;
        string classTeacher;
        string* classStudents;
        int classID;
    public:
        Class();
        Class(string _className, string _classTeacher, string* _classStudents, int classID);
        void setClassName(string _className);
        void setClassTeacher(string _classTeacher);
        void setClassStudents(string* _classStudents);
        void setClassID(int _classID);
        string getClassName();
        string getClassTeacher();
        string* getClassStudents();
        int getClassID();
};

#endif