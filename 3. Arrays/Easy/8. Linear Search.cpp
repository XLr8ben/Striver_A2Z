#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//u already know this bro
// Given an array, traverse through the entire array.
// For each element, check if the element is present in the array.
// If the element is found, print the index of the element.
// If the element is not found, print -1.

// Time Complexity: O(N), where N is the number of elements in the array. This is because we traverse the entire array to find the element.
// Space Complexity: O(1), as we are using a constant

int Solution(vector<int>& arr, int n, int target){
    int i;

    for(int i=0;i<n;i++){
        if(arr[i]==target) return i;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int target;
    cin>>target;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, target)<<endl;

    return 0;
}
