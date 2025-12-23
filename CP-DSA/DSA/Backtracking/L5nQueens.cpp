// N Queens Problem
// Place N Queens on an N x N chessboard such that no two queens threaten each other.
// A queen can attack horizontally, vertically, and diagonally.
// We need to find all possible arrangements to place the N queens on the board.

// Solving with an assumption that no queen is attacking any other queen initially.

#include <bits/stdc++.h>
using namespace std;

void nQueens(vector<vector<char>> board, int row){
    // El row me ek queen rakhni hai
    
}

void printBoard(vector<vector<char>> board){
    int n = board.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
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

    printBoard(board);
    return 0;
}