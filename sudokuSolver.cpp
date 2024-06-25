//Sudoku solver program
#include <iostream>
#include <vector>
using namespace std;

// Function to print the current state of the sudoku board
void printBoard(vector<vector<int> > &board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a number at position (i, j) is safe
bool isSafe(vector<vector<int> > &board, int i, int j, int num){
    // Check if the number is already present in the row or column
    for (int k = 0; k < board.size(); k++){
        if (board[i][k] == num || board[k][j] == num){
            return false; // Not safe to place number here
        }
    }
    // Check if the number is already present in the 3x3 subgrid
    int startRow = i - i%3;
    int startCol = j - j%3;
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if (board[x+startRow][y+startCol] == num){
                return false; // Not safe to place number here
            }
        }
    }
    return true; // It is safe to place number here
}

// Recursive function to solve the sudoku puzzle using backtracking
void solveSudoku(vector<vector<int> > &board, int i, int j){
    // Base case: If all cells are filled, print the board
    if (i == board.size()){
        printBoard(board);
        return;
    }
    // If the current cell is already filled, move to the next cell
    if (j == board[0].size()){
        solveSudoku(board, i+1, 0);
        return;
    }
    // If the current cell is empty, try placing numbers 1-9
    if (board[i][j] == 0){
        for (int num = 1; num <= 9; num++){
            if (isSafe(board, i, j, num)){
                // Place number at (i, j)
                board[i][j] = num;
                
                // Recur to place numbers in remaining cells
                solveSudoku(board, i, j+1);
                
                // Backtrack: Remove number from (i, j)
                board[i][j] = 0;
            }
        }
    }
    else{
        // If the current cell is already filled, move to the next cell
        solveSudoku(board, i, j+1);
    }
}

int main(){
    // Initialize empty 9x9 sudoku board
    vector<vector<int> > board(9, vector<int>(9, 0));
    
    // Input the initial state of the sudoku board
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }
    
    // Solve the sudoku puzzle using backtracking
    solveSudoku(board, 0, 0);
    
    return 0;
}