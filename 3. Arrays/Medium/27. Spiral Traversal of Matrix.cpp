#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm
// The brute force method simulates movement in four directions: right, down, left, and up while keeping track of which cells have already been visited using a separate matrix. This approach ensures that we never revisit any element and always stay within bounds. After moving in one direction as far as possible, we rotate the direction and keep repeating until all elements are visited.
// Initialize a 2D boolean matrix `visited` of same size as input to keep track of visited cells.
// Define direction arrays for right, down, left, and up movements.
// Start at (0, 0), and begin with direction = 0 (right).
// For each of the total elements in the matrix:
// Add the current cell to result and mark it as visited.
// Check if the next cell in the current direction is valid and not visited.
// If valid, move to it; else rotate the direction and try the new direction.
// Repeat this for total number of cells in the matrix.

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {

            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {

            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

// Driver code
int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> result = spiralOrder(matrix);

    for (int val : result)
    {
        cout << val << " ";
    }
    
    return 0;
}