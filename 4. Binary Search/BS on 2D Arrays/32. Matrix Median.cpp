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

// Brute-Force Approach
// Algorithm
// The extremely naive approach is to use a linear array or list to store the elements of the given matrix and sort the list. We can return the middle element of sorted list to find the median.

// Time Complexity: O(M*N*(log(M*N))), sorting the linear array takes time complexity of O(M*N(logM*N)).
// Space Complexity: O(M*N), to create a linear array.


// void Solution(vector<vector<int>> &mat, int n, int m){
//     vector<int> ls;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             ls.push_back(mat[i][j]);
//         }
//     }

//     sort(ls.begin(), ls.end());

//     int size = ls.size();
//     cout<<ls[size/2];
// }

// Optimal Approach
// Algorithm
// In a row-wise sorted matrix, each row is individually sorted, but the entire matrix isn’t globally sorted. Hence, we can’t just pick the middle element directly to get the median. If we flatten and sort the entire matrix, it would take O(N×M log(N×M)) time, which is inefficient. Instead, we can take advantage of the sorted rows and apply a more optimized method using binary search on the value space (i.e., the range of possible numbers in the matrix).
// We start by finding the minimum and maximum elements in the matrix. The smallest element will be in the first column, and the largest element will be in the last column. We then binary search between this range to find the median value.
// In each iteration of the binary search, we choose a middle value and count how many elements in the matrix are less than or equal to it. Since each row is sorted, we can do this efficiently using binary search (upper bound) on each row. If the count is less than or equal to half of the total number of elements, we move our search range to the right, otherwise, we move it to the left.

// Time Complexity: O(rows × log(max - min) × log(cols)), Binary search runs on the value space from min to max of the matrix and for each mid in binary search, we count how many numbers are less than or equal to mid
// Space Complexity: O(1), constant extra space is used.

int upperBound(vector<int> &arr, int n, int m, int target){
    int low = 0, high = m-1;
    int ans = m;
    
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int countLessEqual(vector<vector<int>> &mat, int n, int m, int target){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt += upperBound(mat[i], n, m, target);
    }
    return cnt;
}

int Solution(vector<vector<int>> &mat, int n, int m){
    
    int low = mat[0][0];
    int high = mat[0][m - 1];
    
    for (int i = 1; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }
    
    int req = (n*m)/2;
    while (low <= high) {
        int mid = low + (high-low) / 2;

        int count = countLessEqual(mat, n, m, mid);

        if (count <= req) low = mid + 1;
        else high = mid - 1;
    }

    return low;
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

    cout<<Solution(matrix, n, m);

}
