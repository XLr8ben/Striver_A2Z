#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// *
// **
// ***
// ****
// *****

// Approach
// Algorithm
// This is one of the simplest star patterns. We need to form a right-angled triangle where the number of stars in each row increases line by line. Row i contains exactly i + 1 stars.

// Run an outer loop from 0 to N-1 to handle rows.
// For each row i, run an inner loop from 0 to i.
// In the inner loop, print a star (*).
// After finishing the stars of one row, move to the next line using endl.

// Time Complexity: O(N2), Outer loop runs N times, and inner loop runs up to N stars cumulatively.
// Space Complexity: O(1), No extra space is used apart from loop counters.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
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
