/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int startTime, endTime, startHour, startMinute, endHour, endMinute, timeDifference;
    char startTimeAMPM, endTimeAMPM;

    cout << "\nPlease input the start time in 24-hour notation (0000-2359): ";
    cin >> startTime;
    cout << "Please input the end time in 24-hour notation (0000-2359): ";
    cin >> endTime;

    if (startTime > 1159 && startTime < 2400) {
        startTimeAMPM = 'P';
    } else {
        startTimeAMPM = 'A';
    }
    
    if (endTime > 1159 && endTime < 2400) {
        endTimeAMPM = 'P';
    } else {        
        endTimeAMPM = 'A';
    }

    startHour = startTime / 100;
    startMinute = startTime % 100;
    endHour = endTime / 100;
    endMinute = endTime % 100;

    if (startHour > 12) {
        startHour = startHour - 12;
    }
    if (endHour > 12) {
        endHour = endHour - 12;
    }

    if (startMinute < 10) {
        cout << "\nStart time in 24-hour format= " << startHour << ":0" << startMinute << " " << startTimeAMPM << "M" << endl;
    } else {
        cout << "Start time in 24-hour format= " << startHour << ":" << startMinute << " " << startTimeAMPM << "M" << endl;
    }

    if (endMinute < 10) {
        cout << "End time in 12-hour format = " << endHour << ":0" << endMinute << " " << endTimeAMPM << "M" << endl;
    } else {
        cout << "End time in 12-hour format = " << endHour << ":" << endMinute << " " << endTimeAMPM << "M" << endl;
    }

    if (startTimeAMPM == 'P') {
        startHour = startHour + 12;
    }
    if (endTimeAMPM == 'P') {
        endHour = endHour + 12;
    }
    timeDifference = ((endHour * 60) + endMinute) - ((startHour * 60) + startMinute);
    cout << "Difference in minutes = " << timeDifference << " minutes" << endl;
}