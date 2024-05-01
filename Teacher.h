#include <iostream>
using namespace std;

#ifndef TEACHER_H
#define TEACHER_H

class Teacher
{
    protected:
        string teacherName;
        string teacherEmail;
        string teacherSubject;
        int teacherID;

    public:
        Teacher();
        Teacher(string _teacherName, string _teacherEmail, string teacherSubject, int teacherID);
        void setTeacherName(string _teacherName);
        void setTeacherEmail(string _teacherEmail);
        void setTeacherSubjects(string _teacherSubject);
        void setTeacherID(int _teacherID);
        string getTeacherName();
        string getTeacherEmail();
        string getTeacherSubjects(); 
        int getTeacherID();

};

#endif 