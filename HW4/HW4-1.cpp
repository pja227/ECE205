/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void userInput(int arraySize, int arr[]);
int max(int arraySize, int arr[]);
void printHistogram(int arraySize, int arr[], int bins);

int main() {
    int arraySize, maxValue, bins;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int arr[arraySize];
    userInput(arraySize, arr);

    maxValue = max(arraySize, arr);
    bins = maxValue / 10 + 1;

    printHistogram(arraySize, arr, bins);
}

void userInput(int arraySize, int arr[]) {
    cout << "Enter " << arraySize << " integers: ";

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }
}

int max(int arraySize, int arr[]) {
    int maxValue = arr[0];

    for (int i = 1; i < arraySize; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

void printHistogram(int arraySize, int arr[], int bins) {
    for (int i=0; i < bins; i++) {
        cout << i+1 << ": ";
        for (int j=0; j < arraySize; j++) {
            if (arr[j] >= i*10 && arr[j] < (i+1)*10) {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}