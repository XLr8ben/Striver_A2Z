#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
// Examples
// Approach
// Algorithm
// Calculate the number of digits in the input number and store it in k.
// Initialise a variable sum to 0. This variable will store the sum of each digit raised to the power of number of digits in number.
// Make a copy of the original number to store it in a temporary variable.
// Run a while loop with the condition n>0 and at each iteration:
// Get the last digit of n by using the modulus operator % with 10 and store it in a temporary variable ld.
// Add the digit ld raised to the power of k of the sum.
// Update n by integer division with 10 effectively removing the last digit.
// After the loop, check if the original input number is equal to the sum of the digits raised to the power of the number of digits in the number.
// If they are equal, return true indicating the number is an Armstrong number.
// If they are not equal, return false indicating that the number is not an Armstrong number.

// Complexity Analysis
// Time Complexity: O(log10N + 1) where N is the input number. The time complexity is determined by the number of digits in the input integer N. In the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1.
// Space Complexity: O(1) as only a constant amount of additional memory for the reversed number regardless of size of the input number.

int power(int digit, int x){
    int ans = 1;
    for(int i=0;i<x;i++){
        ans *= digit;
    }
    return ans;
}
bool Solution(int n){
    int cnt=0;
    int temp=n;
    int arms = n;

    while(temp>0){
        int digit = temp%10;
        cnt++;
        temp /= 10;
    }

    int ans=0;

    while(n>0){
        int digit=n%10;
        ans += power(digit, cnt);
        n/=10;
    }
    return ans==arms;
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
