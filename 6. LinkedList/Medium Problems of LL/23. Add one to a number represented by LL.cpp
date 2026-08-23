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

// Iterative approach
// Algorithm
// Since the least significant digit is at the end of the list, we can’t process it directly using a single traversal. Therefore, to perform addition from the end, we need to reverse the list.
// Reverse the list and start from the head and add 1. Carry it forward as needed.
// If a carry remains after the last node, add a new node with value 1.
// Reverse the list again to restore the original order and return the head of the modified list.

// Time Complexity: O(n), Two reversals + one pass for addition.
// Space Complexity: O(1), Iterative, no extra stack used.

// Node* reverseList(Node* node) {
//     Node* prev = nullptr;
//     Node* temp = node;

//     while (temp) {
//         Node* nextNode = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = nextNode;
//     }
//     return prev;
// }

// Node* addOne(Node* head) {
//     head = reverseList(head);

//     Node* temp = head;
//     int carry = 1;  

//     while (temp != nullptr) {
//         temp->data = temp->data + carry;

//         if(temp->data < 10){
//             carry = 0;
//             break;
//         }
//         else{
//             temp->next = 0;
//             carry = 1;
//         }
//         temp = temp->next;
//     }

//     if(carry==1){
//         Node* newNode = new Node(1);
//         head = reverseList(head);
//         newNode->next = head;
//         return newNode;
//     }

//     head = reverseList(head);
//     return head;
// }

// Recursive approach
// Algorithm
// Since the number is stored in most-significant-digit first order, it’s difficult to perform addition directly because we need to handle carry from the last digit (least significant digit). Using recursion, we can traverse to the last node first, perform the addition with carry, and propagate the carry backwards.
// Using a recursive function, traverse to the end of the linked list
// Add 1 to the last node and propagate any resulting carry backwards through the recursive calls.
// At each step, add the carry to the current node's value and update the carry.
// Once recursion completes, if a carry still remains, create a new node at the beginning of the list with value 1.
// Return the updated head of the list.

// Time Complexity: O(n), One pass for addition.
// Space Complexity: O(n), Auxiliary stack space.

int helper(Node* temp) {
    if (temp == nullptr) return 1;
    
    int carry = helper(temp->next);  
    int sum = temp->data + carry;
    
    if(sum < 10){
        temp->data = sum;
        return 0;
    }
    
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry = helper(head);

    if (carry == 1) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }

    return head;
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

    head = addOne(head);

    cout << "Adding one: ";
    printll(head);
    cout << "null\n";

    return 0;
}