#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//optimal approach
//time complexity: O(n)
//space complexity: O(1)
int Solution(vector<int>& arr, int n){
    int count = 0;
    int max_count = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            count++;
            max_count = max(max_count, count);
        }
        else count = 0;
    }

    return max_count;
}

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
