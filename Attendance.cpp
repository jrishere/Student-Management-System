#include <iostream>
#include "Attendance.h"
using namespace std;

Attendance::Attendance()
{
    status = new int[1000];
    date = new int[1000];
    for(int i = 0; i < 1000; i++)
    {
        status[i] = -1;
        date[i] = -1;
    }
    delete[] status;
    delete[] date;
}

void Attendance::markAttendance(int _status, int _date)
{
    for(int i = 0; i < 1000; i++)
    {
        if(status[i] != -1)
        {
            status[i] = _status;
        }
        if(date[i] != -1)
        {
            date[i] = _date;
        }
    }
}

void Attendance::generateAttendanceReport(int startDate, int endDate)
{
    cout << "-----------------" << endl;
    cout << "Attendance Report" << endl;
    cout << "-----------------" << endl;
    cout << startDate;
    for(int i = 0; i < 1000; i++)
    {
        if(date[i] >=  startDate && date[i] <= endDate) // prints out the status for each date, 0 being present, 2 being tardy, 3 being absent
        {
            cout << date[i] << ": ";
            if(status[i] == 0)
                cout << "Present" << endl;
            else if(status[i] == 1)
                cout << "Tardy" << endl;
            else if(status[i] == 2)
                cout << "Absent" << endl; 
            else if(status[i] == -1)
                cout << "Error" << endl; 
            cout << status[i];          
        }

    }
}