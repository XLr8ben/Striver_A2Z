#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
using namespace std;

//brute force approach
// Iterate through the array to select each element one by one.
// For each selected element, run another loop to count its occurrences in the given array.
// If the occurrence of any element is greater than the floor of (N/2), return that element immediately as the majority element.

// Time Complexity: O(N^2), where N is the size of the input array. This is because we are using a nested loop to count the occurrences of each element.
// Space Complexity: O(1), as we are using a constant amount of space for the counters and indices.

// int Solution(vector<int>& arr, int n){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int cnt=0;
        
//         for(int j=0;j<n;j++){
//             if(arr[j]==arr[i]) cnt++;
//         }

//         if(cnt>n/2) return arr[i];
//     }

//     return -1;
// }

//better approach
// Use a hashmap to store elements as (key, value) pairs, where the key is the element of the array and the value is the number of times it occurs.
// Traverse the array and update the value of the corresponding key in the hashmap.
// Simultaneously check if the value (the count) of any key is greater than the floor of (N/2).
// If the value is greater than the floor of (N/2), return the key immediately as the majority element.
// If no majority element is found, continue iterating through the array.

// Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to count occurrences and then iterating through the hashmap to find the majority element.
// Space Complexity: O(N), as we are using a hashmap to store the counts of each element, which can take up to N space in the worst case.

// int Solution(vector<int>& arr, int n){
//     unordered_map<int, int> mp;

//     for(int ele: arr){
//         mp[ele]++;
//     }

//     for(auto pair: mp){
//         if(pair.second > n/2) return pair.first;
//     }

//     return -1;
// }

//optimal approach - Moore Voting Algo
// Initialize two variables: count to track the count of elements, and element to keep track of the element being counted.
// Traverse through the given array. If count is 0, store the current value of the array as element.
// If the current element in the array is the same as element, increment the count by 1.
// If the current element is different from element, decrement the count by 1.
// At the end of the traversal, the integer stored in element will be the expected result (the majority element).

// Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

int Solution(vector<int>& arr, int n){
    int ele=0, cnt=0;

    for(int i=0;i<n;i++){
        if(cnt==0){
            ele = arr[i];
            cnt=1;
        }

        else if(arr[i] == ele) cnt++;
        else cnt--;
    }

    int freq=0;
    for(int i=0;i<n;i++){
        if(ele == arr[i]) freq++;
    }

    if(freq>n/2) return ele;

    return -1;

}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n)<<endl;

    return 0;
}
