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
// First, skip all leading whitespaces.
// Check if the number is negative or positive using the sign character.
// Start processing digits one by one and build the number.
// Stop when a non-digit character is encountered.
// While forming the number, check for overflow and underflow.
// If the value exceeds INT_MAX, return INT_MAX.
// If the value goes below INT_MIN, return INT_MIN.

// Algorithm
// 1. Remove leading spaces by moving the index forward.
// 2. Determine the sign ('+' or '-').
// 3. Traverse the string while characters are digits.
// 4. Convert each digit and append it to the current number.
// 5. Check overflow/underflow before returning.
// 6. Return the final signed integer.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since only a few variables are used.

int Solution(string str){
    int i=0;

    while(i<str.length() && str[i]==' '){
        i++;
    }

    str = str.substr(i);

    int sign = +1;
    long ans = 0;

    if(str[0]=='-') sign = -1;

    i = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    int mini = INT_MIN, maxi = INT_MAX;

    while(i<str.length()){
        if(str[i]==' ' || !isdigit(str[i])) break;
        ans = ans*10 + str[i] - '0';
        if(sign == -1 && ans*sign < mini) return mini;
        if(sign == +1 && ans*sign > maxi) return maxi;
        i++;
    }
    return sign * ans;
}

int main()
{
    string str;
    getline(cin, str);

    cout<<Solution(str)<<endl;

    return 0;
}
