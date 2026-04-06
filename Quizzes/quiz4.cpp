/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void displayAvailability(string category, int year, int ISBN);

class Book {
    
    public:
        Book(string c, int y, int i) {
            category = c;
            year = y;
            ISBN = i;
        }

        string getCategory() { return category; };
        int getYear() { return year; };
        int getISBN() { return ISBN; };

        void setCategory(string c) { category = c; };
        void setYear(int y) { year = y; };
        void setISBN(int i) { ISBN = i; };
        
    private:
        string category;
        int year, ISBN;
};

int main() {
    Book book1("history", 1970, 12345);
    Book book2("fiction", 1980, 67890);
    Book book3("history", 1950, 54321);
 
    cout << "Book 1: " << book1.getCategory() << ", " << book1.getYear() << ", " << book1.getISBN() << endl;
    displayAvailability(book1.getCategory(), book1.getYear(), book1.getISBN());
    cout << endl;

    cout << "Book 2: " << book2.getCategory() << ", " << book2.getYear() << ", " << book2.getISBN() << endl;
    displayAvailability(book2.getCategory(), book2.getYear(), book2.getISBN());
    cout << endl;

    cout << "Book 3: " << book3.getCategory() << ", " << book3.getYear() << ", " << book3.getISBN() << endl;
    displayAvailability(book3.getCategory(), book3.getYear(), book3.getISBN());
    cout << endl;

    return 0;
}

void displayAvailability(string category, int year, int ISBN) {
    if (category == "history" && year >= 1960) {
        cout << "The book is available." << endl;
    } else {
        cout << "The book is not available." << endl;
    }
}

