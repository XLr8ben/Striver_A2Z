#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// 1 
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

// Algorithm
// In this pattern, instead of printing increasing numbers from 1 to i in each row, we print the row number itself repeatedly. For example, the first row prints 1, the second row prints 2 2, the third row prints 3 3 3, and so on until N.

// Use an outer loop (i) from 1 to N for rows.
// For each row, use an inner loop (j) from 1 to i.
// Instead of printing j, print i (the current row number).
// After completing one row, move to the next line.

// Time Complexity: O(N²), because there are two nested loops: the outer loop for rows and the inner loop for printing numbers.
// Space Complexity: O(1), as only loop variables are used.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
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
