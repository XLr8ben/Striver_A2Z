#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

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
// **                **
// ***              ***
// ****            ****
// *****          *****
// ******        ******
// *******      *******
// ********    ********
// *********  *********
// ********************


// Approach

// The pattern consists of two mirrored halves forming an hourglass-like shape made of stars (*). The upper half starts with N stars on both sides and gradually reduces, while the lower half starts with 1 star on both sides and gradually increases. Spaces in between adjust accordingly to maintain symmetry.

// Upper Half:
// Initialize iniS = 0 (number of spaces between the two star blocks).
// For each row i from 0 to N-1:
// Print N - i stars.
// Print iniS spaces.
// Print N - i stars again.
// Increase iniS by 2.
// Lower Half:
// Initialize iniS = 2 * N - 2.
// For each row i from 1 to N:
// Print i stars.
// Print iniS spaces.
// Print i stars again.
// Decrease iniS by 2.


// Time Complexity: O(N2), For each of the N rows, we print up to 2N characters (stars and spaces).
// Space Complexity: O(1), No extra space is used apart from loop variables.

void Solution(int n){

    //first half
    for(int i=0;i<n;i++){

        for(int j=0;j<n-i;j++){
            cout<<"*";
        }

        for(int k=0;k<=2*i-1;k++){
            cout<<" ";
        }

        for(int l=0;l<n-i;l++){
            cout<<"*";
        }
        cout<<endl;
    }

    //second half
    for(int i=1;i<n;i++){

        for(int j=1;j<=i+1;j++){
            cout<<"*";
        }

        for(int k=2*n-i-2;k>i;k--){
            cout<<" ";
        }

        for(int l=1;l<=i+1;l++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Solution(20);

    return 0;
}
