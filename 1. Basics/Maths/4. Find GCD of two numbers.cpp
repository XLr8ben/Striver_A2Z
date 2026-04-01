#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach
// Algorithm
// Intuition:
// The GCD of two numbers is the largest number that divides both of them without leaving a remainder. We iterate through all numbers from 1 up to the minimum of the two input numbers, checking if each number is a common factor of both input numbers.

// If a number is a common factor, we update our gcd variable to that number. This process continues until we have iterated through all possible common factors. Finally, we return the gcd variable, which will hold the greatest common divisor of the two input numbers.

// Algorithm:
// Step 1: Initialise a variable gcd to 1. This variable will store the greatest common divisor of the input numbers n1 and n2.

// Step 2: Iterate from 1 to the minimum of n1 and n2.

// We start from 1 because the GCD of any two numbers is at least 1, and it cannot be greater than the smaller of the two numbers.
// Step 3: At each iteration, if i is a common factor of both n1 and n2 update the gcd variable to i. We keep updating gcd as long as we find common factors.

// Step 4: After the iteration, the gcd variable will store the greatest common divisor of n1 and n2. Return this value as the output of the function.

// Time Complexity: O(min(N1, N2)) where N1 and N2 is the input number. The algorithm iterates from 1 to the minimum of N1 and N2 and each iteration checks whether both the numbers are divisible by the current number (constant time operations).
// Space Complexity: O(1)as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.

// int Solution(int n1,int n2){
//     int gcd=0;

//     for(int i=1;i<=min(n1,n2);i++){
//         if(n1%i==0 && n2%i==0) gcd=i;
//     }

//     return gcd;
// }

// Better Approach
// Algorithm
// Intuition:
// We can optimise the time complexity of the previous approach. In the worst case, the loop iterates from 1 up to the minimum of N1 and N2. This could potentially result in a large number of iterations, especially when one input number is significantly larger than the other.

// If we iterate from the minimum of N1 and N2 down to 1, we reduce the number of iterations because we start from the potentially largest common factor and work downwards.

// The time complexity of this approach remains O(min(N1, N2)) but in practice, it will execute fewer iterations on average.

// Algorithm:
// Step 1: Iterate from the minimum of n1 and n2 because the greatest common divisor of two numbers cannot exceed the smaller number.

// Step 2: For each i in the iteration, we check if it is a common factor of both n1 and n2.

// If a common factor i is found, we return it as the gcd as we are iterating from the largest potential gcd to 1, the first common factor we encounter will be the greatest common divisor.
// Step 3: If the loop completes without finding any common factors we return 1. This is because 1 is always a divisor of any number any number hence is also the GCD of any pair of numbers where no other common factors exist.

// Time Complexity: O(min(N1, N2)) where N1 and N2 is the input number. The algorithm iterates from the minimum of N1 and N2 to 1 and each iteration checks whether both the numbers are divisible by the current number (constant time operations).
// Space Complexity: O(1) as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.

// int Solution(int n1, int n2){
//     int gcd=0;

//     for(int i=min(n1,n2);i>=1;i--){
//         if(n1%i==0 && n2%i==0) return i;
//     }

//     return -1;
// }

// Optimal Approach
// Algorithm
                            
// Euclidean Algorithm:

// The Euclidean Algorithm is a method for finding the greatest common divisor (GCD)
// of two numbers. It operates on the principle that the GCD of two numbers remains
// the same even if the smaller number is subtracted from the larger number.

// To find the GCD of n1 and n2 where n1 > n2:
// 1. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// 2. Once one becomes 0, the other is the GCD of the original numbers.

// Example:
// n1 = 20, n2 = 15

// gcd(20, 15) = gcd(20 - 15, 15) = gcd(5, 15)
// gcd(5, 15)  = gcd(15 - 5, 5)  = gcd(10, 5)
// gcd(10, 5)  = gcd(10 - 5, 5) = gcd(5, 5)
// gcd(5, 5)   = gcd(5 - 5, 5)  = gcd(0, 5)

// Hence, return 5 as the GCD.

// Time Complexity: O(min(N1, N2)) where N1 and N2 is the input number. The algorithm iterates from the minimum of N1 and N2 to 1 and each iteration checks whether both the numbers are divisible by the current number (constant time operations).
// Space Complexity: O(1) as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variable
    
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    cout<<gcd(n1,n2)<<endl;

    return 0;
}
