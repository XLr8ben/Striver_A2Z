#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// Brute Force
// Algorithm
// Approach
// First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations.
// Next, using a loop we will pick k gas stations one at a time.
// Then, using another loop, we will find the index 'i' where the distance (arr[i+1] - arr[i]) is the maximum and insert the current gas station between arr[i] and arr[i+1] (i.e. howMany[i]++).
// Finally, after placing all the new stations, we will find the distance between two consecutive gas stations. For a particular section, distance = section_length / (number_of_stations_ inserted+1) = (arr[i+1]-arr[i]) / (howMany[i]+1)
// Among all the distances, the maximum one will be the answer.

// Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
// Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations.

// long double Solution(vector<int>& arr, int n, int k){
//     vector<int> howMany(n-1, 0);

//     for(int gasStations=1;gasStations<=k;gasStations++){
//         long double maxSection = -1;
//         int maxIdx = -1;

//         for(int i=0;i<n-1;i++){
//             long double diff = arr[i+1] - arr[i];
//             long double sectionLength = diff / (howMany[i] + 1.0);

//             if(sectionLength > maxSection){
//                 maxSection = sectionLength;
//                 maxIdx = i;
//             }
//         }
//         howMany[maxIdx]++;
//     }

//     long double maxAns = -1;
//     for(int i=0;i<n-1;i++){
//         long double diff = arr[i+1] - arr[i];
//         long double sectionLength = diff / (howMany[i] + 1.0);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }

// Better Approach
// Algorithm
// Intuition
// In the previous approach, for every gas station, we were finding the index i for which the distance between arr[i+1] and arr[i] is maximum. After that, our job was to place the gas station. Instead of using a loop to find the maximum distance, we can simply use the heap data structure i.e. the priority queue.

// Approach
// First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations and a priority queue that uses max heap.
// We will insert the first n-1 indices with the respective distance value, arrr[i+1]-arr[i] for every index.
// Next, using a loop we will pick k gas stations one at a time.
// Then we will pick the first element of the priority queue as this is the element with the maximum distance. Let’s call the index ‘secInd’.
// Now we will place the current gas station at ‘secInd’(howMany[secInd]++) and calculate the new section length, new_section_length = initial_section_length / (number_of_stations_ inserted+1) = (arr[secInd+1] - arr[secInd]) / (howMany[i] + 1)
// After that, we will again insert the pair into the priority queue for further consideration.
// After performing all the steps for k gas stations, the distance at the top of the priority queue will be the answer as we want the maximum distance.

// Time Complexity: O(nlogn + klogn), n = size of the given array, k = no. of gas stations to be placed.
// Space Complexity: O(n-1)+O(n-1). The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue..

long double Solution(vector<int> &arr, int n, int k)
{
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        long double length = arr[i + 1] - arr[i];
        pq.push({length, i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto top = pq.top();
        pq.pop();
        int i = top.second;

        howMany[i]++;
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (howMany[i] + 1.0);
        pq.push({sectionLength, i});
    }

    return pq.top().first;
}

// Optimal Approach
// Algorithm
// First, we will find the maximum distance between two consecutive gas stations i.e. max(dist).
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 0 and the high will point to max(dist).
// Now, we will use the ‘while’ loop like this: while(high - low > 10^(-6)).
// Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) / 2.0
// Eliminate the halves based on the number of stations returned by numberOfGasStationsRequired(): We will pass the potential value of ‘dist’, represented by the variable 'mid', to the ‘numberOfGasStationsRequired()' function. This function will return the number of gas stations we can place.
// If result > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid).
// Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid).
// Finally, outside the loop, we can return either low or high as their difference is beyond 10^(-6). They both can be the possible answer. Here, we have returned the ‘high’.

// Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
// Space Complexity: O(1), as we are using no extra space to solve this problem.

// int numberOfGasStationsRequired(vector<int> &arr, int n, long double dist)
// {
//     int cnt = 0;

//         for (int i = 1; i < n; i++) {
//             int diff = arr[i] - arr[i-1];
//             int numberInBetween = diff / dist;

//             if (diff == (dist * numberInBetween)) numberInBetween--;
            
//             cnt += numberInBetween;
//         }
//         return cnt;
// }

// long double Solution(vector<int> &arr, int n, int k)
// {
//     long double low = 0, high = 0;

//     for (int i = 0; i < n - 1; i++){
//         high = max(high, (long double)(arr[i + 1] - arr[i]));
//     }

//     long double diff = 1e-6;

//     while (high - low > diff)
//     {
//         long double mid = (low + high) / 2.0;
//         int cnt = numberOfGasStationsRequired(arr, n, mid);
//         if (cnt > k)
//             low = mid;
//         else
//             high = mid;
//     }

//     return high;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Solution(arr, n, k) << endl;

    return 0;
}
