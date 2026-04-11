/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class PrimeNumber {
    private:
        int number;

    public:
        // Default constructor
        PrimeNumber() {
            number = 1;
        }

        // Custom constructor
        PrimeNumber(int n) {
            number = n;
        }
    
        void setNumber(int n) { number = n; };
        int getNumber() { return number; };
        bool isPrime(int n);
        
        PrimeNumber operator++();
        PrimeNumber operator--();
        PrimeNumber operator++(int);
        PrimeNumber operator--(int);
};

bool PrimeNumber::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;
}

// ++number
PrimeNumber PrimeNumber::operator++() {
    int n = number + 1;

    while (!isPrime(n)) {
        n++;
    }

    number = n;
    return PrimeNumber(number);
}

// number++
PrimeNumber PrimeNumber::operator++(int) {
    int oldNumber = number;
    int n = number + 1;

    while (!isPrime(n)) {
        n++;
    }

    number = n;
    return PrimeNumber(oldNumber);
}

// --number
PrimeNumber PrimeNumber::operator--() {
    int n = number - 1;

    while (n >= 2 && !isPrime(n)) {
        n--;
    }
    if (n >= 2) {
        number = n;
    }
    return PrimeNumber(number);
}

// number--
PrimeNumber PrimeNumber::operator--(int) {
    int oldNumber = number;
    int n = number - 1;

    while (n >= 2 && !isPrime(n)) {
        n--;
    }

    if (n >= 2) {
        number = n;
    }

    return PrimeNumber(oldNumber);
}

int main() {
    PrimeNumber prime(13);
    cout << "Current prime number: " << prime.getNumber() << endl;

    ++prime;
    cout << "After pre-increment: " << prime.getNumber() << endl;

    prime++;
    cout << "After post-increment: " << prime.getNumber() << endl;

    --prime;
    cout << "After pre-decrement: " << prime.getNumber() << endl;

    prime--;
    cout << "After post-decrement: " << prime.getNumber() << endl;

    return 0;
}