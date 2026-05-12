/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Complex {
    private:
        double re;
        double im;

    public:
        Complex() {
            re = 0;
            im = 0;
        }

        Complex(double real) {
            re = real;
            im = 0;
        }

        Complex(double real, double imag) {
            re = real;
            im = imag;
        }

        double getReal() { return re; };
        double getImag() { return im; };

        double calculateMagnitude(double real, double imag);
        Complex add(Complex c1, Complex c2);
        Complex subtract(Complex c1, Complex c2);
        Complex multiply(Complex c1, Complex c2);
        Complex divide(Complex c1, Complex c2);
        void printComplex();


};

double Complex::calculateMagnitude(double real, double imag) {
    return sqrt(real * real + imag * imag);
};

Complex Complex::add(Complex c1, Complex c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
};

Complex Complex::subtract(Complex c1, Complex c2) {
    return Complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
};

Complex Complex::multiply(Complex c1, Complex c2) {
    double c1Real = c1.getReal(); double c1Imag = c1.getImag();
    double c2Real = c2.getReal(); double c2Imag = c2.getImag();

    return Complex(c1Real * c2Real - c1Imag * c2Imag, c1Real * c2Imag + c1Imag * c2Real);
};

Complex Complex::divide(Complex c1, Complex c2) {
    double c1Real = c1.getReal(); double c1Imag = c1.getImag();
    double c2Real = c2.getReal(); double c2Imag = c2.getImag();

    double denom = c2Real * c2Real + c2Imag * c2Imag;
    return Complex((c1Real * c2Real + c1Imag * c2Imag) / denom, (c1Imag * c2Real - c1Real * c2Imag) / denom);
};

void Complex::printComplex() {
    cout << fixed << setprecision(2) << re;
    if (im >= 0) {
        cout << " + " << "i" << im;
    } else {
        cout << " - " << "i" << -im;
    }
};

int main() {
    Complex c1(3, 5);
    Complex c2(4, -2);

    cout << "Complex number 1: ";
    c1.printComplex();
    cout << endl;

    cout << "Complex number 2: ";
    c2.printComplex();
    cout << endl;

    Complex sum = c1.add(c1, c2);
    cout << "Addition: ";
    sum.printComplex();
    cout << endl;

    Complex difference = c1.subtract(c1, c2);
    cout << "Subtraction: ";
    difference.printComplex();
    cout << endl;

    Complex product = c1.multiply(c1, c2);
    cout << "Multiplication: ";
    product.printComplex();
    cout << endl;

    Complex quotient = c1.divide(c1, c2);
    cout << "Division: ";
    quotient.printComplex();
    cout << endl;
}