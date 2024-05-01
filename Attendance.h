#include <iostream>
using namespace std;
#ifndef ATTENDANCE_H
#define ATTENDANCE_H

class Attendance
{
    protected:
        int* status;
        int* date;
    public:
        Attendance();
        void markAttendance(int _status, int _date);
        void generateAttendanceReport(int startDate, int endDate);
};



#endif