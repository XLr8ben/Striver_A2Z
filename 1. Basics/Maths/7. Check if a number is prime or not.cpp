#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach
// Algorithm
// We can iterate through numbers from 1 to n, counting how many of these numbers divide n without a remainder. If exactly two numbers do, so n is prime otherwise it is not prime.

// Algorithm:

// Step 1:Initialise a variable cnt to count the number of factors and set it to 0.

// Step 2:Start a loop from 1 to n, iterating through each number i. Inside the loop:

// Check if n is divisible by i without any remainder.
// If it is, increment the counter variable by 1.
// Step 3:After the loop if the number of divisors is equal to 2, return true indicating the number is prime.

// If the number of divisors is not equal to 2 (but greater), return false indicating that the number is not prime.

// Time Complexity: O(N), as we iterate from 1 to N performing constant-time operation for each iteration.
// Space Complexity : O(1), as the space used by the algorithm does not increase with the size of the input.

// bool Solution(vector<int>& arr, int n){
//     int cnt=0;

//     for(int i=1;i<=n;i++){
//         if(n%i==0) cnt++;
//     }

//     return (cnt==2) ? 1 : 0;
// }

// Optimal Approach
// Algorithm
// We can optimise the algorithm by only iterating up to the square root of n when checking for factors. This is because if n has a factor greater than its square root, it must also have a factor smaller than its square root.

// This property is symmetric about the square root of n by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm. Discusses in detail here:Print All Divisiors

// Algorithm

// Step 1: Initialise a counter variable cnt to count the number of factors to 0.

// Step 2: Begin a loop from 1 to the square root of n. This loop iterates through possible factors of n. For each value of i within the loop:

// Check if n is divisible by i without any remainder.
// If n is divisible by i, it means i is a factor of n, so increment the counter variable cnt by 1.
// Check if the reciprocal factor of i ie. n/i is not equal to i. If they are not equal, it means there is a distinct factor so increment cnt by 1 again.
// Step 3: After the loop, cnt will contain the total numbers of factors of n.

// Step 4: Check if the value of cnt is exactly 2, it means that n has exactly two distinct factors (1 and itself), indicating that it is a prime number.

// If the the number of factors is greater than 2 then it is a composite number, return false.

// Time Complexity: O(sqrt(N)), as The loop iterates up to the square root of n performing constant time operations at each step.
// Space Complexity : O(1), as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.

bool Solution(int n){
    if(n <= 1) return false;
    if(n == 2) return true;

    if(n%2==0) return false;

    for(int i=3;i*i<=n;i++){
        if(n%i==0) return false; 
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
