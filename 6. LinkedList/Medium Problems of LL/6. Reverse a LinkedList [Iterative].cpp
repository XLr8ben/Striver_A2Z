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
// A straightforward approach to reversing a singly linked list is to use an additional data structure such as a stack. As we traverse the list, we push each node’s value onto the stack. Since stacks follow Last-In-First-Out (LIFO) order, popping elements from the stack gives us the values in reverse order. After the stack is filled, we reassign the values to the nodes while traversing the original list again. This effectively reverses the list in terms of values without modifying node links.
// Create an empty stack to store the node values of the original linked list.
// Traverse the linked list using a temporary pointer. For each node, push its value onto the stack.
// Reset the temporary pointer to the head of the list.
// While the stack is not empty, pop a value and assign it to the current node’s value. Move the pointer to the next node.
// Once the traversal is complete, return the head of the modified linked list.

// Time Complexity: O(N) ,We traverse the linked list twice once to push all node values into the stack, and once to reassign values. Each traversal takes O(N) time, where N is the number of nodes.
// Space Complexity: O(N) , We use an extra stack to store all the node values, which requires O(N) additional space.

Node* reverseLL(Node* head) {
    Node* temp = head;
    stack<int> st;


    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
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