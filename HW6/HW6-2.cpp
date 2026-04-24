/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void userInput(vector<char>& v);
void deleteRepeatedChars(vector<char>& myVector);
void selectionSort(vector<char>& myVector);
void printVector(vector<char> myVector);

int main() {
    vector<char> v;
    userInput(v);

    cout << "Original vector: ";
    printVector(v);

    cout << "No duplicates vector: ";
    deleteRepeatedChars(v);
    printVector(v);

    cout << "Sorted vector: ";
    selectionSort(v);
    printVector(v);
}

void userInput(vector<char>& v) {
    char index;
    
    cout << "Enter any number of characters: ";

    cin >> index;
    while ( index != '0' ) {
        v.push_back(index);
        cin >> index;
    }
}

void deleteRepeatedChars(vector<char>& myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        for (int j = i + 1; j < myVector.size(); j++) {
            if (myVector[i] == myVector[j]) {
                
                for (int k = j; k < myVector.size() - 1; k++) {
                    myVector[k] = myVector[k + 1];
                }
                myVector.resize(myVector.size() - 1);
                j--; 
            }
        }
    }
}

void selectionSort(vector<char>& myVector) {
    for (int i = 0; i < myVector.size() - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < myVector.size(); j++) {
            if (myVector[j] > myVector[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            char temp = myVector[i];
            myVector[i] = myVector[maxIndex];
            myVector[maxIndex] = temp;
        }
    }
}

void printVector(vector<char> myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;
}