#include "Grades.h"
#include <iostream>
using namespace std;

Grades::Grades()
{
    assignments = new string[1000];
    grades = new int[1000];
    for(int i = 0; i < 1000; i++)
    {
        assignments[i] = "null";
        grades[i] = -1;
    }
    delete[] assignments;
    delete[] grades;
}

void Grades::submitAssignment(string assignment, int grade)
{
    for(int i =0; i <1000; i++)
    {
        if(assignments[i] != "null"){
            assignments[i] = assignment;
            grades[i] = grade;
        }
    }
}


float Grades::calculateClassGrade()
{
    int gradesTotal = 0;
    int counter = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(assignments[i] != "null")
        {
            gradesTotal += grades[i];
            counter += 1;
        }
    }
    float avg = gradesTotal/counter;
    return avg;
}

