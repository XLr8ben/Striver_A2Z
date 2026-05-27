#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

// Brute Force Approach
// Algorithm
// If m > n: In this case, book allocation is not possible and so, we will return -1.
// Next, we will find the maximum element and the summation of the given array.
// We will use a loop(say pages) to check all possible pages from max(arr[]) to sum(arr[]).
// Next, inside the loop, we will send each ‘pages’, to the function countStudents() function to get the number of students to whom we can allocate the books.
// The first number of pages, ‘pages’, for which the number of students will be equal to ‘m’, will be our answer. So, we will return that particular ‘pages’.
// Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.

// Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[])
// Space Complexity:  O(1) as we are not using any extra space to solve this problem.

int isPossible(vector<int>& arr, int n, int capacity, int students){
    int pages=0, cntStudents=1;

    for(int i=0;i<n;i++){
        if(pages+arr[i] <= capacity) pages += arr[i];
        else{
            cntStudents++;
            pages = arr[i];
        }
    }
    return (cntStudents<=students);
}

// int Solution(vector<int>& arr, int n, int students){
//     if(students > n) return -1;
    
//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);
    
//     int ans=0;

//     for(int i=low;i<=high;i++){
//         if(isPossible(arr, n, i, students)) return i;
//     }
//     return -1;
// }

// Optimal Approach
// Algorithm
// This problem is solved using Binary Search to efficiently find the best way to distribute books among students.
// The main idea is to cut the search range in half each time by checking whether a certain number of pages per student is possible or not.
// The possible range of answers lies between the largest book (since no student can receive less than the largest book) and the total number of pages (which means giving all books to one student).
// First, if there are more students than books, it's impossible to assign at least one book to each student, so we return -1.
// Next, we search between the minimum and maximum possible values:
// The minimum possible is the largest single book (because every student must get at least one complete book).
// The maximum possible is the sum of all pages (if one student reads all books).
// We perform Binary Search:
// We try a middle value of pages per student.
// We check how many students would be required if no student gets more than that value.
// If it takes more students than allowed, that value is too low, so we try a higher one.
// If it fits within the allowed number of students, we store it and try a smaller one to find an even better option.
// Eventually, we land on the smallest value that works this is our answer.
// Note: After the binary search loop ends, the pointer will be on the smallest possible maximum number of pages per student. That's why it gives the correct result directly.

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
// Space Complexity:  O(1) as we are not using any extra space to solve this problem.

int Solution(vector<int>& arr, int n, int students){
    if(students > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;
    
        if(isPossible(arr, n, mid, students)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    int students;
    cin>>students;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Solution(arr, n, students)<<endl;

    return 0;
}
