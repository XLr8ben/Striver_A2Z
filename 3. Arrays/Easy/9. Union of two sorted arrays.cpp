#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <unordered_map>

using namespace std;
//brute force approach
//time complexity: O((n+m)
//space complexity: O(n+m)
vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        mp[arr2[i]]++;
    }

    vector<int> temp;
    for(auto it: mp){
        temp.push_back(it.first);
    }

    return temp;
}

// Approach 2- Using Set
// Algorithm
// Using a set we can find the distinct elements because the set does not hold any duplicates. Hence we can find the union of arr1 and arr2.
// Initialize an empty set.
// Insert all elements from the first array into set.
// Insert all elements from the second array into set.
// Convert the set into a list/array to get the result.
// If required in sorted order, sort the list before returning.
// Return/print the union result.
// Why not unordered_set?
// In unordered_set the elements are stored in random order, while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.

// We can also use unordered_set, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.

// Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.
// Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
// Space Complexity : O(m+n) {If Space of Union ArrayList is considered} ,O(1) {If Space of union ArrayList is not considered}

// vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     set<int> s;

//     for(int i=0; i<n; i++){
//         s.insert(arr1[i]);
//     }

//     for(int i=0; i<m; i++){
//         s.insert(arr2[i]);
//     }

//     vector<int> temp(s.begin(), s.end());

//     return temp;
// }


//optimal approach
//time complexity: O(n+m)
//space complexity: O(n+m)
// vector<int> Solution(vector<int>& arr1, int n, vector<int>& arr2, int m){
//     int i=0,j=0;

//     vector<int> temp;

//     while(i<n && j<m){
//         if(arr1[i]<=arr2[j]){
//             temp.push_back(arr1[i]);
//             i++;
//         }
//         else if(arr1[i]>arr2[j]){
//             temp.push_back(arr2[j]);
//             j++;
//         }
//         else{
//             temp.push_back(arr1[i]);
//             i++;
//             j++;
//         }
//     }

//     while(i<n){
//         temp.push_back(arr1[i]);
//         i++;
//     }

//     while(j<m){
//         temp.push_back(arr2[j]);
//         j++;
//     }

//     return temp;
// }

int main()
{
    int n1;
    cin>>n1;
    vector<int> arr1(n1);

    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }

    int n2;
    cin>>n2;
    vector<int> arr2(n2);

    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }

    vector<int> result = Solution(arr1, n1, arr2, n2);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}
