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

// Approach
// Algorithm
// For reversing nodes in a linked list in groups of size k. Instead of flipping the whole list, we break it into groups of k nodes and reverse each group separately. If any group at the end has fewer than k nodes, we just leave it as is. To make this easier to understand and implement, we break the process into 3 helper functions:

// reverseLinkedList: Reverses a linked list segment using the basic 3-pointer method (prev, curr, next). You reverse pointers one by one until the whole segment is flipped.
// getKthNode: Given a starting node, it walks forward k steps and returns the k-th node. If fewer than k nodes exist, it returns null. This helps us slice the list into group of size k.
// kReverse: The main function that keeps calling getKthNode to find valid k-sized segments, reverses them using reverseLinkedList, and connects everything back together.
// Start with a dummy node pointing to the head of the list to simplify edge cases.
// Set a pointer groupPrev to dummy (this keeps track of the end of the previous reversed group).
// While there are at least k nodes remaining:
// Use getKthNode from groupPrev to find the end of the current k-sized group.
// If getKthNode returns null (less than k nodes left), break the loop.
// Keep track of the next group’s start using kth.next.
// Temporarily break the link after the k-th node so we can reverse this segment cleanly.
// Call reverseLinkedList on the current group’s head to reverse this k-segment.
// Connect the previous group’s tail (groupPrev) to the head of the reversed segment.
// Connect the tail of the reversed segment to the start of the next group.
// Update groupPrev to point to the tail of the reversed segment.
// Once done, return the new head of the list (i.e., dummy.next).

Node* getKthNode(Node* temp, int k){
    k--;
    while(k>0 && temp!=nullptr){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseLL(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;

        prev = temp;    
        temp = front;
    }
    return prev;
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp = head;
    Node* prevLast = nullptr;

    while(temp!=nullptr){
        Node* kthNode = getKthNode(temp, k);
        if(kthNode == nullptr){
            if(prevLast) prevLast->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;

        reverseLL(temp);

        if(temp == head) head = kthNode;
        else prevLast->next = kthNode;

        prevLast = temp;
        temp = nextNode;
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

    int x;
    cin>>x;

    Node* head = convettoLL(arr);
    printll(head);
    cout<<"null"<<endl;
    
    head = kReverse(head, x);
    cout<<"after reversing"<<endl;
    printll(head);
    cout<<"null"<<endl;


    return 0;
}