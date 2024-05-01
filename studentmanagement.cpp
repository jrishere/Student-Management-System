#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "Teacher.cpp"
#include "Student.cpp"
#include "Class.h"
#include "Class.cpp"
#include "Attendance.h"
#include "Attendance.cpp"
#include "Grades.h"
#include "Grades.cpp"
using namespace std;

int main()
{
    int choice;
    Student students[1000]; // creates each array for students teachers and classes
    Teacher teachers[1000];
    Class classes[4];
    
    do
    {
        std::cout << endl << "Student Management System" << endl; // presents the menu
        std::cout << "========================" << endl;
        std::cout << "Select an option:" << endl;
        std::cout << "-----------------" << endl;
        std::cout << "1. Edit/View Students" << endl;
        std::cout << "2. Edit/View Teachers" << endl;
        std::cout << "3. View Classes" << endl;
        std::cout << "4. View/Edit Attendance" << endl;
        std::cout << "5. View/Edit Grades" << endl;
        std::cout << "0. Exit" << endl;
        std::cout << "-----------------" << endl << endl;
        cin >> choice;
        if(choice == 1)
        {
            int studentChoice;
            std::cout << endl << "Select an option:" << endl; // menu for students
            std::cout << "-----------------" << endl;
            std::cout << "1. View students" << endl;
            std::cout << "2. Add students" << endl;
            std::cout << "3. Edit students" << endl;
            std::cout << "-----------------" << endl << endl;
            cin >> studentChoice;
            if(studentChoice == 1) // prints out each students' info
            {
                for(int i = 0; i < 10; i++)
                {
                    if(students[i].getStudentName() != "null")
                    {
                        cout << "Name: " << students[i].getStudentName() << ", Email: " << students[i].getStudentEmail() << ", ID: " << students[i].getStudentID() << endl << "Classes: " << endl;
                        for(int j = 0; j < 4; j++)
                        {
                            cout << j+1 << ". " << students[i].getStudentSchedule()[j] << endl;
                        }
                        cout << endl;
                    }
                }
            }
            if(studentChoice == 2) // gets all the info for each student when you add a student
            {
                string sName;
                string sEmail;
                string clas;
                int id;
                std::cout << "Enter the student\'s name: " << endl;
                std::cin >> sName;
                std::cout << "Enter " << sName << "\'s email: " << endl;
                std::cin >> sEmail;
                string* classes;
                std::cout << "Enter " << sName << "'s schedule in order" << endl;
                std::cout << "-----------------" << endl << "1. Math" << endl << "2. Science" << endl << "3. History" << endl << "4. English"<< endl << "-----------------" << endl;
                classes = new string[4];
                if(classes == NULL)
                {
                    cout << "Error: memory could not be allocated";  
                }
                else{
                    for(int i = 0; i < 4; i++)
                    {
                        std::cin >> clas;
                        classes[i] = clas;
                    }
                }
                cout << "What is " << sName << "\'s student ID?" << endl;
                cin >> id;
                for(int i = 0; i < 1000; i++)
                {
                    if(students[i].getStudentName() == "null")
                    {
                        students[i] = Student(sName, sEmail, classes, id);
                        break;
                    }
                }
                delete [] classes;
            }
            if(studentChoice == 3) // edits each student
            {
                std::cout << "Select a student to edit: " << endl;
                int studentEditing;
                for(int i = 0; i < 1000; i++)
                {
                    if(students[i].getStudentName() != "null")
                        std::cout << i+1 << ". " << students[i].getStudentName() << endl;
                }
                cin >> studentEditing;
                int editingChoice;
                cout << endl << "-----------------" << endl;
                cout << "1. Edit " << students[studentEditing-1].getStudentName() << "\'s name" << endl; // menu to choose which info to edit for each student
                cout << "2. Edit " << students[studentEditing-1].getStudentName() << "\'s email" << endl;
                cout << "3. Swap " << students[studentEditing-1].getStudentName() << "\'s classes" << endl;
                cout << "4. Edit " << students[studentEditing-1].getStudentName() << "\'s ID" << endl;
                cout << "-----------------" << endl;                
                cin >> editingChoice;
                if(editingChoice == 1)
                {
                    string newName;
                    cout << "Enter a new name for " << students[studentEditing-1].getStudentName() << endl; // change name
                    cin >> newName;
                    students[studentEditing-1].setStudentName(newName);
                }
                else if(editingChoice == 2)
                {
                    string newEmail;
                    cout << "Enter a new email for " << students[studentEditing-1].getStudentName() << endl; // change email
                    cin >> newEmail;
                    students[studentEditing-1].setStudentEmail(newEmail);
                }
                else if(editingChoice == 3)
                {
                    int swap1;
                    int swap2;
                    string temp;
                    cout << "Select 2 classes to swap: " << endl;
                    for(int j = 0; j < 4; j++)
                    {
                        cout << j+1 << ". " << students[studentEditing-1].getStudentSchedule()[j] << endl;
                    }
                    cin >> swap1;
                    cin >> swap2;
                    swap1 -= 1;
                    swap2 -= 1;
                    temp = students[studentEditing-1].getStudentSchedule()[swap1];
                    string* newSched;
                    newSched = new string[4];
                    for(int i = 0; i < 4;i++)
                    {
                        newSched[i] = students[studentEditing-1].getStudentSchedule()[i];
                    }
                    newSched[swap1] = newSched[swap2]; // this swaps each class for the student
                    newSched[swap2] = temp;
                    students[studentEditing-1].updateSchedule(newSched); // updates the new schedule for the student with the swapped classes
                    delete [] newSched;
                }
                else if(editingChoice == 4)
                {
                    int newID;
                    cout << "Enter a new ID for " << students[studentEditing-1].getStudentName() << endl; // edits the ID for the student
                    cin >> newID;
                    students[studentEditing-1].setStudentID(newID);
                }

            }
        }
        if(choice == 2)
        {
            int teacherChoice;
            std::cout << endl << "Select an option:" << endl; // menu for teachers
            std::cout << "-----------------" << endl;
            std::cout << "1. View teachers" << endl;
            std::cout << "2. Add teachers" << endl;
            std::cout << "3. Edit teachers" << endl;
            std::cout << "-----------------" << endl << endl;
            cin >> teacherChoice;
            if(teacherChoice == 1) // prints out all the info for the teacher
            {
                for(int i = 0; i < 10; i++)
                {
                    if(teachers[i].getTeacherName() != "null")
                    {
                        cout << "Name: " << teachers[i].getTeacherName() << ", Email: " << teachers[i].getTeacherEmail() << ", ID: " << teachers[i].getTeacherID() << endl << "Subject Taught: " << teachers[i].getTeacherSubjects() << endl;
                        cout << endl;
                    }
                }                
            }
            if(teacherChoice == 2) // gets all the info to create a new teacher
            {
                string tName;
                string tEmail;
                string subject;
                int id;
                std::cout << "Enter the teacher\'s name: " << endl; 
                std::cin >> tName;
                std::cout << "Enter " << tName << "\'s email: " << endl;
                std::cin >> tEmail;
                std::cout << "Enter " << tName << "'s subject they are teaching: " << endl;
                std::cout << "-----------------" << endl << "1. Math" << endl << "2. Science" << endl << "3. History" << endl << "4. English"<< endl << "-----------------" << endl;
                cin >> subject;
                cout << "What is " << tName << "\'s teacher ID?" << endl;
                cin >> id;
                for(int i = 0; i < 1000; i++)
                {
                    if(teachers[i].getTeacherName() == "null")
                    {
                        teachers[i] = Teacher(tName, tEmail, subject, id);
                        break;
                    }
                }              
            }
            if(teacherChoice == 3) // edits a teacher
            {
                std::cout << "Select a teacher to edit: " << endl;
                int teacherEditing;
                for(int i = 0; i < 1000; i++)
                {
                    if(teachers[i].getTeacherName() != "null")
                        std::cout << i+1 << ". " << teachers[i].getTeacherName() << endl;
                }
                cin >> teacherEditing;
                int editingChoice;
                cout << endl << "-----------------" << endl;
                cout << "1. Edit " << teachers[teacherEditing-1].getTeacherName() << "\'s name" << endl;
                cout << "2. Edit " << teachers[teacherEditing-1].getTeacherName() << "\'s email" << endl;
                cout << "3. Edit " << teachers[teacherEditing-1].getTeacherName() << "\'s subject" << endl;
                cout << "4. Edit " << teachers[teacherEditing-1].getTeacherName() << "\'s ID" << endl;
                cout << "-----------------" << endl;                
                cin >> editingChoice;
                if(editingChoice == 1) // edits name for teacher
                {
                    string newName;
                    cout << "Enter a new name for " << teachers[teacherEditing-1].getTeacherName() << endl;
                    cin >> newName;
                    teachers[teacherEditing-1].setTeacherName(newName);
                }
                else if(editingChoice == 2) // edits email for teacher
                {
                    string newEmail;
                    cout << "Enter a new email for " << teachers[teacherEditing-1].getTeacherName() << endl;
                    cin >> newEmail;
                    teachers[teacherEditing-1].setTeacherEmail(newEmail);
                }
                else if(editingChoice == 3) // edits subject for teacher
                {
                    string newSubject;
                    cout << "Enter a new subject for " << teachers[teacherEditing-1].getTeacherName() << endl;
                    std::cout << "-----------------" << endl << "1. Math" << endl << "2. Science" << endl << "3. History" << endl << "4. English"<< endl << "-----------------" << endl;
                    cin >> newSubject;
                    teachers[teacherEditing-1].setTeacherSubjects(newSubject);
                }
                else if(editingChoice == 4) // edits ID for teacher
                {
                    int newID;
                    cout << "Enter a new ID for " << teachers[teacherEditing-1].getTeacherName() << endl;   
                    cin >> newID;
                    teachers[teacherEditing-1].setTeacherID(newID);
                }
            }
        }
        if(choice == 3) // creates each class
        {
            string mathTeacher;
            string scienceTeacher;
            string historyTeacher;
            string englishTeacher;
            for(int i = 0; i < 4; i++)
            {
                if(teachers[i].getTeacherSubjects() == "Math")
                {
                    mathTeacher = teachers[i].getTeacherName();
                }
                else if(teachers[i].getTeacherSubjects() == "Science")
                {
                    scienceTeacher = teachers[i].getTeacherName();
                }
                else if(teachers[i].getTeacherSubjects() == "History")
                {
                    historyTeacher = teachers[i].getTeacherName();
                }
                else if(teachers[i].getTeacherSubjects() == "English")
                {
                    englishTeacher = teachers[i].getTeacherName();
                }
            }
            string* allStudents;
            allStudents = new string[1000];
            for(int j = 0; j < 1000; j++) // adds every student to a class
            {
                if(students[j].getStudentName() != "null")
                    allStudents[j] = students[j].getStudentName();
                else
                    allStudents[j] = "null";
            }
            classes[0] = Class("Math", mathTeacher, allStudents, 1);
            classes[1] = Class("Science", scienceTeacher, allStudents, 2);
            classes[2] = Class("History", historyTeacher, allStudents, 3);
            classes[3] = Class("English", englishTeacher, allStudents, 4); // creates the classes
            int subjectChoice;
            std::cout << endl << "Select an option:" << endl; // allows the user to input a subject
            std::cout << "-----------------" << endl;
            std::cout << "Select a subject" << endl;
            std::cout << "-----------------" << endl << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << i + 1 << ". " <<  classes[i].getClassName() << endl;
            }

            cin >> subjectChoice; // prints all the info 
            cout << "Class Name: " << classes[subjectChoice - 1].getClassName() << ", Teacher: " << classes[subjectChoice - 1].getClassTeacher() << ", Class ID: " << classes[subjectChoice - 1].getClassID() <<endl <<  "Students: " << endl;
            for(int i = 0; i < 1000; i++)
            {
                if(students[i].getStudentName() != "null")
                    cout << i + 1 << ". " << students[i].getStudentName();
            }
            delete [] allStudents;
        }
        if(choice == 4) // mark or view attendance
        {
            int date;
            int chooseStudent;
            int status;
            cout << "-----------------" << endl;
            cout << "Choose a student to generate or mark attendance" << endl;
            cout << "-----------------" << endl;
            for(int i = 0; i < 1000; i++)
            {
                if(students[i].getStudentName() != "null")
                {
                    cout << i + 1 << ". " << students[i].getStudentName() << endl;
                }
            }
            cin >> chooseStudent;
            int attenChoice;
            cout << "-----------------" << endl; // attendance menu
            cout << "1. Mark Attendance" << endl;
            cout << "2. Generate Attendance Report" << endl;
            cout << "-----------------" << endl;
            cin >> attenChoice;
            if(attenChoice == 1) // marks a students attendance
            {
                cout << "Specify a date (MonthDay)" << endl;
                cout << "-----------------" << endl;
                cin >> date;
                cout << "-----------------" << endl;
                cout << "Choose an option:" << endl;
                cout << "1. Present" << endl;
                cout << "2. Tardy" << endl;
                cout << "3. Absent" << endl;
                cout << "-----------------" << endl;
                cin >> status;
                status -= 1;
                students[chooseStudent-1].markAttendance(status, date);
                cout << "Attendance marked for "<<students[chooseStudent-1].getStudentName();
            }
            if(attenChoice == 2) // generates an attendance report for the student
            {
                int startDate;
                int endDate;
                cout << "Enter a start date: " << endl;
                cin >> startDate;
                cout << "Enter an end date: " << endl;
                cin >> endDate;
                students[chooseStudent-1].generateAttendanceReport(startDate, endDate);
            }
        }
        if(choice == 5)
        {
            int chooseStudent;
            cout << "-----------------" << endl; // prints out a list of students to choose from to see grades
            cout << "Choose a student to see grade average or add grades" << endl;
            cout << "-----------------" << endl;
            for(int i = 0; i < 1000; i++)
            {
                if(students[i].getStudentName() != "null")
                {
                    cout << i + 1 << ". " << students[i].getStudentName() << endl;
                }
            }
            cin >> chooseStudent;
            int gradeChoice;
            cout << "-----------------" << endl; // menu for grades
            cout << "1. View Grade Average" << endl;
            cout << "2. Add grades" << endl;
            cout << "-----------------" << endl;
            cin >> gradeChoice;

            if(gradeChoice == 1) // prints out the average for the grade
            {
                cout << "Average: " << students[chooseStudent - 1].calculateClassGrade();
            }
            string assignment;
            int grade;
            if(gradeChoice == 2) // adds an assignment and its corresponding grade
            {
                cout << "-----------------" << endl;
                cout << "Enter name of assignment: " << endl;
                cout << "-----------------" << endl;
                cin >> assignment;
                cout << "-----------------" << endl;
                cout << "Enter grade of assignment: " << endl;
                cout << "-----------------" << endl; 
                cin >> grade;
                students[chooseStudent-1].submitAssignment(assignment, grade);              
            }


        }

    }
    while(choice != 0);
    std::cout << "Goodbye!" << endl;
    return 0;
}

