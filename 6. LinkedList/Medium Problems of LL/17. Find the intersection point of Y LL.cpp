#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *next1)
    {
        data = val;
        next = next1;
    }
};

void printll(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

Node *convettoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Brute Force Approach
// Algorithm
// In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-
// Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
// Iterate through list 2 and search the hashed value in the hash table. If found, return node.

// Time Complexity: O(n + m), Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m).
// Space Complexity: O(n), Storing list 1 node addresses in an unordered_set.

// Node* intersectionPresent(Node* head1, Node* head2) {
    
//     unordered_map<Node*, int> mpp;

//     Node* temp = head1;
    
//     while (temp != NULL) {
//         mpp[temp] = 1;
//         temp = temp->next;
//     }

    
//     Node* temp = head2;

//     while (temp != NULL) {
//         if (mpp.find(temp) != mpp.end()) return temp;
//         temp = temp->next;
//     }

//     return NULL;
// }

// Optimal Approach 1
// Algorithm
// We will reduce the search length. This can be done by searching the length of the shorter linked list. How? Let’s see the process.

// Find the length of both lists.
// Find the positive difference between these lengths.
// Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
// Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.

// Time Complexity: O(2 × max(length of list1, length of list2)) + O(abs(length of list1 − length of list2)) + O(min(length of list1, length of list2)), Finding the length of both lists takes O(max) time since it's done simultaneously, then moving one pointer by the difference in lengths, and finally searching for the intersection.
// Space Complexity: O(1), No extra space is used.

// Node* collisionPoint(Node* t1, Node* t2, int diff) {
//     while(diff){
//         diff--;
//         t2 = t2->next;
//     }

//     while(t1 != t2){
//         t1 = t1->next;
//         t2 = t2->next;
//     }

//     return t1;
// }


// Node* intersectionPresent(Node* head1, Node* head2) {
//     Node * temp = head1;
//     int n1=0;

//     while(temp != nullptr){
//         n1++;
//         temp = temp->next;
//     }

//     temp = head2;
//     int n2=0;

//     while(temp != nullptr){
//         n2++;
//         temp = temp->next;
//     }

//     if(n1 < n2) return collisionPoint(head1, head2, n2-n1);
//     else return collisionPoint(head2, head1, n1-n2);

// }

// Optimal Approach 2
// Algorithm
// The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

// Time Complexity: O(2 × max(length of list1, length of list2)), Uses the same concept of difference of lengths of two lists.
// Space Complexity: O(1), No extra data structure is used.

// Utility function to check presence of intersection
Node* intersectionPresent(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    
    while (t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if(t1==nullptr) t1 = head2;
        if(t2==nullptr) t2 = head1;

    }
    return t1;
}


int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convettoLL(arr);

    cout << "Original List: ";
    printll(head);
    cout << "null\n";

    int n2;
    cin >> n2;

    vector<int> arr2(n2);

    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    Node* head2 = convettoLL(arr2);

    cout << "Original List: ";
    printll(head2);
    cout << "null\n";
    
    Node* newHead = intersectionPresent(head, head2);

    cout << "Intersection Point: ";
    printll(newHead);
    cout << "null\n";

    return 0;
}