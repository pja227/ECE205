#include <iostream>

using namespace std;

bool inOrder(int a, int b, int c);

int main() {
    bool result1 = inOrder(1, 2, 3);
    bool result2 = inOrder(1, 2, 2);
    bool result3 = inOrder(1, 3, 2);

    cout << "inOrder(1, 2, 3) returns: " << result1 << endl;
    cout << "inOrder(1, 2, 2) returns: " << result2 << endl;
    cout << "inOrder(1, 3, 2) returns: " << result3 << endl;
}

bool inOrder(int a, int b, int c) {
    if (a < b && b < c) {
        return true;
    } else {
        return false;
    }
}