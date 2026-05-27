#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force Approach
// Algorithm
// In the brute force method, we manually parse the string to extract words without directly using high-level split functions. The idea is to read through the string character by character, identify sequences of non-space characters as words, store them in a list, and then reverse the list to achieve the desired order. We also need to handle multiple spaces, leading spaces, and trailing spaces, which means ignoring extra spaces while collecting words. Once reversed, we join the words using a single space. This way, the output string has exactly one space between each word and no leading or trailing spaces.
// Initialize an empty list to store words.
// Traverse the string character by character.
// Identify consecutive non-space characters as a word.
// Ignore extra spaces and leading/trailing spaces while collecting words.
// Append each identified word to the list.
// Reverse the list of words.
// Join the reversed list into a single string using a single space.
// Return the resulting string.

// Time Complexity: O(N),We traverse the string once to collect words (O(N)) and once more to reverse and join them (O(N)). Hence total time is O(N).
// Space Complexity: O(N),We store all words in a separate list/array, requiring extra space proportional to the number of characters.

void reversestr(string &str, int s, int e){
    while(s<=e){
        swap(str[s++], str[e--]);
    }
}

string Solution(string str){
    reversestr(str, 0, str.length()-1);
    
    int lastpos=0;
    string ans="";
    
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            reversestr(str, lastpos, i-1);
            lastpos = i+1;
        }
    }
    reversestr(str, lastpos, str.length()-1);

    for(int i=0;i<str.length();i++){
        if(str[i] != ' ') ans += str[i];
        else if(!ans.empty() && ans.back() != ' ') ans += ' ';
    }

    if(!ans.empty() && ans.back() == ' ') ans.pop_back();

    return ans;
}

int main()
{
    string str;
    getline(cin, str);

    cout<<Solution(str)<<endl;

    return 0;
}
