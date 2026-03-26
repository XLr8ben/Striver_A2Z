#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//     *
//    ***
//   *****
//  *******
// *********

// Algorithm
// In this pattern, we form a pyramid of stars. Each row contains:

// (N - i - 1) spaces on the left (to center align the stars),
// (2 * i + 1) stars in the middle,
// (N - i - 1) spaces on the right.
// This ensures symmetry and creates a proper pyramid shape.
// Run an outer loop (i) from 0 to N-1 for rows.
// Print N - i - 1 spaces before the stars.
// Print 2 * i + 1 stars.
// Print N - i - 1 spaces again (optional, only for symmetry in visualization).
// Move to the next line after each row.

// Time Complexity: O(N²), since nested loops print about N² characters overall.
// Space Complexity: O(1), as no extra data structures are required.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
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
