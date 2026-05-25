#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// Approach
// Algorithm
// We need to print a square matrix of size (2 * n - 1) × (2 * n - 1). The outermost border should contain n, the next inner layer n-1, then n-2, and so on until the center which contains 1. This creates a concentric square pattern.

// We use two nested loops:
// Outer loop runs for rows (i from 0 to 2n-2).
// Inner loop runs for columns (j from 0 to 2n-2).
// For each cell (i, j), compute its distance from all four borders:
// top = i
// left = (2n - 2) - i
// bottom = j
// right = (2n - 2) - j
// Take the minimum of these four distances. This tells us how deep we are inside the square.
// Print n - minDistance at that position.

// Time Complexity: O((2N-1)²) ≈ O(N²), since we print every cell once.
// Space Complexity: O(1), only variables for indices are used.

void Solution(int n)
{

    for (int i = 0; i < 2 * n - 1; i++)
    {

        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = 2 * n - 2 - j;
            int bottom = 2 * n - 2 - i;

            int value = min(min(top, bottom), min(left, right));
            cout << (n - value);
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    Solution(n);

    return 0;
}
