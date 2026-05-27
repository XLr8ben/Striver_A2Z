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
// Algorithm / Intuition
// Initialize an empty result string to store the processed output
// Initialize a counter (level) to track the depth of parentheses
// Traverse through the string character by character:
// If the current character is '(', increment the level counter. If the level is greater than 1 (indicating we're inside a valid primitive), add '(' to the result string
// If the current character is ')', decrement the level counter. If the level is greater than 0 (indicating we're still inside a valid primitive), add ')' to the result string
// After the entire string has been traversed, return the result string

// Time Complexity: O(n), since we are performing a single traversal of the string.
// Space Complexity: O(1), since we are using a few variables to track the current state.

string Solution(string str)
{
    string res = "";
    int cnt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            if (cnt > 0)
                res.push_back(str[i]);
            cnt++;
        }
        else if (str[i] == ')')
        {
            cnt--;
            if (cnt > 0)
                res.push_back(str[i]);
        }
    }
    return res;
}

int main()
{
    string str;
    cin >> str;

    cout << Solution(str) << endl;

    return 0;
}
