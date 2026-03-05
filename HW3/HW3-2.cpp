/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void calculate(double length1, double length2, double length3, double& area, double& perimeter);


int main() {
    double length1, length2, length3;
    double area, perimeter;

    cout << "Enter the length of the first side: ";
    cin >> length1;
    cout << "Enter the length of the second side: ";
    cin >> length2;
    cout << "Enter the length of the third side: ";
    cin >> length3;

    calculate(length1, length2, length3, area, perimeter);
}

void calculate(double length1, double length2, double length3, double& area, double& perimeter) {
    if (length1 + length2 <= length3 || length1 + length3 <= length2 || length2 + length3 <= length1) {
        cout << "\nThe lengths you entered cannot form a triangle." << endl;
        return;
    }

    perimeter = length1 + length2 + length3;
    area = sqrt(perimeter * (perimeter - length1) * (perimeter - length2) * (perimeter - length3));
    
    cout << fixed << setprecision(2);
    cout << "\nThe area of the triangle is: " << area << endl;
    cout << "The perimeter of the triangle is: " << perimeter << endl;
}