#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

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



// Brute-Force Approach
// Algorithm
// To sort a given linked list, we can simply create an array of all the elements of the linked list. Now, we can sort this array using any sorting technique and reassign the values of the sorted array to our linked list. This modified linked list will have all the elements in sorted order.
// Create an empty array to store the node values. Iterate the linked list using a temporary pointer to the head and push the value of temporary node into the array.
// Sort the array containing node values in ascending order.
// Convert the sorted array back to a linked list reassigning the values from the sorted array and overwriting them sequentially according to their order in the array.

// Time Complexity: O(2*N + N*LogN), we traverse the linked list, store its elements in an array, sort it, and then copy the sorted values back into the original list.
// Space Complexity: O(N) , additional space required to store all the elements of linked list in an array.

// Node* sortLL(Node* head) {
//     vector<int> arr;

//     Node* temp = head;

//     while (temp != nullptr) {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(arr.begin(), arr.end());

//     temp = head;
//     for (int i = 0; i < arr.size(); i++) {
//         temp->data = arr[i];
//         temp = temp->next;
//     }

//     return head;
// }

// Optimal Approach
// Algorithm
// Instead of using an external array to store node values, we can try to implement similar sorting techniques for linked lists as well. In order to sort the linked list, we can try to implement a modified version of Merge Sort Algorithm. This algorithm would divide the linked list into halves recursively until single nodes remain. These sorted halves of the linked list are merged back together in a sorted order.
// If the linked list is empty or has only one node, it is already sorted, thus we can return the head directly.
// Use the slow and fast pointer technique to find the middle of the linked list, where slow moves one step and fast moves two steps at a time.
// Split the linked list into two halves at the midpoint by pointing middle to null, where the left half starts from the head and the right half starts from the node after the middle.
// Recursively apply merge sort on both halves of the linked list until each part is broken down into single nodes or empty lists.
// Merge the two sorted halves using a helper function that compares node values from both halves, attaches the smaller one to the result list, and continues until all nodes from both halves are merged.
// Return the head of the merged and fully sorted linked list, which will represent the final sorted list.

// Time Complexity: O(N*LogN), we recursively divide the linked list into two halves and then merge two sorted halves.
// Space Complexity: O(1) , constant additional space is required to sort the entire linked list.

Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node
    Node* dummyNode = new Node(-1);
    
    // Temp pointer to build merged list
    Node* temp = dummyNode;

    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr) {
        // Choose smaller node
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move temp pointer
        temp = temp->next;
    }

    // Attach remaining nodes
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    // Return head of merged list
    return dummyNode->next;
}

// Function to find middle of linked list
Node* findMiddle(Node* head) {
    // If list empty or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move fast twice as fast as slow
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Return middle node
    return slow;
}

// Function to perform merge sort
Node* sortLL(Node* head) {
    // Base case: empty or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find middle node
    Node* middle = findMiddle(head);

    // Split into two halves
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    // Recursively sort both halves
    left = sortLL(left);
    right = sortLL(right);

    // Merge sorted halves
    return mergeTwoSortedLinkedLists(left, right);
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

    head = sortLL(head);

    cout << "After Sorting: ";
    printll(head);
    cout << "null\n";

    return 0;
}