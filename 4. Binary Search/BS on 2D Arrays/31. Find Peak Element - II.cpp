#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// Algorithm
// To solve this problem we use the binary search approach.
// The key idea comes from how we find a peak in a 1-D array:
// For any middle position (mid), we check if it’s larger than both its neighbors, if it is, we’ve found a peak.
// If mid is smaller than the element on its left, that means a peak must be somewhere to the left, so we can discard the right half.
// If mid is smaller than the element on its right, then a peak must lie to the right, allowing us to discard the left half.
// This method reduces the number of elements we need to consider in every step, improving efficiency.
// For a 2-D array,
// The search will cover the column range from 0 to col-1, where col is the total number of columns.
// We choose a middle column and identify the row with the largest element in that column.
// We apply similar logic as in 1-D: if this element is bigger than both its side neighbors, we’ve found the peak.
// If the left neighbor is bigger, we only search the left part; if the right neighbor is bigger, we search the right part.

// Time Complexity: O(N * logM), where N is the number of rows in the matrix, M is the number of columns in each row. The complexity arises because binary search is performed on the columns, and for each mid column, a linear search through the rows is executed to find the maximum element.
// Space Complexity: O(1) as no additional space is used.

int maxElement(vector<vector<int>> &mat, int n, int mid){
   int maxValue = INT_MIN, idx=0;

   for(int i=0;i<n;i++){
        if(mat[i][mid] > maxValue){
            maxValue = mat[i][mid];
            idx = i;
        }
   }
   return idx;
}

void Solution(vector<vector<int>> &mat, int n, int m){
    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = maxElement(mat, n, mid);

        int left = mid-1 >=0 ? mat[row][mid-1] : INT_MIN;
        int right = mid+1 <m ? mat[row][mid+1] : INT_MIN;

        if(mat[row][mid] > left && mat[row][mid] > right){
            cout<<row<<" "<<mid;
            return;
        }
        else if(mat[row][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
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

    Solution(matrix, n, m);

}
