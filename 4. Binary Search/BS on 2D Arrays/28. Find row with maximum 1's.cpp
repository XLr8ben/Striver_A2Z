#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force
// Algorithm
// Intuition
// The intution is to traverse the matrix as usual using nested loops and for every single row count the number of 1’s. Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index.
// Approach
// First, we create two variables: cnt_max is set to 0 and will keep track of the highest number of 1s found so far, and index is set to -1 and will store the row number with the most 1s.
// Then, we go through each row of the matrix one by one using a loop.
// Inside that loop, for each row, we count how many 1s it contains using another loop.
// If this count is higher than our current maximum cnt_max, we update cnt_max with this new count and set indexto the current row number.
// At the end, we return the index. It will either be the row number with the most 1s, or -1 if no 1s were found.

// Time Complexity:O(n X m), where n = given row number, m = given column number. We are using nested loops running for n and m times respectively.
// Space Complexity: O(1). No extra space used

// int Solution(vector<vector<int>> &matrix, int n, int m){
//     int cnt_max = 0;
//     int index = -1;

//     for (int i = 0; i < n; i++) {
//         int cnt_ones = 0;
//         for (int j = 0; j < m; j++) {
//             cnt_ones += matrix[i][j];
//         }
//         if (cnt_ones > cnt_max) {
//             cnt_max = cnt_ones;
//             index = i;
//         }
//     }
//     return index;
// }

// Optimal Approach
// Algorithm
// Intuition
// We will use Binary Search to make our solution more efficient. While we still need to check each row one by one, we can speed up how we count the 1s in each row. Instead of going through every element in a row to count the 1s, we find the position of the first 1 using Binary Search, and subtract that index from the total number of columns to get how many 1s are present.

// Approach
// Start by keeping track of the highest number of 1s seen so far and the row where that occurred.
// Go through each row of the matrix one by one.
// For each row, use Binary Search to find the first position where a 1 appears. Then subtract that position from the total number of columns to get the number of 1s in that row.
// Compare the current row's number of 1s with the highest found so far. If it's greater, update the highest count and the corresponding row number.
// After checking all rows, return the row number where the highest number of 1s was found. If there are no 1s at all, return -1.

// Time Complexity:O(n X logm), where n = given row number, m = given column number. We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.
// Space Complexity: O(1), no extra space is used.

int lowerBound(vector<int> &arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int Solution(vector<vector<int>> &matrix, int n, int m){
    int cnt_max=0;
    int idx = -1;

    for(int i=0;i<n;i++){
        int cnt = m - lowerBound(matrix[i], m, 1);
        if(cnt > cnt_max){
            cnt_max = cnt;
            idx = i;
        }
    }
    return idx;
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

    cout << Solution(matrix, n, m) << endl;

    return 0;
}
