#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// Algorithm
// Create a set to keep only unique groups of four numbers.
// Use the first loop from the start of the array to the end to choose the first number.
// Inside it, run a second loop starting from the next position to choose the second number.
// Then, run a third loop starting from the next position after the second number to choose the third number.
// Finally, run a fourth loop starting from the next position after the third number to choose the fourth number.
// Check if the total of these four numbers equals the target value.
// If yes, arrange the four numbers in order and add them to the set.
// Once all loops are done, return the set as a list of unique groups of four numbers.

// Time Complexity: O(N^4 * log K) where N = size of array, K = number of unique quadruplets
// Reason: 4 nested loops generate all combinations, and inserting into set takes O(log K).
// Space Complexity: O(K). Reason: Set stores all unique quadruplets.

// void Solution(vector<int>& arr, int n, int x){
//     set<vector<int>> st;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 for(int l=k+1;l<n;l++){
//                     if(arr[i]+ arr[j] + arr[k] + arr[l] == x){
//                         vector<int> temp = { arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());

//     for(auto ele: ans){
//         for(int c: ele){
//             cout<<c<<" ";
//         }
//         cout<<endl;
//     }
// }

// Better Approach
// Algorithm
// Create a set to keep only unique groups of four numbers.
// Run the first loop from the start to the end of the array to pick the first number.
// Inside it, run the second loop from the next position to pick the second number.
// Before starting the third loop, make a HashSet to keep track of numbers between the second and third positions.
// Run the third loop from the next position after the second number to the end of the array to pick the third number.
// Find the fourth number by subtracting the total of the first three numbers from the target value.
// If this fourth number is already in the HashSet, arrange all four numbers in order and add them to the set.
// Add the current third number to the HashSet (only numbers between the second and third loops are stored).
// After all loops finish, return the set as a list of unique groups of four numbers.

// Time Complexity: O(N3*log(M)), as we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.
// Space Complexity: O(2 * no. of the quadruplets)+O(N), as we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).

// void Solution(vector<int>& arr, int n, int x){
//     set<vector<int>> st;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){

//             set<int> hashset;

//             for(int k=j+1;k<n;k++){
//                 int target = x-(arr[i] + arr[j] + arr[k]);
//                 if(hashset.find(target) != hashset.end()){
//                     vector<int> temp = { arr[i], arr[j], arr[k], target};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }

//     for(auto ele: st){
//         for(int x: ele){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
// }

// Optimal Approach
// Algorithm
// Sort the array first.
// Use the first loop to pick the first number. Skip it if it is the same as the previous one to avoid duplicates.
// Inside it, use the second loop to pick the second number. Also skip it if it repeats the previous one.
// Set two pointers: one just after the second number (left pointer) and one at the end of the array (right pointer).
// While the left pointer is before the right pointer, calculate the total of the four chosen numbers.
// If the total equals the target, save the quadruplet, then move both pointers while skipping duplicate numbers.
// If the total is less than the target, move the left pointer one step forward to increase the total.
// If the total is greater than the target, move the right pointer one step backward to reduce the total.
// After all loops finish, return the list of unique groups of four numbers.

// Time Complexity: O(N3), as Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 
// Space Complexity: O(no. of quadruplets), as This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).

void Solution(vector<int>& arr, int n, int x){
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;

        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;

            int k=j+1, l=n-1;
            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if(sum>x) l--;
                else if(sum<x) k++;
                else{
                    vector<int> temp = { arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }
            }
        }
    }

    for(auto ele: ans){
        for(int x: ele){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    
    int x;
    cin>>x;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    Solution(arr, n, x);

    return 0;
}
