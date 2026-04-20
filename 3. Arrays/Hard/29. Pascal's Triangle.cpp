#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

// 1       1
// 2      1 1
// 3     1 2 1
// 4    1 3 3 1
// 5   1 4 6 4 1
// 6  1 5 10 10 5 1

//Ques 1) Given r & c, find the element at that place?
// r=5, c=3
//ans will be 6.

//brute force
// print whole traingle and then find element.

//better approach
// use factorial to find ans.

// TC: O(r)
// SC: O(1)

// long long fact(int n) {
//     long long res = 1;
//     for (int i = 1; i <= n; i++) res *= i;
//     return res;
// }

// long long getElement(int r, int c) {
//     return fact(r-1) / (fact(c-1) * fact(r-c));
// }

// int main() {
//     int r = 5, c = 3;
//     cout << getElement(r, c);
// }

//optimal 
// To find the element at the coordinates (R,C) where R is the row number and C is the Column number, we can simply simulate the generation of pascal's triangle for R rows.
// In Pascal’s Triangle, the element at row R and column C corresponds to the binomial coefficient (r-1)C(c-1). To calculate this binomial coefficient, we can simply apply the 
// formula of binomial coefficient i.e. (r-1)!/(c-1)!(r-c)!. Instead of computing full factorials (which can overflow and be slow), we can multiply and divide in a loop to compute the coefficient efficiently.

// TC: O(c)
// SC: O(1)

// int Solution(int n, int r){
//     long long ans = 1;

//     for(int i=0;i<r;i++){
//         ans *= (n-i);
//         ans /= (i+1);
//     }
//     return ans;
// }

// int main()
// {
//     int r;
//     cin>>r;

//     int c;
//     cin>>c;
    
//     cout<<Solution(r-1, c-1)<<endl;

//     return 0;
// }

//Ques 2) Print all elements of that row, r=6

//better aproach
//by finding factorial

// TC: O(r²)
// SC: O(1)

// long long fact(int n) {
//     long long res = 1;
//     for (int i = 1; i <= n; i++) res *= i;
//     return res;
// }

// void printRow(int r) {
//     for (int c = 1; c <= r; c++) {
//         cout << fact(r-1) / (fact(c-1) * fact(r-c)) << " ";
//     }
// }

// int main() {
//     printRow(6);
// }

//Ques 3) Print whole pascal`s traingle

//optmial
// TC: O(r)
// SC: O(1)

int Solution(int n){
    long long ans=1;
    cout<<ans<<" ";
    
    for(int i=1;i<n;i++){
        ans *= n-i;
        ans /= i;
        cout<<ans<<" ";
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
       Solution(i);
       cout<<endl;
    }


    return 0;
}
