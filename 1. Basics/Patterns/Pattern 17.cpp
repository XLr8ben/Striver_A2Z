#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

//                          A
//                         ABA
//                        ABCBA
//                       ABCDCBA
//                      ABCDEDCBA
//                     ABCDEFEDCBA
//                    ABCDEFGFEDCBA
//                   ABCDEFGHGFEDCBA
//                  ABCDEFGHIHGFEDCBA
//                 ABCDEFGHIJIHGFEDCBA
//                ABCDEFGHIJKJIHGFEDCBA
//               ABCDEFGHIJKLKJIHGFEDCBA
//              ABCDEFGHIJKLMLKJIHGFEDCBA
//             ABCDEFGHIJKLMNMLKJIHGFEDCBA
//            ABCDEFGHIJKLMNONMLKJIHGFEDCBA
//           ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
//          ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
//         ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
//        ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
//       ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
//      ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
//     ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
//    ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
//   ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
//  ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
// ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA


// Algorithm
// Iterate from i = 0 to N - 1 to process each row.
// Print (N - i - 1) spaces to center-align the pyramid.
// Initialize a character variable ch = 'A'.
// Calculate the midpoint of the row as breakpoint = (2 * i + 1) / 2.
// Iterate from j = 1 to 2 * i + 1 to print the characters:
// If j ≤ breakpoint, print ch and increment it.
// Else, decrement ch and print it.
// Print (N - i - 1) spaces again (optional, as they don't affect output but maintain symmetry in code).
// Print a newline to move to the next row.

// Time Complexity: O(N²), because for each of the N rows, up to 2N characters (spaces and letters) may be printed, resulting in O(N²) total operations.
// Space Complexity: O(1), as only a constant amount of extra space is used for variables like ch and breakpoint.

void Solution(int n){
    for(int i=0;i<n;i++){
        char ch='A';

        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }

        for(int k=0;k<2*i+1;k++){
            cout<<ch;
            if(k>=i) {
                ch--;
            }else{
                ch++;
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    Solution(26);

    return 0;
}
