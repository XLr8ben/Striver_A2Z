#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm
// In the iterative method, we did the following:
// Take an element from the unsorted array(using an outer loop).
// Place it in its corresponding position in the sorted part(using an inner loop).
// Shift the remaining elements accordingly.
// In recursive method we will do the following
// First, call the recursive function with the given array, the size of the array, and the index of the selected element(let's say i).
// Inside that recursive function, take the element at index i from the unsorted array.
// Then, place the element in its corresponding position in the sorted part(using swapping).
// After that, Shift the remaining elements accordingly.
// Finally, call the recursion increasing the index(i) by 1.
// The recursion will continue until the index reaches n(i.e. All the elements are covered). Base Case: if(i == n) return.


void Solution(vector<int>& arr, int i, int n){
    if(i>=n) return;

    int j=i-1;

    while(j>=0 && arr[j]>arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        j--;
    }

    Solution(arr, i+1, n);

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution(arr, 1, n);
    
    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}
