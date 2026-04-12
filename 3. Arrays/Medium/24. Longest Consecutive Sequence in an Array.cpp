#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;

//brute forch approach

//pick 1 element, iterate another loop if ++ found of ele then resets another loop to find its consequetive element
//increment count of consequetive elememts 
//store maximum count in ans, return ans

//Time Complexity: O(n2)
//Space Complexity: O(1)

// int Solution(vector<int> &arr, int n)
// {
//     int ans = 1;

//     for (int i = 0; i < n; i++)
//     {

//         int x = arr[i];
//         int cnt = 1;

//         for (int j = 0; j < n; j++)
//         {
//             if (x + 1 == arr[j])
//             {
//                 cnt++;
//                 x = arr[j];
//                 j=-1;
//             }
//             ans = max(cnt, ans);
//         }
//     }

//     return ans;
// }   

//better approach 

//sort the array
//interate and find the exactly next element in array if count cnt++, if not reset cnt
//store max cnt in ans;

//Time Complexity: O(n logn)
//Space Complexity: O(1)
// int Solution(vector<int> arr, int n){
    
//     sort(arr.begin(), arr.end());
    
//     int ans=1, cnt=1;
//     int lastele = arr[0];

//     for(int i=1;i<n;i++){
//         if(arr[i]==lastele) continue;
//         else if(arr[i]==lastele+1) cnt++;
//         else{
//             cnt=1;
//         }
//         lastele=arr[i];
//         ans = max(ans, cnt);
//     }
//     return ans;
// }

// Optimal Approach
// Algorithm
// We will use two variables: cnt to store the length of the current sequence and longest to store the maximum length found.
// First, place all the array elements into a set data structure to allow efficient lookups for consecutive numbers.
// For each element x that can start a sequence (i.e., x - 1 does not exist in the set), we follow these steps:
// Initialize cnt to 1, indicating the starting element of a new sequence.
// Use the set to search for consecutive elements such as x + 1, x + 2, and so on, to determine the maximum possible length of the current sequence. Update cnt accordingly.
// Compare cnt with longest and update longest to hold the maximum value: longest = max(longest, cnt).
// Finally, longest will contain the length of the longest consecutive sequence found in the array.

// Time Complexity: O(n), where n is the number of elements in the array. This is because we traverse each element once to build the set and then again to find the longest consecutive sequence.
// Space Complexity: O(n), as we use a set to store the unique elements of the array, which in the worst case can be equal to the size of the input array.

int Solution(vector<int> arr, int n){
    int ans = 0;

    unordered_set<int> st;

    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}



int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    cout << Solution(arr, n) << endl;

    return 0;
}
