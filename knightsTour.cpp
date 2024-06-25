#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define N 8

// Function prototypes
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);
int isSafe(int x, int y, int sol[N][N]);
void printSolution(int sol[N][N]);
int solveKT();

// Function to check if (x, y) is a valid position on the chessboard and not yet visited
int isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Function to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

// Main function to solve the Knight's Tour problem
int solveKT() {
    int sol[N][N]; // Solution matrix

    // Initialize solution matrix with all cells as -1 (unvisited)
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Possible moves for a knight in x and y direction
    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    // Start knight's tour from position (0, 0)
    sol[0][0] = 0;

    // Function call to solve Knight's tour problem
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    } else {
        cout << "Solution found:\n";
        printSolution(sol);
    }

    return 1;
}

// A recursive utility function to solve Knight Tour problem
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[8], int yMove[8]) {
    int k, next_x, next_y;

    // Base case: If all squares are visited, return true
    if (movei == N * N)
        return 1;

    // Try all next moves from the current coordinate x, y
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                // Backtracking: If exploring this path does not lead to a solution, undo the move
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Driver code
int main() {
    solveKT(); // Function call to solve Knight's tour
    return 0;
}
