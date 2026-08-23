#include <iostream>
#include <vector>
#include <stack>

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
// When asked to rotate a linked list to the right k times, we are essentially moving the last node to the front of the list, k times. Each rotation means: take the last node, disconnect it from the list, insert it at the front (head) of the list. We repeat this process k times. This approach is straightforward but not efficient because each rotation requires a traversal to the second-last node, which takes linear time. So in total, if we rotate k times and for each rotation we traverse the list (of n nodes), hence this approach is inefficient for large inputs.
// If the linked list is empty or has only one node, or k is 0, return the head as-is.
// Repeat the following steps k times:
// Initialize a pointer to traverse the list from head.
// Traverse to the second-last node of the list.
// Store the last node separately.
// Make the second-last node point to null (removing the last node).
// Insert the stored last node at the beginning by:
// Pointing its next to the current head.
// Updating the head to this node.
// Return the new head of the list.

// Time Complexity: O(k * n),We are performing `k` rotations. In each rotation. We traverse the list to reach the second-last node (this takes O(n) time), then we adjust a few pointers (which is O(1)). So the overall time complexity is O(k * n). This approach becomes inefficient if k is large, especially with long lists, because each rotation traverses the full list.
// Space Complexity: O(1), We do not use any additional data structures.

Node* rotateRight(Node* head, int k) {
    // If list is empty or has only one node or no rotation needed
    if (!head || !head->next || k == 0) return head;

    // Repeat the rotation process k times
    for (int i = 0; i < k; i++) {
        // Initialize two pointers to traverse the list
        Node* curr = head;
        Node* prev = NULL;

        // Traverse to the last node
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }

        // Detach the last node and place it at the beginning
        prev->next = NULL;
        curr->next = head;
        head = curr;
    }

    // Return the rotated head
    return head;
}

// Optimal Approach
// Algorithm
// When we rotate a linked list to the right by k positions, each node is effectively shifted forward k steps. Instead of performing k individual rotations, we observe that rotating a list by its own length results in the same list. So, we only need to rotate by k % length. We first compute the length of the list and connect the last node to the head, forming a circular linked list. Then we locate the new tail, which is at length - (k % length) steps from the start. The node next to this becomes the new head, and we break the circular link there. This transforms the list in a single traversal, making the process efficient.
// Handle edge cases where the list is empty, has one node, or k is 0 — in these cases, return head as-is.
// Traverse the list to calculate its total length.
// Connect the last node to the first node, converting the list into a circular linked list.
// Calculate effective rotations as k % length to avoid unnecessary full rotations.
// Find the new tail node, which is located at the (length - k % length - 1)th position from the start.
// Set the new head to the node just after the new tail.
// Break the circular link by setting newTail.next = null.
// Return the new head of the rotated list.

// Time Complexity: O(N), We perform a single traversal to calculate the length, another to find the new tail, and one for final breaking all linear operations.
// Space Complexity: O(1),No extra space is used; we just adjust pointers in place.

Node* findKthnode(Node* temp, int k){
    int cnt = 1;
    while(temp != nullptr){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateright(Node* head, int k){
    if(head==nullptr || k==0) return head;

    Node* tail = head;
    int len=1;

    while(tail->next != nullptr){
        len++;
        tail = tail->next;
    }

    if(k%len == 0) return head;

    k %= len;
    
    tail->next = head;
    Node* newNode = findKthnode(head, len - k);

    head = newNode->next;
    newNode->next = nullptr;

    return head;

}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;

    Node* head = convettoLL(arr);
    printll(head);
    cout<<"null"<<endl;
    
    head = rotateright(head, x);
    cout<<"after rotating"<<endl;
    printll(head);
    cout<<"null"<<endl;


    return 0;
}