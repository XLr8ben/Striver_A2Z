#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// A B C
// A B
// A

// Algorithm
// Intuition: This pattern prints rows of decreasing-length alphabet sequences starting from 'A'. In the first row, it prints from 'A' to 'E', in the second from 'A' to 'D', and so on, reducing by one letter each row.

// The outer loop runs for N rows (from 0 to N-1).
// In the inner loop, for each row i, we print characters from 'A' up to 'A' + (N - i - 1).
// This ensures that the number of characters decreases by 1 with each row.
// After each inner loop finishes, print a newline to move to the next row.

// Time Complexity: O(N²), due to the total number of characters printed.
// Space Complexity: O(1), only loop variables are used.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<'A'+n-i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Solution(n);

    return 0;
}
