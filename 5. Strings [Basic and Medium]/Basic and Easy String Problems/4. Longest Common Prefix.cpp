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
// The common prefix across all strings must exist between the smallest and largest string when sorted lexicographically.
// Sorting the array helps bring these boundary strings to the extremes.
// By comparing only the first and last strings, we can determine the full common prefix shared by the entire array.
// Character-wise comparison from the beginning allows us to identify where the prefix stops.
// The point at which the characters start differing marks the end of the shared prefix.
// The portion before this mismatch is the longest common prefix among all strings.

// Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.
// Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).

string Solution(vector<string> strs, int n)
{
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[n - 1];
    int minLength = min(first.size(), last.size());

    string ans = "";

    for (int i = 0; i < minLength; i++)
    {
        if (first[i] != last[i])
            break;

        ans += first[i];
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << Solution(input, n) << endl;

    return 0;
}