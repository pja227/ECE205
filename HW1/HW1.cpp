#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Problem 1
void partone() {
    int userTime; // user inputted time in seconds
    int hour, minute, seconds; // variables for the truncated time values
    double realHour, realMinute, realSeconds; // variables for the real time values

    cout << "Please input a length of time in seconds: ";
    cin >> userTime; 
    cout << endl;

    hour = userTime / 3600;
    minute = (userTime - (hour * 3600)) / 60;
    seconds = (userTime - (hour * 3600)) % 60;

    cout << "The time is " << hour << " hours, " << minute << " minutes, and " << seconds << " seconds." << endl;

    realHour = userTime / 3600.0;
    realMinute = userTime / 60.0;

    cout << "The real time is " << fixed << setprecision(4) << realHour << " hours or " << fixed << setprecision(4) << realMinute << " minutes." << endl;
}

// Problem 2
void parttwo() {
    double payRate = 36.75; // hourly pay rate
    double overTimeRate = payRate * 1.5; // overtime pay rate
    double socialSecurityTax = 0.06; // social security tax rate
    double federalIncomeTax = 0.15; // federal income tax rate 
    double stateIncomeTax = 0.04; // state income tax rate
    double bethlehemLocalTax = .01; // bethlehem local tax rate
    int unionDues = 20; // union dues per week
    int healthInsurance = 40; // health insurance for over 2 dependents per week

    int dependents, hoursWorked;
    double grossPay, netPay, totalDeductions;

    cout << endl; 
    cout << "How many hours did you work this week: ";
    cin >> hoursWorked;

    cout << "How many dependents do you have: ";
    cin >> dependents;

    // calculating gross pay
    if (hoursWorked <= 40) {
        grossPay = hoursWorked * payRate;
    } else {
        grossPay = (40 * payRate) + ((hoursWorked - 40) * overTimeRate);
    }

    // calculating total deductions
    if (dependents > 1) {
        totalDeductions = (grossPay * (socialSecurityTax + federalIncomeTax + stateIncomeTax + bethlehemLocalTax)) + unionDues + healthInsurance;
    } else {
        totalDeductions = (grossPay * (socialSecurityTax + federalIncomeTax + stateIncomeTax + bethlehemLocalTax)) + unionDues;
    }

    netPay = grossPay - totalDeductions;

    cout << fixed << setprecision(2);
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Total Deductions: $" << totalDeductions << endl;
    cout << "Net Pay: $" << netPay << endl;
}

// Problem 3
void partthree() {
    double balence = 1000.0; // initial balance
    double annualInterestRate = 0.18; // annual interest rate
    double monthlyInterestRate = annualInterestRate / 12.0; // monthly interest rate
    double monthlyPayment = 50.0; // monthly payment
    double interest, principal;
    double totalInterest = 0.0;
    double totalPaid = 0.0;
    int count = 0;

    cout << fixed << setprecision(2) << endl;
    cout << right << setw(7) << "Month #" << setw(15) << "Interest" << setw(15) << "Principal" << setw(15) << "Balance" << setw(18) << "Total Interest" << setw(15) << "Total Paid" << endl;
    
    while (balence > 0.01) {
        count++;
        if (balence < monthlyPayment) {
            monthlyPayment = balence;
        } 
        interest = balence * monthlyInterestRate;
        principal = monthlyPayment - interest;
        balence -= principal;
        
        totalPaid += monthlyPayment;
        totalInterest += interest;

        cout << right << setw(7) << count << setw(15) << interest << setw(15) << principal << setw(15) << balence << setw(18) << totalInterest << setw(15) << totalPaid << endl;
    }
}

// Main function
int main() {
    partone();
    parttwo();
    partthree();
}