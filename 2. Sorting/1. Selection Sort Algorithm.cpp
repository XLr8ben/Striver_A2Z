#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Approach
// Algorithm
// First, we will select the range of the unsorted array using a loop (say i) that indicates the starting index of the range. The loop will run forward from 0 to n-1. The value i = 0 means the range is from 0 to n-1, and similarly, i = 1 means the range is from 1 to n-1, and so on. (Initially, the range will be the whole array starting from the first index.)
// Now, in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
// After that, we will swap the minimum element with the first element of the selected range(in step 1).
// Finally, after each iteration, we will find that the array is sorted up to the first index of the range.

// Time Complexity:O(N^2),Selection sort runs in O(N²) time in the best, average, and worst cases due to its nested loop structure. It makes approximately N(N-1)/2 comparisons, regardless of the array's initial state. Even if no swaps are needed (best case), the number of comparisons remains the same./p>
// Space Complexity: O(1). No extra space used

int Solution(vector<int>& arr, int n){
    for(int i=0;i<n;i++){
        int mini = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]) mini=j;
        }

        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    return 0;
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
