/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void input(int int1, int int2);
void conversion(int int1, int int2, char& AMPM);
void output(int int1, int int2, char AMPM);

int main() {
    int int1, int2;
    char AMPM;

    input(int1, int2);
    conversion(int1, int2, AMPM);
    output(int1, int2, AMPM);
}

void input(int int1, int int2) {
    cout << "Please input the first two digit (0-23): ";
    cin >> int1;
    cout << "Please input the second two digit (0-59): ";
    cin >> int2;
}

void conversion(int int1, int int2, char& AMPM) {
    if (int1 >= 0 && int1 < 24) {
        if (int1 >= 12) {
            AMPM = 'P';
        } else {
            AMPM = 'A';
        }
    } 

    if (int1 == 0) {
        int1 = 12; 
    } else if (int1 > 12) {
        int1 = int1 - 12;
    } 
}

void output(int int1, int int2, char AMPM) {
    if (int2 < 10) {
        cout << "\nTime in 12-hour format = " << int1 << ":0" << int2 << " " << AMPM << "M" << endl;
    } else {
        cout << "\nTime in 12-hour format = " << int1 << ":" << int2 << " " << AMPM << "M" << endl;
    }
}