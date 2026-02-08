#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Problem 1
void partone();
void parttwo();
void partthree();
void partfour();

int main() {
    srand((time(0)));
    partone();
    parttwo();
    partthree();
    partfour();
}

// Problem 1
void partone() {
    // contains mass1, mass2, distance, and the gravitational constant
    double m1, m2, d;
    const double G = 6.673E-8; 
    double force;

    while (true) {
        // prompts the user for the two masses and distance
        cout << "Please input the first mass: ";
        cin >> m1; 
        cout << "Please input the second mass: ";
        cin >> m2;
        cout << "Please input the distance: ";
        cin >> d;
        cout << endl;

        force = (G * m1 * m2) / (pow(d, 2));

        cout.setf(ios::scientific);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The force of gravity is " << force << " newtons." << endl;

        // if the user types 'n', the program ends
        // if the user types 'y', the program continues and prompts the user for new values
        char userChoice;
        cout << "Would you like to calculate another force of gravity? (y/n): ";
        cin >> userChoice;
        if (userChoice == 'n') {
            break;
        } else if (userChoice == 'y') {
            continue;
        } else {
            cout << "Invalid input. Exiting program." << endl;
            break;
        }
    }
}

// Problem 2
void parttwo() {
    // contains the scores from the file, the average, and the standard deviation
    ifstream in;
    ofstream out;
    double grade1, grade2, grade3, grade4, grade5;
    double average, stdev;

    in.open("scores.txt"); //open the input file
    out.open("output.txt"); // open the output file

    in >> grade1 >> grade2 >> grade3 >> grade4 >> grade5; // read the grades from the file

    // calculate the average and standard deviation 
    average = (grade1 + grade2 + grade3 + grade4 + grade5) / 5.0;
    stdev = sqrt((pow(grade1 - average, 2) + pow(grade2 - average, 2) + pow(grade3 - average, 2) + pow(grade4 - average, 2) + pow(grade5 - average, 2)) / 5.0);    

    out << fixed << setprecision(2) << "The average score is: " << average << endl;
    out << fixed << setprecision(2) << "The standard deviation is: " << stdev << endl;

    in.close();
    out.close();
}

// Problem 3
void partthree() {
    double height, weight, age;
    double hatSize, jacketSize, waistSize;

    cout << "Please input your height in inches: ";
    cin >> height;
    cout << "Please input your weight in pounds: ";
    cin >> weight;
    cout << "Please input your age in years: ";
    cin >> age;

    hatSize = (weight * 2.9) / height;
    if (age > 30) {
        int ageOver30 = age - 30;
        int ageOver30InDecades = ageOver30 / 10;
        jacketSize = (height * weight) / 288.0 + (ageOver30InDecades * (1/8));
    } else {
        jacketSize = (height * weight) / 288.0;
    }
    if (age > 28) {
        int ageOver28 = age - 28;
        int ageOver28InIncrements = ageOver28 / 2;
        waistSize = weight / 5.7 + (ageOver28InIncrements * (1/10));
    } else {
        waistSize = weight / 5.7;
    }

    cout << fixed << setprecision(2);
    cout << "\nYour hat size is: " << hatSize << endl;
    cout << "Your jacket size is: " << jacketSize << endl;
    cout << "Your waist size is: " << waistSize << endl;
}

//Problem 4
void partfour() {
    int finalistList[5] = {0, 0, 0, 0, 0};
    int randomNum;

    for (int i=0; i<5; i++) {
        randomNum = rand() % 26 + 1;
        
        while (true) {
            for (int j=0; j<5; j++) {
                if (finalistList[j] == randomNum) {
                    randomNum = rand() % 26 + 1; // generates a new random number if there is a duplicate
                    break;
                }
            } 
            break;
        }
        finalistList[i] = randomNum;
    }
    cout << "\nThe finalists are: ";
    for (int i=0; i<5; i++) {
        cout << finalistList[i] << " ";
    }
    cout << endl;
}