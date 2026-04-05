#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force
// Algorithm
// Intuition
// As we know fib(i) = fib(i-1) + fib(i-2).Simply iterate and go on calculating the ith term in the series.

// Approach
// Take an array say fib of size n+1.The 0th term and 1st term are 0 and 1 respectively.So fib(0)=0 and fib(1)=1.
// Now iterate from 2 to n and calculate fib(n).fib(n)=fib(n-1) + fib(n-2).

// Time Complexity: O(n)+O(n), for calculating and printing the Fibonacci series.
// Space Complexity: O(n) for storing the fibonacci series.

// void Solution(vector<int>& arr, int n){
    
//     if(n==0) return;

//     arr[0] = 0;
//     if(n > 1) arr[1] = 1;
    
//     for(int i=2;i<n;i++){
//         arr[i] = arr[i-1] + arr[i-2];
//     }

//     for(int it:arr){
//         cout<<it<<" ";
//     }

//     return;
// }

// Better Approach
// Algorithm
// Intuition
// For calculating the ith term we only need the last and second last term i.e (i-1)th and (i-2)th term, so we don't need to maintain the whole array

// Approach
// Take two variables last and secondLast for storing (i-1)th and (i-2)th term.
// Now iterate from 2 to n and calculate the ith term. ith term is last + secondLast term.
// Then update secondLast term to the last term and the last term to ith term as we iterate.

// Time Complexity: O(N).As we are iterating over just one for a loop.
// Space Complexity: O(1), no extra space used.

// void Solution(vector<int>& arr, int n){
//     if(n==0) return;

//     int a=0;
//     int b=1;

//     if(n >= 1) cout << a << " ";
//     if(n >= 2) cout << b << " ";

//     for(int i=2;i<n;i++){
//         int c=a+b;
//         cout<<c<<" ";

//         a=b;
//         b=c;
//     }

// }

// Optimal Approach
// Algorithm
// Intuition
// In this approach, instead of printing the Fibonacci series till N, we’re going to print the Nth Fibonacci number using functional recursion with multiple function calls.

// Similar to all the recursion problems we’ve seen before, we need a base case in this problem too in order for recursion to not go infinitely. Here, we notice that the Fibonacci series start from N = 1, where we initialize its value as 1.
// Assume Fibonacci(0) = 0. So, Fibonacci(2) = 1+0 = 1 as the Nth Fibonacci number is the sum of the previous two Fibonacci numbers.
// Similarly, we call Fibonacci(N-1) and Fibonacci(N-2) and return their sum. Both the function calls Fibonacci(N-1) and Fibonacci(N-2) would be computed individually one by one until the base condition is reached for both and then they return back to the main function.
// Let us see the recursion tree for the following problem to get an even better understanding:

int Solution(int n){
    if(n<=1) return n;

    return Solution(n-1) + Solution(n-2);

}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n);

    return 0;
}
