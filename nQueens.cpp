//Including necessary header files for input/output and vector operations
#include <iostream>
#include <vector>
using namespace std;

// Function to print the current state of the chessboard
void printBoard(vector<vector<int> > &board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at position (i, j) is safe
bool isSafe(vector<vector<int> > &board, int i, int j, vector<bool> &cols, vector<bool> &ldiag, vector<bool> &rdiag){
    // Check if there is a queen in the same column or diagonals
    if (cols[j] || ldiag[i+j] || rdiag[i-j+board.size()-1]){
        return false; // Not safe to place queen here
    }
    return true; // It is safe to place queen here
}

// Recursive function to solve the N-Queens problem using backtracking
void nQueens(vector<vector<int> > &board, int i, vector<bool> &cols, vector<bool> &ldiag, vector<bool> &rdiag){
    // Base case: If all queens are placed, print the board
    if (i == board.size()){
        printBoard(board);
        return;
    }
    // Try placing queen in each column of current row (i)
    for (int j = 0; j < board.size(); j++){
        if (isSafe(board, i, j, cols, ldiag, rdiag)){
            // Place queen at (i, j)
            board[i][j] = 1;
            cols[j] = true;
            ldiag[i+j] = true;
            rdiag[i-j+board.size()-1] = true;
            
            // Recur to place queens in remaining rows
            nQueens(board, i+1, cols, ldiag, rdiag);
            
            // Backtrack: Remove queen from (i, j) and reset flags
            board[i][j] = 0;
            cols[j] = false;
            ldiag[i+j] = false;
            rdiag[i-j+board.size()-1] = false;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the value for n: ";
    cin >> n; // Input number of queens (and board size)
    cout<<"\n";
    
    // Initialize empty n x n chessboard
    vector<vector<int> > board(n, vector<int>(n, 0));
    
    // Vectors to track columns and diagonals for queens
    vector<bool> cols(n, false); // Whether a column is occupied
    vector<bool> ldiag(2*n-1, false); // Whether left diagonals are occupied
    vector<bool> rdiag(2*n-1, false); // Whether right diagonals are occupied
    
    // Solve N-Queens problem starting from row 0
    nQueens(board, 0, cols, ldiag, rdiag);
    
    return 0;
}
