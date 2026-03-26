#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// *********
//  *******
//   *****
//    ***
//     *

// Algorithm
// This pattern is the inverted version of a star pyramid. Each row contains:

// i spaces on the left (to center align the stars),
// 2 * N - (2 * i + 1) stars in the middle,
// i spaces on the right (optional for symmetry).
// As we move down the rows, the number of stars decreases and spaces increase, forming an inverted pyramid.
// Run an outer loop (i) from 0 to N-1 for rows.
// Print i spaces before the stars.
// Print 2 * N - (2 * i + 1) stars.
// Print i spaces after the stars (optional for symmetry in visualization).
// Move to the next line after each row.

// Time Complexity: O(N²), since nested loops print approximately N² characters overall.
// Space Complexity: O(1), as no extra data structures are required.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int k=0;k<2*n-(2*i+1);k++){
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
