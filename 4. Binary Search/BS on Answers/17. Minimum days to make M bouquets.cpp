#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// Algorithm
// If the total number of flowers required to make all bouquets is more than the flowers available, it is not possible to make the bouquets. So, return -1.
// Loop through each day starting from the earliest bloom day to the latest bloom day to test all possible answers.
// For each day, check if it's possible to make the required number of bouquets using the flowers that have bloomed by that day. If yes, return that day as the answer.
// If no suitable day is found after checking all possibilities, it means it's impossible to make the bouquets. So, return -1.

// Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
// Space Complexity : O(1) as we are not using any extra space to solve this problem.

bool isPossible(vector<int>& arr, int n, int day, int target, int groupsize){
    int noofbouquets = 0;
    int cnt = 0;

    for(int i=0;i<n;i++){
        if(arr[i] <= day){
            cnt++;
        }else{
            noofbouquets += ( cnt/groupsize );
            cnt = 0;
        }
    }

    noofbouquets += ( cnt/groupsize );

    return noofbouquets >= target;
}

// int Solution(vector<int>& arr, int n, int m, int k){
//     if(m*k > n) return -1;
//     int mini = *min_element(arr.begin(), arr.end());
//     int maxi = *max_element(arr.begin(), arr.end());

//     for(int i=mini;i<=maxi;i++){
//         if(isPossible(arr, n, i, m, k)){
//             return i;
//         }   
        
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
// Next, we will find the maximum element i.e. max(arr[]), and the minimum element i.e. min(arr[]) in the array.
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to min(arr[]) and the high will point to max(arr[]).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Eliminate the halves based on the value returned by possible(): We will pass the potential answer, represented by the variable 'mid' (which corresponds to a specific day), to the 'possible()' function.
// If possible() returns true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
// Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
// Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

// Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
// Space Complexity : O(h)O(1) as we are not using any extra space to solve this problem.

int Solution(vector<int>& arr, int n, int m, int k){
    long long total = (1LL * m * k);
    if(total > n) return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    int ans = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, mid, m, k)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int m;
    cin>>m;

    int k;
    cin>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, m, k)<<endl;

    return 0;
}
