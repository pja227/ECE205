/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void input(int& pounds, int& ounces);
void conversion(int pounds, int ounces, int& kilograms, int& grams);
void output(int kilograms, int grams);

int main() {
    int pounds, ounces, kilograms, grams;
    char userChoice;

    do {
        input(pounds, ounces);
        conversion(pounds, ounces, kilograms, grams);
        output(kilograms, grams);

        cout << "\nWould you like to convert another time? (y/n): ";
        cin >> userChoice;
    } while (userChoice == 'y');
}

void input(int& pounds, int& ounces) {
    cout << "Please input the weight in pounds: ";
    cin >> pounds;
    cout << "Please input the weight in ounces: ";
    cin >> ounces;
}

void conversion(int pounds, int ounces, int& kilograms, int& grams) {
    double totalPounds = pounds + (ounces / 16.0);
    double totalKilograms = totalPounds / 2.2046;
    kilograms = (int) totalKilograms;
    
    double remainderKg = totalKilograms - kilograms;
    grams = (int) (remainderKg * 1000);
}

void output(int kilograms, int grams) {
    cout << "\nConverted weight = " << kilograms << "kg " << grams << "g" << endl;
}
