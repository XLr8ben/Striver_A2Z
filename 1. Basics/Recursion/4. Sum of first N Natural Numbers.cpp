#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach
// Algorithm
// The most straightforward way to find the sum of the first N natural numbers is to iterate from 1 to N and keep adding each number to a running total. This approach is beginner-friendly and easy to understand because it directly mimics the problem definition. However, it is less efficient than the formula-based approach since it requires looping through all numbers, which means more time complexity when N is large.
// Initialize a variable to store the sum as 0.
// Start a loop from 1 and go up to the given number.
// In each iteration, add the current number to the sum.
// After the loop finishes, the sum variable will hold the result.
// Return or print the sum.

// Time Complexity: O(N),We iterate from 1 to N once, performing a constant-time addition operation in each iteration, resulting in linear time complexity.
// Space Complexity: O(1),We only use a few variables to store the sum and loop counter, so the space usage remains constant regardless of N.

// int Solution(int n){
//     int sum=0;

//     for(int i=1;i<=n;i++){
//         sum += i;
//     }
//     return sum;
// }

// Using Formula
// Algorithm
// We can use the formula for the sum of N numbers, i.e N(N+1)/2.
// Take a variable sum.
// Initialize it with N(N+1)/2, where N is a given number.

// Time Complexity: O(1)
// Space Complexity: O(1)

// int Solution(int n){
//     return (n * (n+1)) / 2;
// }

// Recursive Approach
// Algorithm
// Instead of looping, we can solve the problem using recursion by defining the sum of the first N natural numbers as:

// sum(N) = N + sum(N-1), with the base case sum(1) = 1.

// Recursive way of calculating the sum of first N Natural Numbers:
// Define a recursive function to calculate the sum of natural numbers.
// If the input is the smallest natural number, return it directly as the base case.
// Otherwise, add the current number to the result of calling the same function with the previous number.
// Repeat this process until the base case is reached.
// The results from each call combine to give the final sum.

// Time Complexity: O(N),The function is called N times, with each call performing O(1) work.
// Space Complexity: O(N),Due to recursive function calls being stored on the call stack, which grows linearly with N.

int Solution(int n){
    if(n==1) return 1;

    return n + Solution(n-1);
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
