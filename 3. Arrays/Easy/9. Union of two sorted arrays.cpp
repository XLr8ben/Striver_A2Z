#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>

using namespace std;
//brute force approach
//time complexity: O((n+m)log(n+m))
//space complexity: O(n+m)
vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        mp[arr2[i]]++;
    }

    vector<int> temp;
    for(auto it: mp){
        temp.push_back(it.first);
    }

    return temp;
}

// vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     set<int> s;

//     for(int i=0; i<n; i++){
//         s.insert(arr1[i]);
//     }

//     for(int i=0; i<m; i++){
//         s.insert(arr2[i]);
//     }

//     vector<int> temp(s.begin(), s.end());

//     return temp;
// }


//optimal approach
//time complexity: O(n+m)
//space complexity: O(n+m)
// vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     int i=0,j=0;

//     vector<int> temp;

//     while(i<n && j<m){
//         if(arr1[i]<arr2[j]){
//             temp.push_back(arr1[i]);
//             i++;
//         }
//         else if(arr1[i]>arr2[j]){
//             temp.push_back(arr2[j]);
//             j++;
//         }
//         else{
//             temp.push_back(arr1[i]);
//             i++;
//             j++;
//         }
//     }

//     while(i<n){
//         temp.push_back(arr1[i]);
//         i++;
//     }

//     while(j<m){
//         temp.push_back(arr2[j]);
//         j++;
//     }

//     return temp;
// }

int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);

    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    int n2;
    cin>>n2;
    vector<int> arr2(n2);

    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    vector<int> result = Solution(arr1, n1, arr2, n2);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
