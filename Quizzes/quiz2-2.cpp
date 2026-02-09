#include <iostream>

using namespace std;

string inOrder(int a, int b, int c);

int main() {
    string result1 = inOrder(1, 2, 3);
    string result2 = inOrder(1, 2, 2);
    string result3 = inOrder(1, 3, 2);
    
    cout << "inOrder(1, 2, 3) returns: " << result1 << endl;
    cout << "inOrder(1, 2, 2) returns: " << result2 << endl;
    cout << "inOrder(1, 3, 2) returns: " << result3 << endl;
}

string inOrder(int a, int b, int c) {
    if (a < b && b < c) {
        return "true";
    } else if ( a < b && c == b) {
        return "true";
    } else {
        return "false";
    }
}