#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// brute force (no duplicates)

// Sort the array in ascending order.
// The element at the second index (index 1) is the second smallest element.
// The element at the second index from the end (index length-2) is the second largest element.

// Time Complexity: O(N log N), for sorting the array.
// Space Complexity: O(1), as we are using a constant amount of space for variables.

// int getElements(vector<int>& arr, int n)
// {
//     if(n == 0 || n == 1) return -1;
    
//     sort(arr, arr + n);

//     int small = arr[1]; 
//     int large = arr[n - 2]; 

//     return large;
// }

//better approach
// Perform a single traversal to find the smallest and largest elements in the array.
// After that, traverse the array again to find the element just greater than the smallest element (this will be the second smallest).
// Similarly, find the element just smaller than the largest element (this will be the second largest).

// Time Complexity: O(N), we do two linear traversals in our array.
// Space Complexity: O(1), as we are using a constant amount of space for variables.

// void getElements(vector<int>& arr, int n){

//     if(n==0 || n==1) cout<<-1<<" "<<-1;

//     else{
//         int small=INT_MAX, secS=INT_MAX;
//         int larg=INT_MIN, secl=INT_MIN;

//         for(int i=0;i<n;i++){
//             if(arr[i] > larg) larg = arr[i];
//             if(arr[i] < small) small = arr[i];
//         }

//         for(int i=0;i<n;i++){
//             if(arr[i]>small && secS > arr[i]) secS = arr[i];
//             if(arr[i]<larg && secl < arr[i]) secl = arr[i];
//         }

//         cout<<secS<<" "<<secl;
//     }
// }

// //Optimal approach
// We will need four variables: small, second_small, large, and second_large. Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.
// Second Smallest Algorithm:
// If the current element is smaller than 'small', update the values of second_small and small.
// Else if the current element is smaller than 'second_small', update the value of second_small.
// After traversing the array, the second smallest element will be stored in the variable second_small.
// Second Largest Algorithm:
// If the current element is larger than 'large', update the values of second_large and large.
// Else if the current element is larger than 'second_large', update the value of second_large.
// After traversing the array, the second largest element will be stored in the variable second_large.

// Time Complexity: O(N), we do two linear traversals in our array.
// Space Complexity: O(1), as we are using a constant

int secondSmallest(vector<int>& arr, int n) {
    if (n < 2)
        return -1;

    int small = INT_MAX;
    int second_small = INT_MAX;

    for (int i = 0; i < n; i++) {
       if(arr[i] < small){
        second_small = small;
        small = arr[i];
       }
       else if(arr[i]>small && arr[i]<second_small) second_small = arr[i];
    }
    return second_small;
}

int secondLargest(vector<int>& arr, int n) {
    if (n < 2)
        return -1;

    int large = INT_MIN, second_large = INT_MIN;

    for (int i = 0; i < n; i++) {
       if(arr[i]>large){
        second_large = large;
        large = arr[i];
       }
       else if(arr[i]<large && arr[i]>second_large) second_large = arr[i];
    }
    return second_large;
}



int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    // getElements(arr, n);

    int sS = secondSmallest(arr, n);
    int sL = secondLargest(arr, n);

    cout << sS << " " << sL;

    return 0;
}