#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Board;

bool isSafe(const Board &board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

void addSolution(Board &board, vector<Board> &solutions) {
    solutions.push_back(board);
}

void solveNQueensUtil(Board &board, int col, int n, vector<Board> &solutions) {
    if (col >= n) {
        addSolution(board, solutions);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            solveNQueensUtil(board, col + 1, n, solutions);
            board[i][col] = 0;
        }
    }
}

Board rotate90(const Board &board) {
    int n = board.size();
    Board rotated(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = board[i][j];
        }
    }
    return rotated;
}

Board reflect(const Board &board) {
    int n = board.size();
    Board reflected(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reflected[i][n - j - 1] = board[i][j];
        }
    }
    return reflected;
}

bool isIsomorphic(const Board &a, const Board &b) {
    Board transformed = b;

    for (int i = 0; i < 4; i++) {
        if (a == transformed) return true;
        transformed = rotate90(transformed);
    }

    transformed = reflect(b);
    for (int i = 0; i < 4; i++) {
        if (a == transformed) return true;
        transformed = rotate90(transformed);
    }

    return false;
}

vector<Board> filterNonIsomorphic(vector<Board> &solutions) {
    vector<Board> uniqueSolutions;

    for (const auto &sol : solutions) {
        bool found = false;
        for (const auto &unique : uniqueSolutions) {
            if (isIsomorphic(sol, unique)) {
                found = true;
                break;
            }
        }
        if (!found) uniqueSolutions.push_back(sol);
    }

    return uniqueSolutions;
}

void printBoard(const Board &board) {
    for (const auto &row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int n) {
    Board board(n, vector<int>(n, 0));
    vector<Board> solutions;

    solveNQueensUtil(board, 0, n, solutions);
    vector<Board> uniqueSolutions = filterNonIsomorphic(solutions);

    int idx = 1;
    for (const auto &sol : uniqueSolutions) {
        cout << "Solution " << idx++ << ":\n";
        printBoard(sol);
    }

    cout << "Total non-isomorphic solutions for N=" << n << ": " << uniqueSolutions.size() << endl;
}

int main() {
    int N = 4; // Change this to compute for different N
    cout << "N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
