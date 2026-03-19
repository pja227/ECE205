/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

bool player1(char board[3][3]);
bool player2(char board[3][3]);
void editBoard(char board[3][3], int choice, char mark);
void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char mark);

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    printBoard(board);

    while (true) {
        if (player1(board)) {
            cout << "Player 1 wins!" << endl;
            break;
        }
        if (player2(board)) {
            cout << "Player 2 wins!" << endl;
            break;
        }
    }

    return 0;
}

bool player1(char board[3][3]) {
    int num;
    do {
        cout << "Player 1, enter your choice (1-9): ";
        cin >> num;

        if (num < 1 || num > 9) {
            cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (num - 1) / 3;
        int col = (num - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already taken. Choose another." << endl;
            num = 0;
        }
    } while (num < 1 || num > 9);

    editBoard(board, num, 'X');
    printBoard(board);
    return checkWin(board, 'X');
}

bool player2(char board[3][3]) {
    int num;
    do {
        cout << "Player 2, enter your choice (1-9): ";
        cin >> num;

        if (num < 1 || num > 9) {
            cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (num - 1) / 3;
        int col = (num - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already taken. Choose another." << endl;
            num = 0;
        }
    } while (num < 1 || num > 9);

    editBoard(board, num, 'O');
    printBoard(board);
    return checkWin(board, 'O');
}

void editBoard(char board[3][3], int choice, char symbol) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = symbol;
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}