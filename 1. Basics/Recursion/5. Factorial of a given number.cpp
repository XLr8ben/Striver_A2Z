#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Iterative Solution
// Algorithm
// Since the factorial of a number X is the product of the number itself and all its preceding positive integers, we can calculate it using a loop.
// We initialize a variable (say fact) to 1, which will hold the running product.
// We run a loop from i = 1 to X.
// In each iteration, we multiply fact by i (i.e., fact = fact * i).
// After the loop ends, fact will contain the factorial of X.

// Time Complexity: O(n)
// Space Complexity: O(1)

// int Solution(int n){
//     int ans = 1;
//     for(int i=n;i>=1;i--){
//         ans *= i;
//     }

//     return ans;
// }

// Recursive Solution
// Algorithm
// The factorial of a number N can be calculated by multiplying all natural numbers from 1 to N.
// We can visualize this using recursion:
// factorial(N) = N * factorial(N - 1)
// This means the factorial of N is the product of N and the factorial of N - 1.
// We define a base case:
// If N == 0, we return 1, since 0! = 1 by definition.
// This approach breaks the problem into smaller subproblems, and the results of each subproblem are multiplied together as the recursive calls return.
// The final result is stored and printed as the output of the factorial(N) function.
// Recursion Tree for the following problem can be represented as follows :

// Time Complexity: O(N), Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N)
// Space Complexity: O(N), In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space.

int Solution(int n){
    if(n==1) return 1;

    return n * Solution(n-1);
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
