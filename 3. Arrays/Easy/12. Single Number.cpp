#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//brute force approach
//time complexity: O(n^2)
//space complexity: O(1)
int Solution(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        bool found = false;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j] && i!=j){
                found = true;
                break;
            }
        }
        if(!found) return arr[i];
    }

    return -1;

}


//optimal approach
//time complexity: O(n)
//space complexity: O(1)
// int Solution(vector<int>& arr, int n){
//     int ans=0;

//     for(int i=0;i<n;i++){
//         ans = ans ^ arr[i];
//     }

//     return ans;
// }

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
