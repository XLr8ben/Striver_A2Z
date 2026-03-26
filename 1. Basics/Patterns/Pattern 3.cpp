#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;
 
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

// Algorithm
// We need to print a right-angled triangle where each row contains numbers starting from 1 up to the row number. So, the first row has 1, the second row has 1 2, the third row has 1 2 3, and so on until N.

// Use an outer loop (i) from 1 to N for rows.
// For each row, use an inner loop (j) from 1 to i to print numbers.
// Each row prints numbers starting from 1 up to the current row index.
// After printing each row, move to the next line.

// Time Complexity: O(N²), because the outer loop runs N times and the inner loop runs up to i times for each row.
// Space Complexity: O(1), since only loop variables are used.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
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
