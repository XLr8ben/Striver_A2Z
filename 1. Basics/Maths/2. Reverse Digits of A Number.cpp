#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm
// We know that extracting digits of a number can be done by repeatedly taking modulo 10 and dividing by 10. Now, instead of just extracting digits, if we build a new number by appending these digits in reverse order, we effectively reverse the number. Each new digit becomes the least significant digit of the reversed number by multiplying the current reversed value by 10 before adding the digit.
// Initialize a variable to store the reversed number as 0.
// Loop while the original number is greater than 0.
// Extract the last digit by performing modulo 10.
// Multiply the reversed number by 10 and add the extracted digit.
// Remove the last digit from the original number using integer division by 10.
// Continue this process until the original number becomes 0.
// Return the reversed number.

// Time Complexity: O(log₁₀N),The number of iterations in the loop depends on the number of digits in the number N. Since each digit is processed once using constant time operations (modulo, division, multiplication, and addition), the total time taken is proportional to the number of digits, which is log₁₀N.
// Space Complexity: O(1),Only a constant number of variables are used regardless of the size of the input number.

int Solution(int n){
    int ans=0;

    while(n>0){
        int digit = n%10;
        ans = ans*10 + digit;
        n/=10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    cout<<Solution(n)<<endl;

    return 0;
}
