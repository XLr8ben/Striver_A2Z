#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute-Force Approach
// Algorithm
// To find the nth root of a number m, we want to find a number x such that x^n = m. The naive approach to solve this is to linearly search for every possible number. Using linear search, we start from 1 and gradually try increasing values, checking if raising them to the power n gets us close to or exactly equals m.
// Start a loop from 1 to m for linear search.
// For each value in the loop, compute the value raised to power n.
// If the result equals m, return that value.
// If the result exceeds m, break the loop as the nth root does not exist as an integer.
// If no exact match is found, return -1 to indicate failure.

// Time Complexity: O(M), we search for every possible number from 1 to M to check if it is the Nth root.
// Space Complexity: O(1), constant additional space is used.

// int Solution(int n, int m){
//     int ans=-1;

//     for(int i=1;i<=n;i++){
//         if( pow(i,n) == m) return i;
//         else if( pow(i,n) > m) break;
//     }

//     return ans;
// }

// Optimal Approach
// Algorithm
// To find the N-th root of a number M, instead of checking every number from 1 to M (which is inefficient), we use binary search to efficiently reduce the search space. Since the N-th root lies between 1 and M, we start with a search range from 1 to M.
// For each middle value in this range, we compute its N-th power by multiplying it with itself N times, without using built-in power functions (to avoid integer overflow). During this multiplication, if the result exceeds M, we stop early to save time. If the final result equals M, we’ve found the N-th root. Otherwise, we adjust our search range accordingly to continue the binary search. This method significantly speeds up the process by halving the range at each step.
// Start binary search with low as 1 and high as M.
// Find mid of the range and multiply it with itself N times to get Nth power of mid.
// If Nth power of mid equals M, return mid as the N-th root.
// If Nth power of mid is less than M, shift search to the right half.
// If Nth power of mid is greater than M, shift search to the left half.
// If no integer root is found after the loop, return -1.

// Time Complexity: O(logM), we search for every possible number from 1 to M to check if it is the Nth root.
// Space Complexity: O(1), constant additional space is used.

// double Solution(int n, int m){
//     double low=1,high=m;
//     double eps=1e-6;
    
//     while(high - low > eps){
//         double mid = (low + high) / 2.0;
//         double ans = 1.0;

//         for(int i=0;i<n;i++){
//             ans *= mid;
//             if(ans > m) break;
//         }

//         if(ans < m) low = mid;  
//         else high = mid;
//     }
//     return low;
// }

int Solution(int n, int m) {
    int low = 1, high = m;

    while(low <= high){
        int mid = low + (high - low) / 2;
        long long ans = 1;

        for(int i = 0; i < n; i++){
            ans *= mid;
            if(ans > m) break;
        }

        if(ans == m) return mid;
        else if(ans < m) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}


int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    cout<<Solution(n, m)<<endl;

    return 0;
}
