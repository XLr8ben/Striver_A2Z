#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// A
// A B
// A B C
// A B C D
// A B C D E

// Algorithm
// Intuition: This pattern prints letters in a triangular format where each row starts from 'A' and goes up to a certain alphabet depending on the row number. The idea is to print increasing sequences of alphabets in each row.

// Use a nested loop where the outer loop runs for N rows (from 0 to N-1).
// In the inner loop, print characters starting from 'A' up to 'A' + i.
// This means row 0 will print just 'A', row 1 prints 'A B', and so on.
// After completing each row, print a newline to move to the next row.


// Time Complexity: O(N²), as the total number of characters printed is 1 + 2 + ... + N = O(N²).
// Space Complexity: O(1), only loop variables are used.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){
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
