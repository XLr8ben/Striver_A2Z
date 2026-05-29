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
// The goal is to rank characters based on how frequently they appear in the string.
// We need a structure that can track both the character and how often it occurs.
// Sorting the characters by frequency helps surface the most significant ones first.
// To maintain consistency when frequencies match, tie-breaking is done alphabetically.
// Once sorted, the characters with non-zero occurrences form the final ranked result.

// Time Complexity: O(n + k log k), where n is the length of the string and k is the constant 26 for the alphabet.
// Space Complexity: O(k) , where k is the constant 26 for the frequency array.


vector<char> Solution(string str){

}

int main()
{
    string str;
    cin >> str;

    vector<char> ans = Solution(str);

    for(char ch: ans){
        cout<<ch;
    }

    return 0;
}