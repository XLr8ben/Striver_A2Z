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

// Approach
// Algorithm
// In a doubly linked list, each node has pointers to both the previous and next nodes. To delete a node, link its previous node to its next node. If the node is the head, update the head pointer. If the node is the tail, update the prev->next and ensure no access to that node remain.
// Start from the head of the doubly linked list and traverse until you reach the end.
// For each node, if the node's value is equal to the target:
// If there is a previous node, connect the previous node to the next node.
// If there is a next node, connect the next node to the previous node.
// If the node is the head of the list, update the head to the next node.
// Delete the current node and move to the next node in the list.
// Return the updated head of the list.

// Time Complexity: O(n), Every node is visited once.
// Space Complexity: O(1), No extra space is used.

Node* deleteTargetNodes(Node* head, int target) {
    Node* temp = head;

    while (temp != nullptr) {

        if (temp->data == target) {
            if (temp == head) head = temp->next; 
            
            Node* nextNode = temp->next;
            Node* prev = temp->back;
            if(nextNode != nullptr) nextNode->back = prev;
            if(prev != nullptr) prev->next = nextNode;

            delete temp;
            temp = nextNode;
        }else{
            temp = temp->next;
        } 
    }

    return head;
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
    
    int x;
    cin>>x;
    
    Node *head = convertToDLL(arr);

    cout << endl << "Doubly Linked List Initially: " << endl;
    printDLL(head);

    head = deleteTargetNodes(head, x);

    cout << endl << "Doubly Linked List After Deleting: " << endl;
    printDLL(head);


    return 0;
}