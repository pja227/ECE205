/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double difficultyInput();
void judgesInput( int arr[] );

int main() {
    double 

}

double difficultyInput() {
    double difficulty;

    cout << "Enter the difficulty level of the dive (between 1.2 and 3.8): ";
    do {
        cin >> difficulty;
        if (difficulty < 1.2 || difficulty > 3.8) {
            cout << "Invalid input. Please enter a difficulty level between 1.2 and 3.8: ";
        }
    } while (difficulty < 1.2 || difficulty > 3.8);

    return difficulty;
}

void judgesInput( int arr[] ) {
    cout << "Enter 7 real numbers between 0 and 10: ";

    for (int i = 0; i < 7; i++) {
        do {
            cin >> arr[i];
            if (arr[i] < 0 || arr[i] > 10) {
                cout << "Invalid input. Please enter a real number between 0 and 10: ";
            }
        } while (arr[i] < 0 || arr[i] > 10);
    }
}
