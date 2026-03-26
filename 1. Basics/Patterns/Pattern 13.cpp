#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

// Algorithm
// Intuition: This pattern prints a continuous sequence of increasing numbers, arranged row by row in a triangular structure. Each row has one more number than the previous, and the values increment consecutively throughout the triangle.

// Initialize a variable to store the current number, starting from 1.
// Loop from 1 to N to handle each row.
// For each row, print i numbers starting from the current value of the number variable.
// Increment the number after each print to maintain the continuous sequence.
// After printing all numbers in a row, move to the next line.


// Time Complexity: O(N²), due to the nested loop structure where rows grow in length.
// Space Complexity: O(1), constant space is used regardless of input size.

void Solution(int n){
    int cnt=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<cnt<<" ";
            cnt++;
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
