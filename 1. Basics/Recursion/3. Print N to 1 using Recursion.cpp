#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Forward Recursion
// Algorithm
// To print numbers from n down to 1 using forward recursion, the approach involves defining a recursive function that takes the current number as a parameter. The function first checks if the current number is less than 1, if it is, the recursion terminates.
// Otherwise, it prints the current number and then recursively calls itself with the next number decremented by one. This way, the numbers are printed in descending order as the recursion unfolds forward from the base case down to 1. The key is to make the print statement before the recursive call, ensuring the numbers appear from n down to 1 in order.

// Time Complexity: O(N), we print every number from N to 1 using recursion[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]
// Space Complexity: O(N), stack space used for recursive calls.

// void Solution(int i, int n){
//     if(n<1) return;

//     cout<<n<<" ";

//     Solution(i, --n);
// }

// Backtracking
// Algorithm
// Backtracking builds solutions by exploring all options and undoing choices when needed. To print numbers from n down to 1 using backtracking, the function recursively calls itself with the previous number until it goes below 1. 
// After reaching the base case, it prints the numbers while returning from the recursion. This way, numbers are printed in ascending order because the print happens after the recursive call during backtracking. The main difference from forward recursion is that printing occurs on the way back, not before the recursive call.

// Time Complexity: O(N), we print every number from N to 1 using recursion
// Space Complexity: O(N), stack space used for recursive calls.

void Solution(int i, int n){
    if(n<1) return;

    Solution(i,n-1);
    cout<<n<<" ";

}

int main()
{
    int n;
    cin>>n;

    Solution(1 , n);

    return 0;
}
