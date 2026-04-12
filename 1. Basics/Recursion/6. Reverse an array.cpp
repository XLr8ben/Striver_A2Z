#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

// Brute Force Approach
// Algorithm
// We want to reverse the elements of an array, so the first element becomes last and the last becomes first. A straightforward way is to create a new array and start placing the original array's elements from the back into the front of the new array. This way, we preserve the original and get the reversed version separately.
// Initialize an empty array of the same size as the original array.
// Start a loop from the last index of the original array and go backward.
// For each element while going backward, insert it at the current forward index of the new array.
// Continue until all elements are copied in reverse order.
// Return or print the reversed array.

// Time Complexity: O(n) Each element is visited once in a loop, where n is the number of elements in the input array.
// Space Complexity: O(n) An additional array of the same size is used to store the reversed elements.

// vector<int> Solution(vector<int>& arr, int n, vector<int>& temp){

//     for(int i=n-1;i>=0;i--){
//         temp[n-i-1] = arr[i];
//     }
//     return temp;
// }


// Better Approach
// Algorithm
// This approach improves on the previous one by reversing the array in-place, avoiding the need for extra space. It uses two pointers to simultaneously traverse the array from both ends, swapping the elements until the center is reached. This way, we avoid creating a new array and perform the reverse operation efficiently using constant space.
// Initialize a pointer p1 at the start of the array (index 0).
// Initialize another pointer p2 at the end of the array (index n - 1).
// While p1 is less than p2, do the following:
// Swap the elements at positions p1 and p2.
// Increment p1 by 1.
// Decrement p2 by 1.
// Continue this process for only the first n/2 elements of the array.
// Note: Swapping all n elements instead of just n/2 would result in the array being reversed twice, which brings it back to its original form.

// Time Complexity: O(n) Where n is the number of elements in the array. Each element is visited at most once due to the two-pointer approach.
// Space Complexity: O(1) No extra space is used other than a few pointers and variables. The array is reversed in-place.

// vector<int> Solution(vector<int>& arr, int n, vector<int>& temp){
//     int left=0,right=n-1;

//     while(left<=right){
//         swap(arr[left++], arr[right--]);
//     }
//     return arr;

// }

// Built-in Library Function Approach
// Algorithm
// C++ (using std::reverse from STL): The Standard Template Library provides a built-in reverse() function in <algorithm >, which reverses the contents of a container in-place. It uses two pointers internally to swap elements from both ends toward the center, making the solution efficient and concise.

// Time Complexity: O(n), because each element is visited once and possibly swapped once with its mirror index.
// Space Complexity: O(1) for C++, Java, and JavaScript (in-place), but O(n) for Python slicing since it creates a new list and then assigns back (unless using two pointers).

void Solution(vector<int>& arr, int n, vector<int>& temp){
    return reverse(arr.begin(), arr.end());
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> temp(n);

    Solution(arr, n, temp);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
