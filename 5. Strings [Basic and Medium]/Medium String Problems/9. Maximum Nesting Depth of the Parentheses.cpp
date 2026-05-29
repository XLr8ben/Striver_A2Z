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
// We're interested in measuring how deeply nested the parentheses are at any point in the string.
// Each opening bracket indicates going deeper into a new level of nesting.
// Each closing bracket signals returning to the previous level of nesting.
// By tracking how deep we go at each step, we can monitor the peak nesting level.
// The deepest level we reach during this traversal is the answer.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as only constant extra space is used.

int Solution(string str){
    int cnt = 0, ans = 0;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(') cnt++;
        else if(str[i]==')') cnt--;
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    string str1;
    cin>>str1;

    cout << Solution(str1) << endl;

    return 0;
}