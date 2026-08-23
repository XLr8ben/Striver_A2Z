#include <iostream>
#include <vector>
#include <stack>
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
// Using the brute force approach, the middle node of a linked list can be determined by traversing the entire linked list initially to find the total number of nodes, denoted as n. Then we reset the temporary node temp to the head of the linked list and proceed to traverse to the node positioned at index [n/2], which represents either the middle node in an odd-lengthed list or the node just before the middle node in an even-lengthed linked list.
// Traverse the linked list to count the number of nodes and store the length as n. Calculate the index of the middle node by dividing the total number of nodes by 2.
// Traverse the linked list again while keeping track of the node count to reach the middle node.
// Once reaching the middle node, delete it by setting the next pointer of the previous node directly to the node after the middle node.
// Free the memory allocated to the middle node.

// Time Complexity: O(N + N/2), we traverse the entire linked list once to count the number of nodes and then traverse again to delete the middle node.
// Space Complexity: O(1) , we have fixed number of pointers and variables to delete the Kth node.

// Node* deleteMiddle(Node* head) {
//     Node* temp = head;
//     int n = 0;
    
//     // Loop to count the number of nodes in the linked list
//     while (temp != NULL) {
//         n++;
//         temp = temp->next;
//     }
    
//     int res = n / 2;
    
//     temp = head;
    
//     while (temp != NULL) {
//         res--;
        
//         if (res == 0) {
//             Node* middle = temp->next;
            
//             temp->next = temp->next->next;
//             free(middle);
            
//             break;
//         }
        
//         temp = temp->next;
//     }
    
//     return head;
// }

// Optimal Approach
// Algorithm
// The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal. The 'slow' pointer advances one node at a time while the 'fast' pointer moves two nodes at a time. By doing so, when the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.
// Since we require `slow` to reach the node before the middle node, we give `fast` a head start!
// Check if the list is empty or contains only one node. If so, no middle node exists to delete, return NULL. Initialise 'slow' and 'fast' pointers at the head of the list.
// Move ‘fast’ two nodes ahead for the initial position as we have to reach the node previous to the middle node via slow.
// Move the 'fast' pointer two nodes ahead and the 'slow' pointer one node ahead in each iteration. Continue this process until the 'fast' pointer reaches the end of the list.
// Once the 'fast' pointer reaches the end, the 'slow' pointer will be at the middle node. Delete the middle node by skipping it from the linked list.
// Return the head of the modified linked list.

// Time Complexity: O(N/2), we traverse the entire linked list using slow and fast pointers, effectively covering about half the list before reaching the midpoint.
// Space Complexity: O(1) , we have fixed number of pointers and variables to delete the Kth node.


Node* deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next = slow->next->next;

    delete middle;

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

    head = deleteMiddle(head);

    cout << "After Deletion: ";
    printll(head);
    cout << "null\n";

    return 0;
}