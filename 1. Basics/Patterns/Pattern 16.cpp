#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// A 
// B B 
// C C C 

// Algorithm
// Intuition: This pattern prints a right-angled triangle of alphabets where each row contains the same character repeatedly. The character printed in row i is 'A' + i.

// The outer loop runs from i = 0 to i = N - 1, for each row.
// In each row, the character to print is determined by ch = 'A' + i.
// The inner loop runs from j = 0 to j = i, printing the character ch exactly i+1 times.
// A newline is printed at the end of each row to move to the next line.

// Time Complexity: O(N²), because the total number of characters printed is the sum of the first N natural numbers.
// Space Complexity: O(1), only loop variables and a character variable are used.

void Solution(int n){
    char ch='A';
    for(int i=0;i<n;i++){

        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
        }
        ch++;
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
