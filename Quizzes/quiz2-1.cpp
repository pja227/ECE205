#include <iostream>

using namespace std;

int main() {
    int number;
    char response;

    do {
        cout << "Please input a number: ";
        cin >> number;

        if (number > 0) {
            cout << number << " is positive" << endl;
        } else {
            cout << number << " is negative" << endl;
        }

        cout<< "Do you want to give another input? (y/n): ";
        cin >> response;


    } while (response == 'y' || response == 'Y');
}