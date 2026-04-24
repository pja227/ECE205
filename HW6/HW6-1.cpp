/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void userInput(vector<int>& v);
void printHistogram(vector<int> v, int bins);
int max(vector<int> v);

int main() {
    int maxValue, bins;
    vector<int> v;

    userInput(v);

    maxValue = max(v);
    bins = maxValue / 10 + 1;

    printHistogram(v, bins);
}

void userInput(vector<int>& v) {
    int index;
    
    cout << "Enter any number of integers: ";

    cin >> index;
    while ( index > 0 ) {
        v.push_back(index);
        cin >> index;
    }
}

void printHistogram(vector<int> v, int bins) {
    for (int i=0; i < bins; i++) {
        cout << i+1 << ": ";
        for (int j=0; j < v.size(); j++) {
            if (v[j] >= i*10 && v[j] < (i+1)*10) {
                cout << v[j] << " ";
            }
        }
        cout << endl;
    }
}

int max(vector<int> v) {
    int maxValue = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > maxValue) {
            maxValue = v[i];
        }
    }
    return maxValue;
}