#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node *next1, Node *back1)
    {
        data = val;
        next = next1;
        back = back1;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int lengthDLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *convertToDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);

        mover->next = temp;
        temp->back = mover;

        mover = temp;
    }

    return head;
}

// Brute Force Approach
// Algorithm
// A brute-force approach involves replacing data in a doubly linked list. First, we traverse the list and store node data in a stack. Then, in a second pass, we assign elements from the stack to nodes, ensuring a reverse order replacement since stacks follow the Last-In-First-Out (LIFO) principle.
// Initialization a temp pointer to the head of the doubly linked list and a stack data structure to store the values from the list.
// Traverse the doubly linked list with the temp pointer and while traversing push the value at the current node temp onto the stack. Move the temp to the next node continuing until temp reaches null indicating the end of the list.
// Reset the temp pointer back to the head of the list and in this second iteration pop the element from the stack, replace the data at the current node with the popped value from the top of the stack and move temp to the next node. Repeat this step until temp reaches null or the stack becomes empty.

// Time Complexity : O(2N), During the first traversal, each node's value is pushed into the stack once, which requires O(N) time. Then, during the second iteration, the values are popped from the stack and used to update the nodes.
// Space Complexity : O(N), This is because we are using an external stack data structure. At the end of the first iteration, the stack will hold all N values of the doubly linked list therefore the space required for stack is directly proportional to the size of the input doubly linked list.

// Node* reverseDLL(Node* head) {
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }

//     stack<int> st;

//     Node* temp = head;

//     while (temp != nullptr) {
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     temp = head;

//     while (temp != nullptr) {
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }

//     return head;
// }

// Optimal Approach
// Algorithm
// Instead of performing two separate traversals of the linked list and storing its node values in an external data structure, we can optimize our approach by directly modifying the links between the nodes within the doubly linked list We need to traverse on every node, and for every node change the next pointer and back pointer. If we can do this for all nodes, at the end of traversal, the doubly linked list will be reversed.
// Initialise two pointers that are needed for the reversal. Initialize a current pointer to the head of the linked list. This pointer will traverse the list as we reverse it. Initialize a second pointer last to null. This pointer will be used for temporary storage during pointer swapping, as we need a third variable while swapping two data.
// Traverse through the DLL by looping over all the nodes.
// While iterating over all nodes in the linked list, we make changes to set the backward pointer of a node to the next changing its previous link. Along with this, the forward pointer is adjusted to point to the previous node, reversing the next link. To prevent losing the last node in this process, we use a reference to the last node to retain it.
// Update the current node's back pointer to point to the next node (current->back = current->next). This step reverses the direction of the backward pointer.
// Update the current node's next pointer to point to the previous node (current->next = last). This step reverses the direction of the forward pointer.
// Move the current pointer one step forward (current = current->back). This allows us to continue the reversal process.
// After completing the traversal, the last node ends up at the second node in the reversed doubly linked list. To obtain the new head of the reversed list, we simply use the backward pointer of the last node, which points to the new head.
// To ensure that we handle the case where the traversal ended at the original list's end (i.e., the last pointer is not null), we update the head pointer to point to the new head of the reversed list, which is stored in the last pointer.
// Finally, we return the head pointer, now pointing to the head of the fully reversed doubly linked list.

// Time Complexity : O(N) We only have to traverse the doubly linked list once, hence our time complexity is O(N).
// Space Complexity : O(1), as the reversal is done in place.

Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* curr = head;
    Node* last = nullptr;

    while (curr != nullptr) {
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;

        curr = curr->back;         
    }

    return last->back;
}


int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = convertToDLL(arr);

    cout << endl << "Doubly Linked List Initially: " << endl;
    printDLL(head);

    head = reverseDLL(head);

    cout << endl << "Doubly Linked List After Reversing: " << endl;
    printDLL(head);


    return 0;
}