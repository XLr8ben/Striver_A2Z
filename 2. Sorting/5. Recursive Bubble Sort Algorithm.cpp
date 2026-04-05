#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm
// We will check in the first recursion call if any swap is taking place. If the array is already sorted no swap will occur and we will return from the recursion call.
// Thus the number of recursions will be just 1. And our overall time complexity will be O(N).

void bubblesort(vector<int>& arr, int n){
    if(n==1) return;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }

    bubblesort(arr, n-1);    
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubblesort(arr, n);
    
    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}
