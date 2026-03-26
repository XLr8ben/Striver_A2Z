#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


//brute force approach
// Since we need to store only unique elements, we can use the set data structure. We can insert all the elements of the array in the set irrespective of their frequency as set only allows one occurence of each element.
// Declare a set and insert all the elements of the array into the set.
// The number of unique elements in array is equal to size of the set.
// Traverse the set and fill the first k indices with elements in set.

// Time Complexity: O(N), We traverse the entire array and insert elements into set.
// Space Complexity: O(N), additional space used to store elements in set.

    // int removeDuplicates(vector<int>& nums) {
    //     unordered_set<int> st;

    //     for(auto it: nums){
    //         st.insert(it);
    //     }

    //     vector<int> temp(st.begin(), st.end());
    //     sort(temp.begin(), temp.end());
        
    //     int i=0;
    //     for(auto ot: temp){
    //         nums[i] = ot;
    //         i++;
    //     }

    //     return temp.size();
    // }

//optmized 
// Instead of using a set to store the unique elements, we can implement a two pointer strategy to optimize the space. Since the array is sorted, we know that all the duplicate values will be adjacent to each other.
// Begin at the first position, which will always be part of the final unique list.
// Move through the list one item at a time, comparing the current item with the most recently kept unique item.
// If the current item is the same as the last kept one, skip it because it’s a duplicate.
// If it’s different, place it right after the last kept unique item to keep all unique values grouped at the front.
// Continue until every element in the list has been checked. The first part of the list now contains all the unique values in their original order, and the rest can be ignored.

// Time Complexity: O(N), We traverse the entire original array only once.
// Space Complexity: O(1), constant additional space is used to check unique elements.

int removeDuplicates(vector<int>& nums){
        int i=0;

        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    } 

int main() {
    
    int sz;
    cin>>sz;

    vector<int> arr(sz);

    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }

    int k = removeDuplicates(arr);

    cout<<k<<endl;

    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
