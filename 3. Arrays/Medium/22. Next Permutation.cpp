#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;


void permutation(vector<int>& arr, int n, vector<int>& temp, vector<bool> used, vector<vector<int>>& ans){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(!used[i]){
            temp.push_back(arr[i]);
            used[i] = true;
            permutation(arr, n, temp, used, ans);
            temp.pop_back();
            used[i] = false;
        }
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

    vector<bool> used(n, false);


    vector<int> temp;

    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    permutation(arr, n, temp, used, ans);

    for(auto& perm:ans){
        for(int ele:perm){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
