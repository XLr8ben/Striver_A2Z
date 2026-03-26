#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;


//brute force
// The extremely naive solution, we can think of, involves the use of an extra array. The algorithm is as follows.
// Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array.
// Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array.
// The last N-X places of the original array will be then filled with zero. Now, our task is completed.

// Time Complexity: O(N), we can move all zeroes to end in linear time.
// Space Complexity: O(N), additional space used for temporary array.

// int moveZeroes(vector<int>& arr, int n){
//     vector<int> temp(n, 0);

//     int idx=0;

//     for(int i=0;i<n;i++){
//         if(arr[i]!=0){
//             temp[idx] = arr[i];
//             idx++;
//         }
//     }

//     for(int i=0;i<n;i++){
//         arr[i] = temp[i];
//     }

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    
//     return 0;
// }

//Optimal Approach
// We can optimize the approach using 2 pointers i.e. i and j. The pointer j will point to the first 0 in the array and i will point to the next index.
// Assume, the given array is {1, 0, 2, 3, 2, 0, 0, 4, 5, 1}. Now, initially, we will place the 2-pointers like the following:
// First, we iterate through the array to locate the position of the first zero, using a pointer j. If no zero is found, no further steps are needed.
// Next, we set a second pointer i to j + 1 and start moving it forward through the array.
// While moving i, whenever we encounter a non-zero element a[i], we swap it with the element at index j. After the swap, since j now holds a non-zero value, we increment j to point to the next zero.

// Time Complexity: O(N), we can move all zeroes to end in linear time.
// Space Complexity: O(1), constant additional space is used.

void moveZeroes(vector<int>& arr, int n){

    if(n<=1){
        cout<<0;
        return;
    }
    
    int i=-1;

    for(int j=0;j<n;j++){
        if(arr[j]==0){
            i=j;
            break;
        }
    }

    if(i==-1) return;

    for(int j=i+1;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j], arr[i]);
            i++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    moveZeroes(arr, n);

    return 0;
}
