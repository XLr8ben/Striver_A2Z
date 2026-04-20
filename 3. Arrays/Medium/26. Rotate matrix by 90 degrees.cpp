#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach
// Algorithm
// In a 90-degree clockwise rotation, each element in the matrix moves from its original position to a new position based on a specific pattern. The first column becomes the first row (in reverse order) and second column becomes the second row, and so on.
// We can simulate this movement by using a new matrix. For each element at position (i, j) in the original matrix, we calculate its new position in the rotated matrix as (j, n - i - 1) where n is the size of the matrix.
// Initialize an empty matrix of the same size (n x n).
// Loop through every element of the original matrix using two nested loops.
// For each element at position (i, j), place it in the new matrix at position (j, n - i - 1).
// After completing the placement for all elements, return or copy the new matrix.

// Time Complexity: O(N²),Each element of the matrix is visited exactly once and placed into a new matrix, so the time taken is proportional to the total number of elements.
// Space Complexity: O(N²),We use an additional matrix of the same size to store the rotated result, leading to O(N²) extra space.

// vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();

//     vector<vector<int>> rotated(n, vector<int>(n));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             rotated[j][n-i-1] = matrix[i][j];
//         }
//     }
//     return rotated;
// }

// Optimal Approach
// Algorithm
// To rotate a matrix 90 degrees clockwise in-place (without using extra space), we use two key matrix operations:
// Step 1: Transpose the matrix: swap elements across the diagonal. This converts rows into columns.
// Step 2: Reverse each row: this turns the new columns into the final rotated rows.

// This works because:
// Transposing moves elements from (i, j) to (j, i), effectively rotating across the diagonal.
// Reversing the rows repositions the elements in each row, finalizing the clockwise rotation.
// Get the size of the square matrix (number of rows or columns).
// Start the first phase: Transpose the matrix
// For each row starting from the top to bottom:
// For each column starting from the diagonal element (excluding already visited elements):
// Swap the current element with the element that is diagonally opposite across the main diagonal.
// This effectively flips the matrix over its top-left to bottom-right diagonal, converting rows into columns.
// Move to the second phase: Reverse each row
// For every row in the matrix:
// Reverse the order of the elements in that row (first element becomes last, second becomes second last, and so on).
// This realigns the columns to their correct position for the clockwise rotation.
// Once both phases are done, the matrix will have been rotated 90 degrees clockwise in-place. 

// Time Complexity: O(N²),We traverse every element once during transposition and again during reversal of each row, resulting in a total of O(N²) time.
// Space Complexity: O(1),All operations are done in-place using only temporary variables. No extra matrix is used.

vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;

}


int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<vector<int>> rotated = rotateClockwise(mat);

    for (auto row : rotated)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
