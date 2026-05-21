#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force
// Algorithm
// Can there be more than 2 majority elements?
// To understand why there can't be more than two majority elements (elements that appear more than n/3 times) in an array of size n, let's consider the following reasoning:
// A majority element must appear more than n/3 times. Let’s assume there are more than two majority elements, say A, B, and C.
// The combined frequency of these three elements would be: frequency of A + frequency of B + frequency of C > n/3 + n/3 + n/3 = n.
// Since the total occurrences of all elements cannot exceed n (the size of the array), the combined frequency of any three elements each appearing more than n/3 times would exceed the total size of the array, leading to a contradiction.
// Therefore, it is mathematically impossible to have more than two elements that each appear more than n/3 times in the array.
// Approach:
// Iterate through the array and select each element one by one.
// For each unique element, run another loop to count its occurrences in the array.
// If any element occurs more than floor(N/3) times, include it in the result array.
// If a previously included element is found during traversal, skip it to avoid counting duplicates.
// If the result array already contains 2 elements, break out of the loop, as there can’t be more than two majority elements.
// Return the result array containing the majority elements or return -1 if no such element is found.

// Time Complexity: O(N^2), where N is the size of the array. This is because for each element, we are traversing the entire array to count its occurrences.
// Space Complexity: O(1), as we are using a constant amount of space for the result array, which can hold at most 2 elements.

// void Solution(vector<int>& arr, int n){
//     vector<int> temp;

//     for(int i=0;i<n;i++){

//         if(find(temp.begin(), temp.end(), arr[i]) != temp.end()) continue;

//         int cnt=0;
//         for(int j=0;j<n;j++){
//             if(arr[i] == arr[j]) cnt++;
//         }
//         if(cnt>n/3){
//             temp.push_back(arr[i]);
//         }
//         if(temp.size()==2) break;
//     }

//     for(int ele: temp){
//         cout<<ele<<" ";
//     }

// }

// Better Approach
// Algorithm
// Use a hashmap (or a frequency array if the array size is small) to store the elements as key-value pairs, where the key is the element and the value is the number of times it occurs in the array.
// Traverse the entire array, updating the occurrences of each element in the hashmap.
// After the traversal, check the hashmap to see if any element's value (frequency) is greater than the floor of N/3. If it is, include the element in the answer array.
// If the size of the answer array reaches 2, break out of the loop, as there cannot be more than two majority elements.
// Finally, return the answer array containing the majority elements. If no such elements are found, return -1.

// Time Complexity: O(N * logN), where N is the size of the given array. For using a map data structure, where insertion in the map takes logN time, and we are doing it for N elements. So, it results in the first term O(N * logN). On using unordered_map instead, the first term will be O(N) for the best and average case, and for the worst case, it will be O(N2).
// Space Complexity: O(N) for using a map data structure. A list that stores a maximum of 2 elements is also used, but that space used is so small that it can be considered constant.

// void Solution(vector<int>& arr, int n){
//     unordered_map<int, int> mp;
//     int mini = n/3+1;

//     vector<int> ans;

//     for(int i=0;i<n;i++){
//         mp[arr[i]]++;

//         if(mp[arr[i]] == mini){
//             ans.push_back(arr[i]);
//         }

//         if(ans.size()==2) break;        
//     }

//     for(int x : ans) cout << x << " ";
// }

// Optimal Approach
// Algorithm
// Initialize four variables: cnt1 and cnt2 for tracking the counts of elements, and el1 and el2 for storing the potential majority elements.
// Traverse through the given array:
// If cnt1 is 0 and the current element is not equal to el2, set el1 to the current element and increment cnt1 by 1.
// If cnt2 is 0 and the current element is not equal to el1, set el2 to the current element and increment cnt2 by 1.
// If the current element is equal to el1, increment cnt1 by 1.
// If the current element is equal to el2, increment cnt2 by 1.
// In all other cases, decrease cnt1 and cnt2 by 1.
// After processing all elements, el1 and el2 should be the candidate elements for majority. To confirm:
// Use another loop to manually check the counts of el1 and el2 in the array.
// If either el1 or el2's count is greater than floor(N/3), it is considered a valid majority element.

// Time Complexity: O(N), where N is the size of the input array. We traverse the array twice: once to find potential candidates and once to validate them.
// Space Complexity: O(1), as we are using a constant amount of space for the counters and candidate elements, regardless of the input size.

void Solution(vector<int>& arr, int n){
    int mini = n/3+1;

    int ele1=0,ele2=0,cnt1=0,cnt2=0;

    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=ele2){
            ele1=arr[i];
            cnt1=1;
        }else if(cnt2==0 && arr[i]!=ele1){
            ele2=arr[i];
            cnt2=1;
        }

        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;

        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0,cnt2=0;

    for(int ele: arr){
        if(ele == ele1) cnt1++;
        if(ele == ele2) cnt2++;
    }

    if(cnt1 >= mini) cout<<ele1<<" ";
    if(cnt2 >= mini) cout<<ele2<<" ";
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
