#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

//brute force approach
// We use two nested loops to generate all possible pairs of elements in the array. The outer loop iterates through the first element of the pair, while the inner loop iterates through the second element of the pair.
// For each pair of elements, we check if their sum equals the target value k. If it does, we store these two elements in the temp vector and return true.
// Time Complexity: O(n2), where n is the size of the array. This is because we have two nested loops: one for the first element and one for the second element.
// Space Complexity: O(1), as we are using a constant amount of space for variables and the temp vector only stores two elements, which does not grow with input size.

// bool Solution(vector<int>& arr, int n, int target, vector<int>& temp){
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i] + arr[j] == target){
//                 temp.push_back(arr[i]);
//                 temp.push_back(arr[j]);
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//better approach
// We use an unordered_map (hash map) to store the elements of the array and their corresponding indices. As we iterate through the array, we calculate the complement of the current element (i.e., target - current element) and check if it exists in the hash map.
// If the complement exists in the hash map, it means we have found a pair of elements that sum up to the target. We then store these two elements in the temp vector and return true.
// If the complement does not exist in the hash map, we add the current element and its index to the hash map for future reference.

// Time Complexity: O(n), where n is the size of the array. We traverse the array once, and each lookup and insertion in the hash map is O(1) on average.
// Space Complexity: O(n), as we are using a hash map to store the elements of the array, which can grow up to the size of the input array in the worst case.

// bool Solution(vector<int>& arr, int n, int target, vector<int>& temp){
//     unordered_map<int, int> mp;

//     for(int i=0;i<n;i++){
//         int compliment = target - arr[i];
//         if(mp.find(compliment) != mp.end()){
//             temp.push_back(arr[mp[compliment]]);
//             temp.push_back(arr[i]);
//             return true;
//         }
//         mp[arr[i]] = i;
//     }
//     return false;
// }

//optimal approach
//sort arr, then iterate with 2 pointers
//if sum is less then left++
//else right ++
//if found return true;

bool Solution(vector<int>& arr, int n, int target ,vector<int>& temp ){
    if(n<=1) return false;

    sort(arr.begin(), arr.end());

    int left=0, right=n-1;

    while(left<right){
        int treasure = arr[left] + arr[right];
        if(treasure == target){
            temp.push_back(arr[left]);
            temp.push_back(arr[right]);
            return true;
        }
        if(treasure<target) left++;
        else right--;
    }
    return false;
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

    vector<int> temp;

    cout<<Solution(arr, n, target, temp)<<endl;

    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }

    return 0;
}
