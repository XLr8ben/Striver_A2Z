#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

//brute force
//take 2 pointers compare them and push smaller ele to DS (another array),
// finally treverse the DS and put back the ele to arrays.

// Time Complexity: O(N+M) + O(N+M)
// Space Complexity: O(N+M)

// void Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     int left = 0, right = 0;
//     vector<int> arr;

//     while(left<n && right<m){
//         if(arr1[left] <= arr2[right]){
//             arr.push_back(arr1[left++]);
//         }else{
//             arr.push_back(arr2[right++]);
//         }
//     }

//     while(left<n){
//         arr.push_back(arr1[left++]);
//     }
//     while(right<m){
//         arr.push_back(arr2[right++]);
//     }

//     for(int i=0;i<arr.size();i++){
//         if(i<n) arr1[i] = arr[i];
//         else arr2[i - n] = arr[i];
//     }

//     // Print arrays
//     cout << "Array 1: ";
//     for (int x : arr1) {
//         cout << x << " ";
//     }
//     cout << endl;

//     cout << "Array 2: ";
//     for (int x : arr2) {
//         cout << x << " ";
//     }
//     cout << endl;

// }

//optimal approach
//take 2 pointers and swap if [left] > [right]

// Time Complexity: O(min(N+M)) + O(n logn) + O(n logn)
// Space Complexity: O(1), constant additional space is used.

void Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
    int left = n-1;
    int right = 0;

    while(left >=0 && right<=m-1){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
 
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // Print arrays
    cout << "Array 1: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int x : arr2) {
        cout << x << " ";
    }
    cout << endl;

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr1(n);

    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    int m;
    cin>>m;
    vector<int> arr2(m);

    for(int i=0; i<m    ; i++){
        cin>>arr2[i];
    }

    Solution(arr1, n, arr2, m);

    return 0;
}
