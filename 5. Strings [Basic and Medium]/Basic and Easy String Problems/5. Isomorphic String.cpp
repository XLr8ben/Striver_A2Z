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
// Think of isomorphism as a consistent one-to-one mapping between characters of two strings.
// The goal is to ensure the pattern of appearances and repetitions is identical in both strings.
// Use two fixed-size arrays (size 256) to track the last-seen positions of characters from each string.
// While scanning both strings together, compare if the characters at the current position have been seen at the same relative positions before.
// If not, it indicates inconsistent mapping — one character maps to multiple others — return false.
// If consistent, update the last seen position of both characters to ensure future checks remain valid.
// This approach confirms isomorphic structure by comparing character occurrence patterns, not the characters themselves.

// Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.
// Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size

string Solution(string str1, string str2)
{
    
}

int main()
{
    string str1;
    cin>>str1;

    
    string str2;
    cin>>str2;



    cout << Solution(str1, str2) << endl;

    return 0;
}