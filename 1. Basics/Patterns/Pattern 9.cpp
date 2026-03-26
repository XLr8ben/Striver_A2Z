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
// *********
//  *******
//   *****
//    ***
//     *

// Algorithm
// These patterns create symmetric pyramids of stars:

// Erect Pyramid: Starts with 1 star at the top, adding 2 stars per row, forming a pyramid pointing upwards.
// Inverted Pyramid: Starts with the maximum stars at the top, removing 2 stars per row, forming a pyramid pointing downwards.
// Spaces are used to center-align the stars for symmetry.
// Erect Pyramid:
// Loop through i = 0 to N-1 for rows.
// Print N-i-1 spaces before stars.
// Print 2*i + 1 stars.
// Print N-i-1 spaces after stars (optional for symmetry).
// Inverted Pyramid:
// Loop through i = 0 to N-1 for rows.
// Print i spaces before stars.
// Print 2*N - (2*i + 1) stars.
// Print i spaces after stars (optional for symmetry).

// Time Complexity: O(N²), since nested loops print approximately N² characters overall.
// Space Complexity: O(1), as no extra data structures are required.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }

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
