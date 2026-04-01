#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

using namespace std;

// Brute Force Approach
// Algorithm
// The brute force approach to find all the divisors of a number is to iterate through every number from 1 to N and 
// check whether it is a divisor or not. We can store all the divisors and return the list of divisors after iteration.

// Time Complexity: O(N), we check for every number from 1 to N.
// Space Complexity: O(N), extra space used for storing divisors.

// void Solution(int n){
    
//     for(int i=1;i<=n;i++){
//         if(n%i==0) cout<<i<<" ";
//     }
// }

// Optimal Approach
// We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n. This property is symmetric about the square root of N. Thus, by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm.
// Iterate from 1 to sqrt(N) and for every divisor found, if N/divisor is distinct, add that to the list of divisors as well.

// Time Complexity: O(sqrt(N)), we check for every number between 1 and sqaure root of N.
// Space Complexity: O(2*sqrt(N)), extra space used for storing divisors.

void Solution(int n){

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i<=n/2) cout<<n/i<<" ";
        } 
    }
}

int main()
{
    int n;
    cin>>n;

    Solution(n);

    return 0;
}


