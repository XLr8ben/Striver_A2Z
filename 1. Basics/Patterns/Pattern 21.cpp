#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// **********
// *        *
// *        *
// *        *
// *        *
// *        *
// *        *
// *        *
// *        *
// **********


// Approach
// Algorithm
// We need to print a square of size n × n but only with stars on the border, leaving the inner cells as spaces. This creates a "hollow square" effect.

// Run an outer loop i from 0 to n-1 (rows).
// Inside, run an inner loop j from 0 to n-1 (columns).
// For each position (i, j):
// If it lies on the border (i == 0, j == 0, i == n-1, j == n-1), print *.
// Else, print a space.
// After printing one row, move to the next line.

// Time Complexity: O(N2), For each of the n rows, we print n characters.
// Space Complexity: O(1), Only loop counters are used.

void Solution(int n){

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1) cout<<"*";
            else cout<<" ";
        }

        cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;

    Solution(10);

    return 0;
}
