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
// Understand that Roman numerals are generally written in descending order of value, and their values are added.
// However, when a smaller value appears before a larger one, it indicates subtraction instead of addition.
// To handle this, scan the string from left to right and compare each character with the one after it.
// If the current symbol is smaller than the next, treat it as a subtractive pair.
// Otherwise, treat the symbol as a standalone value and add it normally.
// The final character is always added since there's nothing after it to compare.

// Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
// Space Complexity: O(1), since we use a fixed-size map for Roman numerals.
 
int Solution(string str){
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int ans = 0;

    for(int i=0;i<str.length()-1;i++){
        if(roman[str[i]] < roman[str[i+1]])  ans -= roman[str[i]];
        else ans += roman[str[i]];
    }
    ans += roman[str.back()];

    return ans;

}

int main()
{
    string str1;
    cin>>str1;

    cout << Solution(str1) << endl;

    return 0;
}