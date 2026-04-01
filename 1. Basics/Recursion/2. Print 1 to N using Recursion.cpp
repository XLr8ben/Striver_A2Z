#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Forward Recursion
// Algorithm
// To print numbers from 1 to n using forward recursion, the approach involves defining a recursive function that takes the current number as a parameter. The function first checks if the current number exceeds n; if it does, the recursion terminates.
// Otherwise, it prints the current number and then recursively calls itself with the next number incremented by one. This way, the numbers are printed in ascending order as the recursion unfolds forward from the base case to the maximum number. The key is to make the print statement before the recursive call, ensuring the numbers appear from 1 up to n in order.

// Time Complexity: O(N), we print every number from 1 to N using recursion
// Space Complexity: O(N), stack space used for recursive calls.

// void Solution(int i, int n){
//     if(i>n) return;

//     cout<<i<<" ";
//     Solution(++i,n);
// }

// Backtracking
// Algorithm
// Backtracking builds solutions by exploring all options and undoing choices when needed. To print numbers from 1 to n using backtracking, the function recursively calls itself with the next number until it passes n.
// After reaching the base case, it prints the numbers while returning from the recursion. This way, numbers are printed in reverse order because the print happens after the recursive call during backtracking. The main difference from forward recursion is that printing occurs on the way back, not before the recursive call.

// Time Complexity: O(N), we print every number from 1 to N using recursion
// Space Complexity: O(N), stack space used for recursive calls.

void Solution(int i, int n){
    if(i>n) return;

    Solution(i+1,n);
    cout<<i<<" ";
}

int main()
{
    int n;
    cin>>n;

    Solution(1,n);

    return 0;
}
