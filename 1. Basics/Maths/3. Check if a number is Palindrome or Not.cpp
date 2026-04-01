#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm / Intuition
// To check if a number is a palindrome, we can use the algorithm created in Extract Digits as now we extract the digits of the number to create a reversed number.

// We then compare the reversed number with the original number. If they are equal, the original number is a palindrome. If they are not equal the original number is not a palindrome.

// Algorithm
// Initialise an integer revNum to 0. This variable will store the reverse of the number.
// Make a duplicate of the original number and store it in an integer dup for later comparison.
// Run a while loop with the condition n>0 to reverse the number and at each iteration
// Get the last digit of n by using the modulus operator % with 10 and store it in a temporary variable ld.
// Update the revNum by multiplying it by 10 and adding the last digit ld.
// Update n by integer division with 10 effectively removing the last digit.
// After the loop, check if the original number dup is equal to the reversed number revNum.
// If they are equal, return true indicating the number is a palindrome.
// If they are not equal, return false indicating that the number is not a palindrome.

// Time Complexity: O(log10N + 1), as in the worst case when N is a multiple of 10 the number of digits in N is log10 N + 1. In the while loop we divide N by 10 until it becomes 0 which takes log10N iterations. In each iteration of the while loop we perform constant time operations like modulus and division and pushing elements into the vector.
// Space Complexity: O(1), as only a constant amount of additional memory for the reversed number regardless of size of the input number.

bool Solution(int n){
    int revNum = 0;
    int dup = n;

    while (n > 0) {
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }

    if (dup == revNum) {
        return true;
    } else {
        return false;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    cout<<Solution( n)<<endl;

    return 0;
}
