#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach

// In this simple approach, since the number of positive and negative elements are the same, we put positives into an array called “pos” and negatives into an array called “neg”.
// After segregating each of the positive and negative elements, we start putting them alternatively back into array A.
// Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
// This approach uses O(N+N/2) of running time due to multiple traversals which we’ll try to optimize in the optimized approach given below.

// Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
// Space Complexity: O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.

// int Solution(vector<int> &arr, int n)
// {
//     vector<int> pos;
//     vector<int> neg;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > 0)
//             pos.push_back(arr[i]);
//         else
//             neg.push_back(arr[i]);
//     }

//     for(int i=0;i<n/2;i++){
//         arr[2*i] = pos[i];
//         arr[2*i+1] = neg[i];
//     }

//     for(int ele: arr){
//         cout<<ele<<" ";
//     }

//     return 0;
// }

// Optimal Approach

// In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.
// We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).
// Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.
// When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.

// Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.
// Space Complexity: O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.

int Solution(vector<int> arr, int n){
    int pos=0,neg=1;
    vector<int> ans(n, 0);

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[pos] = arr[i];
            pos += 2;
        }else{
            ans[neg] = arr[i];
            neg += 2;
        }
    }

    for(int ele: ans){
        cout<<ele<<" ";
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution(arr, n);

    return 0;
}
