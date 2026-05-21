#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Floor
// We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).

// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
// Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// Case 1 - If arr[mid] <= x: The index arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
// Case 2 - If arr[mid] > x: arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.

// Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm
// Space Complexity: O(1). No extra space used

int floorval(vector<int>& arr, int n, int x){
    int low=0, high=n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }else
            high = mid - 1;
    }
    return ans;
}

// Ceil
// We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).

// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
// Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// Case 1 - If arr[mid] >= x: This condition means that the index arr[mid] may be an answer. So, we will update the ‘ans’ variable with arr[mid] and search in the left half if there is any smaller number that satisfies the same condition. Here, we are eliminating the right half.
// Case 2 - If arr[mid] < x: In this case, arr[mid] cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.

// Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm
// Space Complexity: O(1). No extra space used

int cielval(vector<int>& arr, int n, int x){
    int low=0, high=n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid - 1;
        }else
            low = mid + 1;
    }
    return ans;
}

//another approach for ciel is = (a + b - 1) / b ;

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

    cout<<"Floor val is "<<floorval(arr, n, x)<<endl;
    cout<<"Ciel val is "<<cielval(arr, n, x)<<endl;

    return 0;
}
