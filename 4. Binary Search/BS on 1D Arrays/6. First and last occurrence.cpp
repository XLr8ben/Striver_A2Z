#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// First Occurrence

int firstOcc(vector<int>& arr, int n, int x){
    int low=0, high=n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }else
            low = mid + 1;
    }
    return ans;
}

// Last Occurrence

int lastOcc(vector<int>& arr, int n, int x){
    int low=0, high=n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] <= x){
            ans = mid;
            low = mid + 1;
        }else
            high = mid - 1;
    }
    return ans;
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

    int fe = firstOcc(arr, n, x);

    if(fe == -1) cout<<"-1 -1";
    else{
        int ls = lastOcc(arr, n, x);
        cout<<fe<<" "<<ls;
    }

    return 0;
}
