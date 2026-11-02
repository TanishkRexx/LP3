#include <iostream>
using namespace std;

int n;

// Display chessboard
void printBoard(int board[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check whether queen can be placed
bool isSafe(int board[20][20], int row, int col) {

    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve N-Queens using backtracking
bool solveNQueen(int board[20][20], int row) {

    // All queens are placed
    if (row == n)
        return true;

    // Try each column
    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col)) {

            board[row][col] = 1;

            if (solveNQueen(board, row + 1))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[20][20] = {0};

    cout << "Enter value of N: ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Enter N between 1 and 20";
        return 0;
    }

    // Place first queen
    board[0][0] = 1;

    cout << "\nInitial Board:\n";
    printBoard(board);

    if (solveNQueen(board, 1)) {
        cout << "\nFinal N-Queens Matrix:\n";
        printBoard(board);
    }
    else {
        cout << "\nSolution does not exist";
    }

    return 0;
}