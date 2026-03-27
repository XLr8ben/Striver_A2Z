#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// *                  *
// **                **
// ***              ***
// ****            ****
// *****          *****
// ******        ******
// *******      *******
// ********    ********
// *********  *********
// ********************
// *********  *********
// ********    ********
// *******      *******
// ******        ******
// *****          *****
// ****            ****
// ***              ***
// **                **
// *                  *


// Approach
// Algorithm
// This pattern prints two symmetrical right-angled triangles facing each other with spaces in between. - In the first half, stars increase while spaces decrease. - In the second half, stars decrease while spaces increase. The symmetry is maintained across the middle row.

// Initialize spaces = 2 * n - 2.
// Run an outer loop from 1 to 2*n - 1 (total rows).
// For each row:
// Determine number of stars:
// If i <= n, stars = i.
// If i > n, stars = 2*n - i.
// Print stars stars.
// Print spaces spaces.
// Print stars stars again.
// Update spaces:
// If i < n, decrease spaces by 2.
// Else, increase spaces by 2.

// Time Complexity: O(N2), Two nested loops: outer loop runs 2n-1 times, inner loops cumulatively print O(N) characters per row.
// Space Complexity: O(1), No extra space used apart from loop counters.

void Solution(int n){
    //first half
    for(int i=0;i<n;i++){

        for(int j=0;j<=i;j++){
            cout<<"*";
        }

        for(int k=2*n-i-2;k>i;k--){
            cout<<" ";
        }

        for(int l=0;l<=i;l++){
            cout<<"*";
        }
        cout<<endl;
    }

    //second half
    for(int i=1;i<n;i++){

        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }

        for(int k=0;k<2*i;k++){
            cout<<" ";
        }

        for(int l=1;l<=n-i;l++){
            cout<<"*";
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
