#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Algorithm
// To print your name N times using recursion, the approach involves defining a recursive function that takes the current count as a parameter. The function checks if the count has reached N, if it has, the recursion terminates.
// Otherwise, it prints the name once and recursively calls itself, incrementing the count by one. This way, the name gets printed exactly N times as the recursion progresses. The key is to use the count to keep track of how many times the name has been printed so far and stop once it reaches N.

// Time Complexity: O(N), we print our name exactly N times.
// Space Complexity: O(N), stack space used for recursive calls.

void Solution(string str, int start,int n){
    if(start==n) return;

    cout<<str<<endl;
    Solution(str, ++start, n);
}

int main()
{
    int n;
    cin>>n;

    string str;
    cin>>str;

    Solution(str, 0, n);

    return 0;
}
