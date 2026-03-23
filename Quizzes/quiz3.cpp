/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int userInput(int arraySize, int arr[]);
int max(int arraySize, int arr[]);
int min(int arraySize, int arr[]);
double calculateMean(int arraySize, int arr[]);
double stddev(int arraySize, int arr[], double meanValue);

int main() {
    int arrayCount;

    int arr[100]; // Assuming a maximum size of 100
    arrayCount = userInput(100, arr);
    
    int maxValue = max(arrayCount, arr);
    cout << "Max value: " << maxValue << endl;

    int minValue = min(arrayCount, arr);
    cout << "Min value: " << minValue << endl;

    double meanValue = calculateMean(arrayCount, arr);

    double standardDeviation = stddev(arrayCount, arr, meanValue);
    cout << "Standard deviation: " << standardDeviation << endl;

    return 0;
}

int userInput(int arraySize, int arr[]) {
    int count = 0;
    cout << "Enter positive integers (enter a negative integer to stop): ";

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            break;
        }
        if (arr[i] > 100) {
            i--;
            continue;
        }
        count++;
    }
    return count;
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

int min(int arraySize, int arr[]) {
    int minValue = arr[0];

    for (int i = 1; i < arraySize; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

double calculateMean(int arraySize, int arr[]) {
    if (arraySize == 0) {
        return 0.0;
    }

    int sum = 0;

    for (int i = 0; i < arraySize; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / arraySize;
}

double stddev(int arraySize, int arr[], double meanValue) {
    if (arraySize == 0) {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < arraySize; i++) {
        sum += pow(arr[i] - meanValue, 2);
    }
    return sqrt(sum / arraySize);
}
