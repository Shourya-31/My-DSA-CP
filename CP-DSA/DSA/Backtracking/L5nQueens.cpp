// N Queens Problem
// Place N Queens on an N x N chessboard such that no two queens threaten each other.
// A queen can attack horizontally, vertically, and diagonally.
// We need to find all possible arrangements to place the N queens on the board.

// Solving with an assumption that no queen is attacking any other queen initially.

#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void nQueens(vector<vector<char>> board, int row){
    // El row me ek queen rakhni hai
    int n = board.size();

    if(row == n){
        printBoard(board);
        return;
    }

    for(int j=0; j<n; j++){

        // Place Queen at (row,j)
        board[row][j] = 'Q';
        nQueens(board, row+1);
        board[row][j]='.'; // Reasoning => Backtrack else next calls will have this queen placed

    }
}

int main() {
    vector<vector<char>> board;
    int n = 2;

    // Initialize the board with '.'
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    cout<<"Initial Board: \n";
    printBoard(board);
    cout<<"\nAll possible arrangements of "<<n<<" queens are: \n";
    nQueens(board, 0);
    return 0;
}