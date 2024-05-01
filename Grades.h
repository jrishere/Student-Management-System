#include <iostream>
using namespace std;

#ifndef GRADES_H
#define GRADES_H

class Grades
{
    protected:
        string* assignments;
        int* grades;
    public:
        Grades();
        void submitAssignment(string assignment, int grade);
        float calculateClassGrade();
};

#endif