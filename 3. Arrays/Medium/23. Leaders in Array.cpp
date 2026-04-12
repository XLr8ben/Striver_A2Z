#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force
// Algorithm
// In this brute force approach, we start by checking all the elements from the start of the array to the end to determine if an element is greater than all the elements to its right (i.e., the leader).
// We use nested loops for this:
// The outer loop checks each element in the array to see if it is a leader.
// The inner loop checks if there is any element to the right that is greater than the element being currently processed by the outer loop.
// Begin by initializing the outer loop pointer at the start element and set it as the current leader.
// If any element traversed is found to be greater than the current leader, the element is not considered a leader, and the outer loop pointer is incremented by 1, setting the next element as the current leader.
// If no other element to the right is greater than the current element, it is added to the answer array as a leader element.

// Time Complexity: O(N2), where N is the size of the input array. This is because we have a nested loop where the outer loop runs N times and the inner loop runs up to N times in the worst case.
// Space Complexity: O(1), as we are using only a constant amount of extra space for the answer array, which does not depend on the input size.

// void Solution(vector<int>& arr, int n){

//     vector<int> temp;

//     for(int i=0;i<n;i++){
//         bool leader = true;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>=arr[i]){
//                 leader = false;
//                 break;
//             }
//         }
//         if(leader) temp.push_back(arr[i]); 
//     }

//     for(int ele: temp){
//         cout<<ele<<" ";
//     }
    
// }

// Optimal Approach
// Algorithm
// Set a variable max to the last element of the array (nums[sizeOfArray - 1]), as the last element is always a leader.
// Create an empty list ans to store the leader elements, and initially add the last element of the array to this list, as it is always a leader.
// Start from the second last element (index = sizeOfArray - 2) and move towards the first element (index = 0).
// For each element, compare it with the max variable. If the current element is greater than max, add this element to the ans list and update max to the current element.
// After processing all elements, the ans list will contain all the leader elements in reverse order. Reverse the ans list and return it.

// Time Complexity: O(N), where N is the size of the input array. This is because we traverse the array only once.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

void Solution(vector<int>& arr, int n){

    vector<int> temp;

    int maxi = arr[n-1];
    temp.push_back(maxi);

    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            temp.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    for(int ele: temp){
        cout<<ele<<" ";
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
