/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void printSeats(char seats[10][4]);
bool changeSeat(char seats[10][4], int row, char seat);

int main() {
    char seats[10][4];
    char rows[4] = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            seats[i][j] = rows[j];
        }
    }

    changeSeat(seats, 1, 'B');
    changeSeat(seats, 3, 'D');
    changeSeat(seats, 5, 'A');
    printSeats(seats);

    char next;
    do {
        int row;
        char seat;
        cout << "Enter the row number (1-10) and seat letter (A-D) to change: ";
        cin >> row >> seat;
        
        while (!changeSeat(seats, row, seat)) {
            cout << "Please enter a valid row number (1-10) and seat letter (A-D): ";
            cin >> row >> seat;
        }
        printSeats(seats);

        cout << "Do you want to change another seat? (y/n): ";
        cin >> next;

    } while (next == 'y');


    return 0;
}

void printSeats(char seats[10][4]) {
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << right << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << setw(2) << seats[i][j] << " ";
        }
        cout << endl;
    }
}

bool changeSeat(char seats[10][4], int row, char seat) {
    int seatIndex = seat - 'A';
    if (row >= 1 && row <= 10 && seatIndex >= 0 && seatIndex < 4) {
        if (seats[row - 1][seatIndex] == 'X') {
            cout << "Seat already taken." << endl;
            return false;
        }
        seats[row - 1][seatIndex] = 'X';
        return true;
    } else {
        cout << "Invalid seat selection." << endl;
        return false;
    }
}