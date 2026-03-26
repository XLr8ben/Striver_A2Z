#include<iostream>
#include<vector>

using namespace std;

//Brute Force Approach
// The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its future elements that are present in the array.
// If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element until the whole array is traversed.
// If any of the picked elements is greater than its future elements, Then simply we will return False.
// If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully then we will simply return True.


// Time Complexity: O(N2), as it uses two nested loops to compare every pair of elements in the array.
// Space Complexity: O(1), as no extra space is used apart from a few variables.

// bool isSorted(vector<int>& arr, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[i]) 
//                 return false;
//         }
//     }
//     return true;
// }

//Optimal Approach
// As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
// So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
// We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
// If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). Then we will return True else return False.

// Time Complexity: O(N), as it checks each adjacent pair once in a single pass through the array.
// Space Complexity: O(1), as it uses constant extra space regardless of input size.

bool isSorted(vector<int>& arr, int n){
    int cnt=0;

    for(int i=1;i<n;i++){
        // cout<<"arr "<<arr[i-1]<<" == "<<arr[i]<<endl;
        if(arr[i]<arr[i-1]) cnt++;
    }

    // cout<<cnt<<endl;

    if(arr.front()<arr.back()) cnt++;
    // cout<<cnt<<endl;

    return cnt<=1;
}

int main() {

    int sz;
    cin>>sz;

    vector<int> arr(sz);

    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
   
    cout<<isSorted(arr,sz);
    
    return 0;
}
