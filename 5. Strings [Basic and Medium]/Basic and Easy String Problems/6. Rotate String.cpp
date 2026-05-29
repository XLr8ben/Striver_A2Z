#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute Force
// Algorithm
// Start by generating all possible left rotations of the original string using substring slicing and concatenation.
// For each rotated version of the string, compare it with the target (goal) string.
// If a match is found at any point, return true immediately as the goal can be achieved.
// If none of the rotations match the goal string after checking all possibilities, return false.

// Time Complexity: O(N^2) since generating N rotations and each comparison takes O(N) time.
// Space Complexity: O(N) for the space needed to store each rotated string.

// string Solution(string str, string goal){
//     if (str.length() != goal.length()) return "false";

//     for(int i=0;i<str.length();i++){
//         string rotated = str.substr(i) + str.substr(0, i);
//         if(rotated == goal) return "true";
//     }
//     return "false";
// }

//another approach
bool rotateString(string s, string goal) {
    if(s.length() != goal.length()) return false;

    string str = s+s;
    int n = str.size(), m = goal.size();
    

    for(int i=0;i<n-m;i++){
        int first =i,sec=0;
        while(sec<m){
            if(str[first] != goal[sec]) break;
            else{
                first++;
                sec++;
            }
        }
        if(sec==m) return true;
    }
    return false;
}

// Optimal Approach
// Algorithm
// Double the original string by joining it with itself, creating a new string like s + s.
// Look for the target string goalinside this new doubled string.
// If goal exists within the doubled string, then it's a valid rotation, return true.
// If it's not found, that means the original string cannot be rotated to match goal, return false

// Time Complexity: O(N), because checking for a substring in s + s is linear in time.
// Space Complexity: O(N) for the space needed to store the concatenated string s + s.

bool Solution(string str, string goal){
    if (str.length() != goal.length()) return false;
        
    string doubledS = str + str;
    return doubledS.find(goal) != string::npos;
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