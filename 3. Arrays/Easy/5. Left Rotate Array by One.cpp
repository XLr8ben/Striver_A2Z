#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//brute force
// Create a dummy array of the same length as the original array.
// Shift all elements in the original array toward the left, copying them into the dummy array.
// After shifting, place the value of the 0th index of the original array into the last element of the dummy array.
// Finally, print the dummy array which now contains the left-shifted elements with the 0th element moved to the last position.

// Time Complexity: O(N), where N is the size of the array. This is because we traverse the array once to shift the elements.
// Space Complexity: O(N), as we are using a temporary array of the same size as the input array to store the shifted elements.

// int Solution(vector<int>& arr, int n){
//     vector<int> temp;

//     for (int i = 1; i < n; i++) {
//         temp[i - 1] = arr[i];
//     }
//     temp[n - 1] = arr[0];

//     for (int i = 0; i < n; i++) {
//         cout << temp[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Optimal Approach
// Store the value of the first element of the array in a temporary variable.
// Iterate through the array starting from the second element.
// Shift each element one position to the left by assigning the current element to the position of its predecessor.
// After completing the iteration, place the value from the temporary variable into the last position of the array.

// Time Complexity: O(N), where N is the size of the input array. This is because we traverse the array once to shift the elements.
// Space Complexity: O(1), as we are using only a constant amount of extra space for the temporary variable.

void Solution(vector<int>& arr, int n){
    int temp = arr[0];
        
    for (int i = 1; i < n; ++i) {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;

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

    Solution(arr, n);

    return 0;
}
