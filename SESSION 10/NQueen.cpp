#include <bits/stdc++.h>
using namespace std;

// Check if placing a queen at (row, col) is safe
bool isSafe(vector<string>& board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    // Check upper-right diagonal
    r = row;
    c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c++;
    }

    return true;
}

// Backtracking function
void nQueens(vector<string>& board, int row, int n,
             vector<vector<string>>& ans) {

    // Base case: all queens placed
    if (row == n) {
        ans.push_back(board);
        return;
    }

    // Try each column in current row
    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            // Place queen
            board[row][col] = 'Q';

            // Recur for next row
            nQueens(board, row + 1, n, ans);

            // Backtrack
            board[row][col] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    nQueens(board, 0, n, ans);

    cout << "\nTotal solutions: " << ans.size() << "\n\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (auto& row : ans[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
