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
// ******
// *****
// ****
// ***
// **
// *

// Approach: 

// There are 4 general rules for solving a pattern-based question : 

// We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
// Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
// We print the ‘*’ inside the inner loop.
// Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns or not.
// In this problem, we have to print only the right half of the star diamond pattern as discussed in the previous article. So, as we can observe from the examples for N = 3 we have 5 rows, and for N = 6 we have 11 rows, 
// hence the outer loop will run for 2*N -1 times. For the inner loop where we print the stars if row no. is less than or equal to N, then we observe that the stars which are printed in each row are equal to the row index itself. 
// But, when i becomes more than N, then the no. of stars decreases by 1 with each increasing row. So, therefore the stars printed would be 2*N - i after i becomes greater than N.

// Time Complexity: O(N²), since nested loops print approximately N² characters overall.
// Space Complexity: O(1), as no extra data structures are required.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
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
