#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;


int atMostKDistinct(string str, int k) {
    int left=0, res=0;

    unordered_map<char, int> freq;

    for(int right = 0; right<str.size(); right++){
        freq[str[right]]++;

        while(freq.size() > k){
            freq[str[left]]--;
            if(freq[str[left]] == 0) freq.erase(str[left]);
            left++;
        }
        res += right - left + 1;
    }
    return res;
}

int Solution(string str, int k) {
    return atMostKDistinct(str, k) - atMostKDistinct(str, k - 1);
}

int main()
{
    string str;
    cin>>str;

    int n;
    cin>>n;

    cout<<Solution(str, n)<<endl;

    return 0;
}
