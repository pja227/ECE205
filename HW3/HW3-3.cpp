/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void timeDifference(int startTime, int endTime);

int main() {
    int startTime, endTime;

    cout << "\nPlease input the start time in 24-hour notation (0000-2359): ";
    cin >> startTime;
    cout << "Please input the end time in 24-hour notation (0000-2359): ";
    cin >> endTime;

    timeDifference(startTime, endTime);
}

void timeDifference(int startTime, int endTime) {
    int startHour, startMinute, endHour, endMinute;

    startHour = startTime / 100;
    startMinute = startTime % 100;
    endHour = endTime / 100;
    endMinute = endTime % 100;

    int startTotalMinutes = (startHour * 60) + startMinute;
    int endTotalMinutes = (endHour * 60) + endMinute;

    int timeDifference;
    if (endTotalMinutes < startTotalMinutes) {
        timeDifference = (1440 - startTotalMinutes) + endTotalMinutes;
    } else {
        timeDifference = endTotalMinutes - startTotalMinutes;
    }

    cout << "Difference in minutes = " << timeDifference << " minutes" << endl;
}