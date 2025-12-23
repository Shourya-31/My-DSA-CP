// Now safeguarding against placing multiple queens

#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();
    // Horizontal Safety
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // Vertical Safety
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Left Diagonal Safety
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // Right Diagonal Safety
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void nQueens(vector<vector<char>> board, int row)
{
    // El row me ek queen rakhni hai
    int n = board.size();

    if (row == n)
    {
        printBoard(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {

        // Place Queen at (row,j)
        board[row][j] = 'Q';
        nQueens(board, row + 1);
        board[row][j] = '.'; // Reasoning => Backtrack else next calls will have this queen placed
    }
}

int main()
{
    vector<vector<char>> board;
    int n = 2;

    // Initialize the board with '.'
    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    cout << "Initial Board: \n";
    printBoard(board);
    cout << "\nAll possible arrangements of " << n << " queens are: \n";
    nQueens(board, 0);
    return 0;
}
