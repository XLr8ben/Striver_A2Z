#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Approach
// Algorithm
// Focus on finding the longest valid odd number starting from the original string.
// An odd number must end with an odd digit, so we look for the last odd digit when scanning from the end.
// Leading zeroes don’t add value to the number, so we aim to remove them for a cleaner representation.
// Once the endpoint (last odd digit) is determined, we identify the starting point by skipping any leading zeroes before it.
// Extract the portion between these two positions, this gives the largest possible odd integer from the string.

// Time Complexity: O(N), since the loop runs once through the string of length N.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

string Solution(string str){
    int n = str.length();
    int idx = -1;

    for(int i = n - 1; i >= 0; i--){
        if((str[i] - '0') % 2 == 1){
            idx = i;
            break;
        }
    }

    if(idx == -1) return "";
    return str.substr(0, idx+1);
}

int main()
{
    string str;
    cin>>str;

    cout<<Solution(str)<<endl;

    return 0;
}
