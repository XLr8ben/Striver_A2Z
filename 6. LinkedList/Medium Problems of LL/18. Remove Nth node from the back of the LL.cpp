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
// The simplest way to delete the Nth node from the end is to delete the (L-N+1)th node from the start of the linked list, where L is the total length of the linked list. Therefore, this problem can be broken down into two sub-problems:
// The first part involves the calculation of the length of the linked list.
// The second part involves the deletion of the (L-N+1)th node from the start of the linked list.
// If N equals 1, this means we have to delete the tail of the linked list.
// If N equals the length of the linked list, we have to delete the head of the linked list.
// To calculate the length and delete the node we can follow the following steps:
// Initialize a temp pointer that will be used to traverse the list. Create a counter and increment it for every node while traversing.
// When the pointer reaches null, counter will store the length of linked list.
// To delete the (L-N+1)th node of the linked list, create a new temp pointer to the head. Initialize a variable res to L-N, and start iterating the linked list while decrementing res at each node. Once res equals 0, we know that temp will be pointing to the (L-N)th node, therefore, stop the traversal.
// To create a new link, point the (L-N)th node to the (L-N+2)th node of the linked list, effectively skipping the (L-N+1)th node.
// Finally, free up the memory being occupied by the (L-N+1)th node, thus deleting this node.

// Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
// Space Complexity: O(1), constant additional space is used.

// Node *deleteNthNodeFromEnd(Node *head, int N)
// {
//     // If list is empty, return NULL
//     if (head == NULL) return NULL;

//     int cnt = 0;
//     Node *temp = head;

//     // Count the number of nodes in the linked list
//     while (temp != NULL){
//         cnt++;
//         temp = temp->next;
//     }

//     // If N equals the total number of nodes, delete the head
//     if (cnt == N){
//         Node *newHead = head->next;
//         // free memory
//         delete head;
//         return newHead;
//     }

//     // Calculate the position from start to delete
//     int res = cnt - N;
//     temp = head;

//     // Traverse to the node just before the one to delete
//     while (temp != NULL)
//     {
//         res--;
//         if (res == 0) break;
//         temp = temp->next;
//     }

//     // Delete the target node
//     Node *delNode = temp->next;
//     temp->next = temp->next->next;
//     delete delNode; // free memory

//     return head;
// }

// Optimal Approach
// Algorithm
// The brute force, in the worst case, has a time complexity of O(2*L), where L is the length of the linked list. Therefore, it is not the most efficient algorithm, as we are traversing the entire list twice.

// To enhance efficiency, we will involve two pointers, a fast pointer and a slow pointer. The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer. After which, both of them will move one step at a time. When the fast pointer reaches the last node, i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.
// Initialize two pointers, slow and fast, to the head of the linked list. Initially, only fast will move till it crosses N nodes, after which both of the pointers will move simultaneously.
// Traverse the linked list till the fast pointer reaches the last node, that is, the Lth Node, at this stage, the slow pointer is guaranteed to be at the (L-N)th node.
// Point this slow pointer to the (L-N+2)th node, effectively skipping the Nth node from the end or the (L-N+1)th node from the start.
// Finally, free up the space occupied by this to delete it.

// Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
// Space Complexity: O(1), constant additional space is used to check unique elements.

Node* deleteNthNodeFromEnd(Node* head, int N) {

    Node* slow = head;
    Node* fast = head;

    for (int i = 0; i < N; i++) {
        fast = fast->next;
    }

    if(fast == nullptr) return head->next;

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* deleteNode = slow->next;
    slow->next = slow->next->next;

    delete(deleteNode);

    return head;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int N;
    cin >> N;

    Node* head = convettoLL(arr);

    cout << "Original List: ";
    printll(head);
    cout << "null\n";

    head = deleteNthNodeFromEnd(head, N);

    cout << "After Deletion: ";
    printll(head);
    cout << "null\n";

    return 0;
}