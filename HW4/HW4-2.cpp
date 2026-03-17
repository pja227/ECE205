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
    double difficulty = difficultyInput();
    int judges[7];
    judgesInput(judges);


    /**
     * Insertion sort
     */
    for (int i = 0; i < 7; i++) {
        int key = judges[i];
        int j = i - 1;

        while (j >= 0 && judges[j] > key) {
            judges[j + 1] = judges[j];
            j--;
        }
        judges[j + 1] = key;
    }

    double sum = judges[1] + judges[2] + judges[3] + judges[4] + judges[5];
    double score = sum * difficulty * 0.6;
    cout << fixed << setprecision(2) << "The final score is: " << score << endl;

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
