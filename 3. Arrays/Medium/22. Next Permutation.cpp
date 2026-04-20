#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

//brute force
//1. Generate all sequence in sorted
//2. Linear search
//3. Next index

// Time Complexity: O(N!*N), since we are generating all possible permutations, it takes N! time.
// Space Complexity: O(N!), storing all permutations.

// void permutation(vector<int>& arr, int n, vector<int>& temp, vector<bool> used, vector<vector<int>>& ans){
//     if(temp.size()==n){
//         ans.push_back(temp);
//         return;
//     }

//     for(int i=0;i<n;i++){
//         //for duplicates
//         if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;

//         if(!used[i]){
//             temp.push_back(arr[i]);
//             used[i] = true;
//             permutation(arr, n, temp, used, ans);
//             temp.pop_back();
//             used[i] = false;
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> arr(n);

//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     vector<bool> used(n, false);


//     vector<int> temp;

//     vector<vector<int>> ans;

//     sort(arr.begin(), arr.end());

//     permutation(arr, n, temp, used, ans);

//     for(int i=0;i<ans.size();i++){
//         if(ans[i]==arr){
//             if(i==ans.size()-1){
//                 for(int ele: ans[0]){
//                     cout<<ele<<" ";
//                 }
//             }
//             else {
//                 for(int ele: ans[i+1]){
//                     cout<<ele<<" ";
//                 }
//             }
//         }
//     }

//     //print all permutations
    
//     // for(auto& perm:ans){
//     //     for(int ele:perm){
//     //         cout<<ele<<" ";
//     //     }
//     //     cout<<"\n";
//     // }

//     return 0;
// }


//optimal approach

// We want to rearrange the array to form the next greater permutation. If that's not possible (i.e., it's the last permutation), we return the smallest one (i.e., sorted ascendingly).
// To find this next permutation with minimal change, we need to find a digit that can be increased slightly to make the number bigger and then rearrange the remaining part to be the smallest possible.
// Traverse from the end and find the first index where the current digit is smaller than the next one (this is the "breaking point").
// Then again traverse from the end to find the first digit greater than the breaking point digit and swap them.
// Finally, reverse the part of the array to the right of the breaking point to get the smallest next permutation.
// If no such breaking point exists (entire array is descending), just reverse the whole array.

// Time Complexity: O(N), we find the breaking point and reverse the subarray in linear time.
// Space Complexity: O(1), constant additional space is used.


void Solution(vector<int>& arr, int n){
    int idx=-1;

    for(int i=n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        return reverse(arr.begin(), arr.end());
    }

    for(int i=n-1;i>=0;i--){
        if(arr[i] > arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());
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
