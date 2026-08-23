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

// Approach
// Algorithm
// Create a dummy node that will act as the starting point of the new linked list.
// Create a temporary pointer and set it to the dummy node.
// Start with a carry value of 0.
// Loop through both linked lists until you reach the end of both, or until there is no carry left.
// At each step, add the values of the current nodes and the carry.
// Update the carry by dividing the total by 10.
// Create a new node with the last digit of the total (total % 10) and attach it to the next of the temporary pointer, then move the temporary pointer forward.
// Move both list pointers to their next nodes.
// After the loop ends, return the next node of the dummy (this is the head of the result list).
// The dummy node is used to make the code easier. Without it, extra conditions would be needed to handle the first node.

// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node *dummy = new Node(-1); 
    Node *temp = dummy; 

    int carry = 0;

    while( (l1 != NULL || l2 != NULL) || carry) {
        int sum = 0; 
        if(l1 != NULL) {
            sum += l1->data; 
            l1 = l1 -> next; 
        }
        
        if(l2 != NULL) {
            sum += l2 -> data; 
            l2 = l2 -> next; 
        }
        //Carry gets added to sum in the node (carry=sum/10)
        sum += carry; 
        carry = sum / 10; 
        Node* newNode = new Node(sum % 10); 
        temp -> next = newNode; 
        temp = temp -> next; 
    }
    return dummy -> next; 
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

    int n2;
    cin >> n2;

    vector<int> arr2(n2);

    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    Node* head2 = convettoLL(arr2);

    cout << "Original List: ";
    printll(head2);
    cout << "null\n";
    
    Node* newHead = addTwoNumbers(head, head2);

    cout << "After adding: ";
    printll(newHead);
    cout << "null\n";

    return 0;
}