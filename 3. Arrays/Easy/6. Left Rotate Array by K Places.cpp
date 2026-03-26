#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force
// Right Rotation: We store the last k elements of the array into a temporary array. Then we shift all the other elements (n-k elements) to the right by k positions. Finally, we place the elements from the temporary array at the beginning of the original array. This achieves a right rotation by k positions.
// Take the last k elements and store them in a temporary array.
// Shift the first n-k elements to the right by k positions.
// Copy the k stored elements from the temporary array to the start of the original array.

// Left Rotation: We store the first k elements in a temporary array. Then we shift the remaining n-k elements to the left by k positions. Finally, we copy the elements from the temporary array to the end of the array. This achieves a left rotation by k positions.
// Store the first k elements in a temporary array.
// Shift the remaining elements to the left by k positions.
// Copy the k stored elements to the end of the original array.

// Time Complexity: O(n), We are performing a constant number of linear operations copying `k` elements and shifting up to `n-k` elements.
// Space Complexity: O(k) ,A temporary array of size `k` is used to store either the first `k` or last `k` elements depending on the direction of rotation.

// void Solution(vector<int>& arr, int n, int pos, string dir){
//     vector<int> temp;

//     pos %= n;

//     if(dir == "left"){
//         for(int i = pos; i < n; i++){
//             temp.push_back(arr[i]);
//         }

//         for(int i = 0; i < pos; i++){
//             temp.push_back(arr[i]);
//         }
//     }
//     else if(dir == "right"){
//         for(int i = n - pos; i < n; i++){
//             temp.push_back(arr[i]);
//         }

//         for(int i = 0; i < n - pos; i++){
//             temp.push_back(arr[i]);
//         }
//     }

//     for(int i = 0; i < n; i++){
//         arr[i] = temp[i];
//     }
// }

// Optimal Approach
// Instead of simulating each rotation one by one, we can get the rotated array in-place by reversing specific parts of the array. This works because rotating is just rearranging sections of the array.
// For Right Rotation by k steps:
// Reverse the entire array
// Reverse the first k elements
// Reverse the remaining n - k elements
// For Left Rotation by k steps:
// Reverse the first k elements
// Reverse the remaining n - k elements
// Reverse the entire array
// Normalize k by doing k = k % N
// If direction is "right":
// Reverse the entire array
// Reverse the first k elements
// Reverse the rest (from k to end)
// If direction is "left":
// Reverse the first k elements
// Reverse the rest (from k to end)
// Reverse the entire array

// Time Complexity: O(N), where N is the size of the array. This is because we traverse the array once to shift the elements.
// Space Complexity: O(1), as we are changing the same array
void reverseArr(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void Solution(vector<int> &arr, int n, int pos, string dir)
{
    pos %= n;

    if (dir == "left")
    {
        reverseArr(arr, 0, pos - 1);
        reverseArr(arr, pos, n - 1);
        reverseArr(arr, 0, n - 1);
    }
    else if (dir == "right")
    {
        reverseArr(arr, 0, n - 1);
        reverseArr(arr, 0, pos - 1);
        reverseArr(arr, pos, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int pos;
    cin >> pos;

    string dir;
    cin>>dir;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution(arr, n, pos, dir);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}
