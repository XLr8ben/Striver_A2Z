#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
// 0 1 0 1 0 1

// Algorithm
// Intuition: This pattern prints alternating 1s and 0s in each row, starting with 1 on even-indexed rows and 0 on odd-indexed rows. The value alternates after each print using basic toggling logic.

// Take an integer N as input representing the number of rows.
// Loop from 0 to N-1 to handle each row.
// If the row index is even, set the starting value to 1; otherwise, set it to 0.
// For each row, print i+1 numbers while toggling the value between 1 and 0 after each print.
// After printing each row, move to the next line.

// Time Complexity: O(N²), due to the nested loop structure where rows grow in length.
// Space Complexity: O(1), constant space is used regardless of input size.

void Solution(int n){
    int x=0;

    for(int i=0;i<n;i++){
        if(i%2==0) x=1;
        for(int j=0;j<=i;j++){
            if(x>=2) x=0;
            cout<<x<<" ";
            x++;
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
