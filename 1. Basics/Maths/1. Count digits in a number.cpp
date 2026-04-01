#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach

// To count the number of digits in a number, we can use the algorithm created in Extract Digits as now instead of extracting digits we are simply creating a counter to count the number of digits in the number..

// Initialise a counter to store the number of digits.
// While N is greater than 0, execute the following:
// Increment the counter by 1
// Update N by removing its last digit by performing a modulo 10 (%10) operation on it.
// After exiting the while loop, we return the counter as the number of digits.

// Complexity Analysis

// Time Complexity: O(log10N + 1), where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10N + 1.
// In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations.
// In each iteration of the while loop we perform constant time operations like division and increment the counter.
// Space Complexity : O(1), as only a constant amount of additional memory for the counter regardless of size of the input number.

// int Solution(int n){
//     int cnt=0;

//     while(n>0){
//         cnt++;
//         n/=10;
//     }
//     return cnt;
// }

// Optimal Approach
// Algorithm
// The logarithmic base 10 of a positive integers gives the number of digits in n. We add 1 to the result to ensure that the count is correct even for numbers that are powers of 10.

// We cast the result to an integer to ensure that any fractional part is discarded giving the exact count of digits.

// Algorithm

// Initialise a variable to store the count of digits of the number.
// The count of digits can be calculated using log10 N + 1.
// log10 N operation gives the logarithmic base 10 of which returns the power to which 10 must be raised to, to be equal to N.
// We add 1 to the result which accounts for the possibility that N itself is a power of 10.
// Financially cast the result to an integer to ensure that it is rounded down to the nearest whole number.
// Return the value of count which represents the count of digits in the input integer N

// Time Complexity: O(1), as simple arithmetic operations in constant time are computed on integers.
// Space Complexity : O(1), as only a constant amount of additional memory for the count variable regardless of size of the input number.

int Solution(int n){
    int cnt = (int)(log10(n)+1);

    return cnt;
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
