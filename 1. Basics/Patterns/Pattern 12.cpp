#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// 1          1
// 12        21
// 123      321
// 1234    4321
// 12345  54321
// 123456654321

// Algorithm
// Intuition: This pattern prints a mirrored sequence of numbers on both sides with spaces in the center. The outer digits increase and decrease symmetrically, while the center gap shrinks with each row, forming a diamond-like structure across rows.

// Initialize the number of spaces between the two number sequences as 2 × (N - 1).
// Loop from 1 to N to handle each row.
// Print increasing numbers from 1 to i on the left side of the row.
// Print the current number of spaces in the middle.
// Print decreasing numbers from i to 1 on the right side of the row.
// Move to the next line after completing the row.
// Reduce the number of middle spaces by 2 after each row.


// Time Complexity: O(N²), due to the nested loop structure where rows grow in length.
// Space Complexity: O(1), constant space is used regardless of input size.

void Solution(int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        for(int k=0;k<2*n-(2*i+1)-1;k++){
            cout<<" ";
        }
        for(int l=i+1;l>0;l--){
            cout<<l;
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
