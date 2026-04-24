/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
  from https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
  algorithm Sieve of Eratosthenes is
    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.
    
    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                set A[j] := false

    return all i such that A[i] is true.
 */

int main() {
    int number;
    cout << "Enter a number greater than 1: ";
    cin >> number;

    if (number < 2) {
        cout << "Sorry, no prime numbers." << endl;
        return 0;
    }

    vector<bool> A(number + 1, true);
    A[0] = A[1] = false;

    for (int i = 2; i * i <= number; i++) {
        if (A[i]) {
            for (int j = i * i; j <= number; j += i) {
                A[j] = false;
            }
        }
    }

    cout << "Prime numbers from 2 to " << number << ": ";
    for (int i = 2; i <= number; i++) {
        if (A[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}