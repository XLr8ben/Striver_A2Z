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

// Optimal Approach
// Algorithm
// The core idea is to change the next pointers of the nodes one by one so that they point backward instead of forward. By maintaining references to the current node, its previous node, and the next node, we can safely rewire the links without losing track of the list. Once all links are reversed, the last node of the original list becomes the new head.
// Initialize a traversal pointer at the head of the linked list.
// Also initialize a pointer for the previous node and set it to NULL.
// Repeat the following steps until the traversal pointer reaches the end:
// Save the next node in a temporary pointer.
// Reverse the `next` pointer of the current node to point to the previous node.
// Move the previous pointer to the current node.
// Advance the traversal pointer to the next node (saved earlier).
// Once the traversal is complete, return the previous node as the new head of the reversed list.

// Time Complexity: O(N) Because we are traversing each node of the linked list exactly once. Each pointer reversal is done in constant time.
// Space Complexity: O(1) We are not using any additional data structure or recursion. All modifications are done in-place using pointers.

// Node* reverseLL(Node* head) {
//     Node* temp = head;
//     Node* prev = nullptr;

//     while (temp != NULL) {
//         Node* front = temp->next;
//         temp->next = prev;

//         prev = temp;    
//         temp = front;
//     }
//     return prev;
// }

// Recursive Approach
// Algorithm
// Before diving into this approach, make sure your concepts of recursion are solid. Recursion lets us break a problem into smaller subproblems and solve them incrementally. It continues doing this until it hits the base case, the smallest instance of the problem. From there, it starts combining the results of the subproblems to solve the original task.

// In the case of reversing a singly linked list: We're reducing the problem from reversing N nodes to reversing N - 1, N - 2, and so on. When we hit the base case (1 node), we start wiring the reversed nodes back together.

// For example, if the list has 4 nodes:
// Recursion works down from 4 → 3 → 2 → 1.
// Then it rewires the links backward starting from node 1.
// Base Case: If the head is null or there’s only one node, it’s already reversed. So, just return the head.
// Recursive Step: Call the same function to reverse the rest of the list starting from head.next. This recursive call gives back the new head of the reversed sublist.
// Store Reference: Before breaking any link, store the next node (say front) so we don’t lose access to it.
// Reverse the Link: Now, set front.next = head. This flips the direction of the link — making the next node point back to the current one.
// Break the Old Link: To avoid cycles, disconnect the original forward link by doing head.next = null.
// Return the New Head: Finally, return the newHead received from the recursive call — it’s now the head of the reversed list.

// Time Complexity: O(n),Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).
// Space Complexity: O(n),The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLL(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
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
    
    head = reverseLL(head);
    cout<<"after reversing"<<endl;
    printll(head);
    cout<<"null"<<endl;


    return 0;
}