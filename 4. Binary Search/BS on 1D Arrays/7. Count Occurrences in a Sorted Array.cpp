#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Optimal Approach
// Algorithm
// In the previous article, we discussed how to find the first and the last occurrences of a number in a sorted array using Binary Search.
// The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
// Now in order to solve this problem, we are going to use the previous concept. We will find the first and the last occurrences and figure out the number of occurrences like the following:
// Total number of occurrences = last occurrence - first occurrence + 1
// Algorithm:
// We will get the first and the last occurrences of the number using the function firstAndLastPosition(). For the implementation details of the function, please refer to the previous article.
// After getting the indices, we will check the following cases:
// If the first index == -1: This means that the target value is not present in the array. So, we will return 0 as the answer.
// Otherwise: We will find the total number of occurrences like this:
// The total number of occurrences  = (last index - first index + 1) and return this length as the answer.

// Time Complexity: O(2*logN), We are basically using the binary search algorithm twice.
// Space Complexity: O(1), as we are using no extra space.

// First Occurrence
int firstOcc(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

//Last Occurrence
int lastOcc(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int fe = firstOcc(arr, n, x);

    if (fe == -1)
        cout << "-1";
    else
    {
        int ls = lastOcc(arr, n, x);
        int cnt = ls - fe + 1;
        cout << cnt;
    }

    return 0;
}
