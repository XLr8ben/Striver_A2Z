#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//brute force (no duplicates)

// Sort the array in ascending order.
// Print the element at the (size of the array - 1)th index, which corresponds to the largest element in the array.

// Time Complexity: O(N log N), where N is the size of the array, as we are sorting the array.
// Space Complexity: O(1), as we are using a constant

// int sortArr(vector<int>& arr) {
//     sort(arr.begin(), arr.end());
//     return arr[arr.size() - 1];
// }


// optimised

// Create a variable called maxEle and initialize it with the value of the first element in the array.
// Use a for loop to iterate through the rest of the elements in the array.
// In each iteration, compare the current element with the max variable.
// If the current element is greater than the max value, update the max value with the current element's value.
// After completing the loop, print the max variable, which will hold the largest value in the array.

//Time Complexity: O(N), where N is the size of the array, as we are iterating through the array once.
// Space Complexity: O(1), as we are using a constant

int sortArr(vector<int>& arr){
    int maxEle = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxEle) maxEle = arr[i];
    }

    return maxEle;
}

int main() {
    int sz;
    cin>>sz;

    vector<int> arr(sz);

    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
   
    cout<<sortArr(arr);
   
    return 0;
}