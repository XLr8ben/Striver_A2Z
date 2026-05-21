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
// Iterate through the array from index 1 to N, where N is the size of the array.
// For each integer, i, use linear search to count its occurrence in the given array.
// If an element has an occurrence of 2, store it as a candidate element.
// If an element has an occurrence of 0, store it as another candidate element.
// Finally, return the two elements that have occurrences of 2 and 0, respectively.

// Time Complexity: O(N2), where N is the size of the array. This is because we are iterating through the array for each integer from 1 to N, leading to a nested loop.
// Space Complexity: O(1), as we are using a constant amount of space for the variables `repeating` and `missing`, regardless of the input size.

// void Solution(vector<int>& arr, int n){
    
//     int rep = -1, mis = -1;

//     for(int i=1;i<=n;i++){
//         int cnt = 0;
//         for(int j=0;j<n;j++){
//             if(arr[j] == i) cnt++;
//         }
//         if(cnt == 0) mis = i;
//         else if(cnt == 2) rep = i;

//         if(rep != -1 && mis != -1) break;
//     }
    
//     cout<<"repeating is "<<rep<<endl<<"missing is "<<mis<<endl;
// }

// Better Approach
// Algorithm
// Declare a hash array of size N+1 where N is the range of numbers in the array (from 1 to N). This hash array will store the frequency of each element.
// Iterate through the given array and for each element encountered, update the frequency in the hash array.
// Once all elements are processed, iterate through the hash array and identify the two elements: one with frequency 2 and one with frequency 0.
// Return the two elements that have frequencies of 2 and 0, respectively.

// Time Complexity: O(2*N), where N is the size of the array. This is because we are iterating through the array once to build the hash array and then iterating through the hash array to find the repeating and missing numbers.
// Space Complexity: O(N), as we are using an additional hash array of size N+1 to store the frequency of each element.

// void Solution(vector<int>& arr, int n){
//     int hash[n+1] = {0};

//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }

//     int rep = -1, mis = -1;

//     for(int i=1;i<=n;i++){
//         if(hash[i] == 2) rep = i;
//         else if(hash[i] == 0) mis = i;
//         if(rep != -1 && mis != -1) break;
//     }
//     cout<<"repeating is "<<rep<<endl<<"missing is "<<mis<<endl;
// }

// Optimal Approach 1
// Algorithm
// First, calculate the sum of all elements in the given array, denoted as S, and the sum of natural numbers from 1 to N, denoted as Sn. The formula for Sn is (N * (N + 1)) / 2.
// Now calculate S - Sn. This gives us X - Y, where X is the repeating number and Y is the missing number.
// Next, calculate the sum of squares of all elements in the array, denoted as S2, and the sum of squares of the first N numbers, denoted as S2n. The formula for S2n is (N * (N + 1) * (2N + 1)) / 6.
// Now calculate S2 - S2n. This gives us X2 - Y2.
// From the equations S - Sn = X - Y and S2 - S2n = X2 - Y2, we can compute X + Y by the formula (S2 - S2n) / (S - Sn).
// Using the values of X + Y and X - Y, we can solve for X and Y through simple addition and subtraction.
// Finally, return the values of X (the repeating number) and Y (the missing number).

// Time Complexity: O(N), where N is the size of the array. This is because we are iterating through the array to calculate the sums and sums of squares.
// Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

void Solution(vector<int>& arr, int n){

    long long S=0, S2=0;
    long long Sn = (n*(n+1)) / 2;
    long long S2n = (n*(n+1)*(2*n+1)) / 6;

    for(int i=0;i<n;i++){
        S += arr[i];
        S2 += (long long) arr[i] *(long long) arr[i]; 
    }

    long long val1 = S - Sn;      //x - y
    long long val2 = S2 - S2n;     //x2 - y2

    val2 = val2 / val1;     //x + y

    long long x = (val1 + val2) / 2;
    long long y = x- val1;

    cout<<x<<" "<<y<<endl;
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution(arr, n);

    return 0;
}
