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
// Since the list is sorted in non-decreasing order, any duplicates will always be adjacent.Compare each node with the next node. If they have the same value, skip the duplicate node (and delete it).
// Start at the head of the list and traverse until the temp node and the next node are not null.
// If the next node has the same value as the temp node:
// Move forward until you find a node with a different value.
// Delete all the duplicate nodes in between.
// Link the temp node to the first different node found.
// If the next node has a different value, move to the next node.
// Continue this process until the end of the list and return the head of the modified list.

// Time Complexity: O(n), Every node is visited exactly once.
// Space Complexity: O(1), No extra space is used.

Node* removeDuplicates(Node* head) {
    if (!head) return nullptr;

    Node* temp = head;

    while (temp != nullptr && temp->next != nullptr) {
        Node* nextNode = temp->next;

        while (nextNode != nullptr && nextNode->data == temp->data) {
            Node* duplicateNode = nextNode;
            nextNode = nextNode->next;
            delete duplicateNode;
        }

        temp->next = nextNode;
        if (nextNode != nullptr) nextNode->back = temp;

        temp = temp->next;
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

    cout<<endl;

    head = removeDuplicates(head);

    cout << endl << "After removing duplicates: " << endl;
    printDLL(head);


    return 0;
}