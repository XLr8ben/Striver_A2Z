#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// *****
// *****
// *****
// *****
// *****

// Intuition: The task is to print a square pattern of stars. Since the number of rows and columns are equal, we can use two nested loops: the outer one for rows and the inner one for printing N stars per row.

// Take an integer N as input to define the size of the square.
// Use a loop from 0 to N-1 to represent each row.
// Inside that loop, use another loop from 0 to N-1 to print stars in the current row.
// Print "* " during each inner loop iteration to form the row.
// After each inner loop completes, move to the next line.

// Time Complexity: O(N²), since we print N stars for each of the N rows.
// Space Complexity: O(1), no additional space is used apart from loop variables.

void Solution(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
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
