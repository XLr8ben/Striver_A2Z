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
// First, check if the lengths of both strings are equal. If not, they can't be anagrams and return false immediately.
// If the lengths match, sort both strings using a built-in sorting algorithm.
// Once sorted, iterate through each character of both strings and compare them one by one.
// If any character mismatch is found, return false.
// If all characters match, return true, confirming that the strings are anagrams.

// Time Complexity: O(N log N), where N is the length of the strings. This is due to the sorting step performed on both strings.
// Space Complexity: O(1), as the sorting is done in-place and no extra space proportional to input size is used (excluding the input strings themselves).

// string Solution(string str1, string str2){
//     if (str1.length() != str2.length()) {
//         return "false";
//     }

//     sort(str1.begin(), str1.end());
//     sort(str2.begin(), str2.end());

//     for (int i = 0; i < str1.length(); i++) {
//         if (str1[i] != str2[i]) {
//             return "false";
//         }
//     }

//     return "true";
// }

// Optimal Approach
// Algorithm
// First, check if the lengths of both strings are equal. If not, return false immediately as they cannot be anagrams.
// Initialize a frequency array of size 26 (for all uppercase English letters) and set all elements to 0.
// Traverse the first string and increment the frequency of each character.
// Traverse the second string and decrement the frequency of each character.
// Finally, check if all elements in the frequency array are zero. If any element is not zero, return false as the characters do not match in frequency.
// If all frequencies are zero, the strings are anagrams and the function returns true.

// Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).
// Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size.

string Solution(string str1, string str2){

    if (str1.length() != str2.length()) return "false";

    int freq[26] = {0};

    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'A']++;
    }  
    for (int i = 0; i < str2.length(); i++) {
        freq[str2[i] - 'A']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return "false";
    }

    return "true";
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