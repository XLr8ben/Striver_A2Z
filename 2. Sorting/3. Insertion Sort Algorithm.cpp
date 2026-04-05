#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Approach
// Algorithm
// In each iteration, select an element from the unsorted part of the array using an outer loop.
// Place this selected element in its correct position within the sorted part of the array.
// Use an inner loop to shift the remaining elements, if necessary, to accommodate the selected element. This involves shifting elements by one position until the selected element can be placed in the correct position.
// Continue this process until the entire array is sorted.

// Time Complexity: O(n^2), where n is the number of elements in the array. This is because, in the worst case, we may have to compare each element with all the previous elements.
// Space Complexity: O(1), as we are sorting the array in place and not using any additional data structures that grow with input size.

void Solution(vector<int>& arr, int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        for(;j>=0;j--){
            if(arr[j]>key){
                arr[j+1] = arr[j];
            }else{
                 break;
            }
        }
        arr[j+1] = key;
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

    Solution(arr, n);
    
    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}
