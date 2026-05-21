#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// What is Upper Bound?
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x.

// Brute Force Approach
// Algorithm
// Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array
// starting from the beginning. During this traversal, each element will be compared with the target value, x. The index, i, where the condition arr[i] > x is first satisfied, will be the answer.

// Time Complexity: O(N), where N = size of the given array.
// Space Complexity: O(1), no extra space used.

// int Solution(vector<int>& arr, int n, int x){
//     for(int i=0;i<n;i++){
//         if(arr[i]>x) return i;
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows: We will declare the 2 pointers and an ‘ans’ variable initialized to n i.e. the size of the array(as If we don’t find any index, we will return n).
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
// Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// Case 1 - If arr[mid] > x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
// Case 2 - If arr[mid] <= x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.

// Time Complexity: O(logn), used for typical binary search
// Space Complexity: O(1), no extra space used

int Solution(vector<int>& arr, int n, int x){
    int low=0, high=n-1;
    int ans=-1;

    while(low<=high){
        int mid = (low + high) / 2;

        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid +1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int x;
    cin>>x;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, x)<<endl;

    return 0;
}
