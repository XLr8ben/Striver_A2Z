#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

    Node(int val, Node* next1){
        data = val;
        next = next1;
    }
};

void printll(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

Node* convettoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


// Brute Force Approach
// Algorithm
// Traverse the linked list from start to end, and push each node's value into a stack.
// Once done, start again from the head of the linked list.
// For each node, pop an element from the stack and compare it with the current node’s value.
// If any value doesn’t match, return false — it’s not a palindrome.
// If all values match till the end, return true — the list is a palindrome.

// Time Complexity: O(N), we traverse the entire linked list twice, once to push all elements into the stack, and once to compare them with the original list.
// Space Complexity: O(N), we use a stack that stores all the elements of the linked list, which takes linear space in the worst case.

// bool isPalindrome(Node* head) {
//     // Create an empty stack to store values
//     stack<int> st;

//     // Initialize a temporary pointer to the head of the linked list
//     Node* temp = head;

//     // Traverse the linked list and push values onto the stack
//     while (temp != NULL) {
//         st.push(temp->data); // Push the data from the current node onto the stack
//         temp = temp->next;   // Move to the next node
//     }

//     // Reset the temporary pointer back to the head of the linked list
//     temp = head;

//     // Compare values by popping from the stack and checking against linked list nodes
//     while (temp != NULL) {
//         if (temp->data != st.top()) {
//             // If values don't match, it's not a palindrome
//             return false;
//         }
//         st.pop();           // Pop the value from the stack
//         temp = temp->next;  // Move to the next node in the linked list
//     }

//     // If all values match, it's a palindrome
//     return true;
// }

// Optimal Approach
// Algorithm
// Return true if the list is empty or has only one node, since such lists are palindromes by default.
// Use two pointers ‘slow’ and ‘fast’ to find the middle node, where slow moves one step and fast moves two steps at a time.
// Reverse the second half of the linked list starting from the node after the middle (slow->next), preparing it for comparison.
// Set two pointers: one at the head of the list and the other at the head of the reversed second half, to compare both halves.
// Compare both halves node by node; if any mismatch occurs, return false, otherwise continue till the end of either list.
// Reverse the second half again to restore the original list structure, and return true if all nodes matched successfully.

// Time Complexity: O(N), we traverse the list twice, once to reverse half of it and once to compare, each taking O(N/2), which simplifies to O(N).
// Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.

Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;  // No change is needed; return the current head
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}

bool isPalindrome(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer one step at a time
        fast = fast->next->next; // Move fast pointer two steps at a time
    }

    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node* first = head;

    // Pointer to the reversed second half
    Node* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}


int main() {

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Node* head = convettoLL(arr);
    printll(head);
    cout<<"null"<<endl;
    
    bool pal = isPalindrome(head);
    cout<<"isPakindrome "<<pal<<endl;
    cout<<"null"<<endl;


    return 0;
}