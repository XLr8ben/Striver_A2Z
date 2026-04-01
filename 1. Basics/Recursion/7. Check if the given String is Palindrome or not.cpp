#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Brute Force Approach
// Algorithm
// To check whether a string is a palindrome, we only need to compare characters from the start and end, moving towards the center.
// Run a for loop from i = 0 to i < str.length() / 2. This ensures that each character is compared with its corresponding character from the end.
// In each iteration, compare the character at the front str[i] with the character at the back str[str.length() - i - 1].
// If at any point these characters do not match, return false as the string is not a palindrome.
// If the loop completes without returning false, then the string is a palindrome, and we return true.

// Time Complexity: O(N), where N is the length of the string. Each character is compared at most once till the middle of the string.
// Space Complexity: O(1), since no extra space is used apart from a few variables for iteration.

// bool Solution(string str)
// {
//     int left = 0, right = str.length() - 1;

//     while (left <= right)
//     {
//         if (!isalnum(str[left]))
//             left++;
//         else if (!isalnum(str[right]))
//             right--;
//         else if (tolower(str[left]) != tolower(str[right]))
//             return false;
//         else
//         {
//             left++;
//             right--;
//         }
//     }
//     return true;
// }

// Optimal Approach
// Algorithm
// Use recursion to compare characters at the start and end of the string.
// If the characters are not equal, return false indicating the string is not a palindrome.
// If they are equal, recursively call the function with the next set of indices: start + 1 and end - 1.
// Base Case: If the start index becomes greater than or equal to the end index, return true as it means the entire string has been checked and is a palindrome.

// Time Complexity: O(N), where N is the length of the string. Each character is checked once.
// Space Complexity: O(N), due to the recursion stack in the worst case (no early termination).

bool Solution(int left, int right, string &str) {
    if (left >= right) return true;

    if (!isalnum(str[left]))
        return Solution(left + 1, right, str);

    if (!isalnum(str[right]))
        return Solution(left, right - 1, str);

    if (tolower(str[left]) != tolower(str[right]))
        return false;

    return Solution(left + 1, right - 1, str);
}

int main()
{
    string str;
    cin >> str;

    cout << Solution(0, str.length()-1, str) << endl;

    return 0;
}
