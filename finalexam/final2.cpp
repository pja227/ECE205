/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Book {
    private:
        string title;
        string author;
        int year;

    public:
        Book() {
            title = "";
            author = "";
            year = 0;
        }

        Book(string t, string a, int y) {
            author = a;
            title = t;
            year = y;
        }

        string getTitle() { return title; };
        string getAuthor() { return author; };
        int getYear() { return year; };
};

class Library {
    public:
        vector<Book> books;

        Library() { };

        void addBook(string title, string author, int year);
        void removeBook(string title);
        void sortBooksByAuthor();
        void printBooks();
};

void Library::addBook(string title, string author, int year) {
    books.push_back( Book(title, author, year) );
};

void Library::removeBook(string title) {
    for (int i=0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            for (int j = i; j < books.size() - 1; j++) {
                books[j] = books[j + 1];
            }

            books.resize(books.size() - 1);
            i--;
        }
    }
};

void Library::printBooks() {
    sortBooksByAuthor();

    for (int i = 0; i < books.size(); i++) {
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Year: " << books[i].getYear() << endl;
        cout << endl;
    }
};

void Library::sortBooksByAuthor() {
    for (int i = 0; i < books.size(); i++) {
        Book key = books[i];
        string keyAuthor = key.getAuthor();
        int j = i - 1;

        while (j >= 0 && books[j].getAuthor() > keyAuthor) {
            books[j + 1] = books[j];
            j--;
        }

        books[j + 1] = key;
    }
};

void display() {
    cout << "1. Add a book" << endl;
    cout << "2. Delete a book" << endl;
    cout << "3. Print listing sorted by author" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    Library library;
    int choice;

    library.addBook("Percy Jackson: The Lightning Thief", "Riordan, Rick", 2004);
    library.addBook("The Diary of a Wimpy Kid", "Joe, John", 2006);
    library.addBook("It Ends with Us", "Hoover, Colleen", 2020);

    do {
        display();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string author, title;
                int year;

                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter date: ";
                cin >> year;
                cin.ignore();  // Clear newline after year input

                library.addBook(title, author, year);
                break;
            }
            case 2: {
                string title;

                cout << "Enter title you want to remove: ";
                getline(cin, title);

                library.removeBook(title);
                break;
            }

            case 3:
                cout << "The books entered so far, sorted by author:" << endl;
                library.printBooks();
                break;

            case 4:
                cout << "Program exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);
    
}