#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute force Approach
// Algorithm
// The extremely naive approach is to get the answer by checking all the elements of the given matrix. So, we will traverse the matrix and check every element if it is equal to the given ‘target’.
// We will use a loop(say i) to select a particular row at a time.
// Next, for every row, we will use another loop(say j) to traverse each column.
// Inside the loops, we will check if the element i.e. matrix[i][j] is equal to the ‘target’. If we find any matching element, we will return true.
// Otherwise, after completing the traversal, we will return false.

// Time Complexity: O(n × m), We are traversing the entire matrix with `n` rows and `m` columns. In the worst case, we may end up visiting every cell once if the target is not present. So, the total number of operations is proportional to the number of elements in the matrix.
// Space Complexity: O(1),We are not using any additional space. The algorithm uses a constant amount of extra memory regardless of the size of the matrix just loop variables and the target. Therefore, the space complexity is constant.

// int Solution(vector<vector<int>> &matrix, int n, int m, int target){

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == target)
//                 return true;
//         }
//     }

//     return false;
// }

// Better Approach
// Algorithm
// We are going to use the Binary Search algorithm to optimize the approach. The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

// The question specifies that each row in the given matrix is sorted. Therefore, to determine if the target is present in a specific row, we don't need to search column by column. Instead, we can efficiently use the binary search algorithm.

// To make the time complexity even better, we won't use binary search on every row. We'll focus only on the particular row where the target might be located.

// How to check if a specific row is containing the target:
// If the target lies between the first and last element of the row, i (i.e. matrix[i][0] <= target && target <= matrix[i][m-1]), we can conclude that the target might be present in that specific row.

// Once we locate the potentially relevant row containing the 'target', we need to confirm its presence. To accomplish this, we will utilize the Binary search algorithm, effectively reducing the time complexity.
// We will use a loop(say i) to select a particular row at a time.
// Next, for every row, i, we will check if it contains the target.
// If matrix[i][0] <= target && target <= matrix[i][m-1]: If this condition is met, we can conclude that row i has the possibility of containing the target.
// So, we will apply binary search on row i, and check if the ‘target’ is present. If it is present, we will return true from this step. Otherwise, we will return false.
// Otherwise, after completing the traversal, we will return false.

// Time Complexity: O(n × log m), We go through each of the `n` rows once. For any valid row where the target can exist, we apply binary search which takes O(log m). So overall time = O(n × log m).
// Space Complexity: O(1), No extra space is used just a few integer variables for looping and binary search. So space complexity is constant.

// bool binarySearch(vector<int> &arr, int n, int x){
//     int low = 0, high = n-1;

//     while(low<=high){
//         int mid = low + (high - low) / 2;

//         if(arr[mid] == x) return true;
//         else if(arr[mid] > x) high = mid - 1;
//         else low = mid + 1;
//     }
//     return false;
// }

// bool Solution(vector<vector<int>> &matrix, int n, int m, int target){
//     for(int i=0;i<n;i++){
//         if(matrix[i][0] <= target && target <= matrix[i][m-1]){
//             return binarySearch(matrix[i], m, target);
//         }
//     }
//     return false;
// }

// Optimal Approach
// Algorithm
// If we flatten the given 2D matrix into a 1D array, that 1D array would also be sorted. By running binary search on this flattened version, we could quickly check if the element exists.

// But actually flattening the matrix takes extra time and memory, which makes it inefficient. Instead, we can simulate the flattening without creating a new array. The trick is to directly map a 1D index into the corresponding row and column of the 2D matrix.

// To do this mapping, if there are `m` columns in the matrix and the index is `i`, then:
// Row = i / m, Column = i % m.

// So instead of working on the 2D matrix directly, we pretend it’s a sorted 1D array of length (rows × columns), and apply binary search on this imaginary array.

// Start with two pointers: one at the first index of the imaginary 1D array, and the other at the last index.
// While the first pointer does not cross the last:
// Find the middle index between the two pointers.
// Convert this middle index into a row and column of the original 2D matrix.
// If the element at that position matches the target, return true (element found).
// If the element is smaller than the target, discard the left half and continue searching in the right half.
// If the element is larger than the target, discard the right half and continue searching in the left half.
// If the search ends without finding the element, return false (element not present in the matrix).

// Time Complexity: O(log(NxM)), where N = given row number, M = given column number.We are applying binary search on the imaginary 1D array of size NxM.
// Space Complexity: O(1) as we are not using any extra space.

bool Solution(vector<vector<int>> &matrix, int n, int m, int target){
    int low = 0, high = n*m-1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col]==target) return true;
        else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin>>target;

    cout << Solution(matrix, n, m, target) << endl;

    return 0;
}

