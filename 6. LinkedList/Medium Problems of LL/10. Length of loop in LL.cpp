#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

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
// While traversing the linked list, employ a timer against each node to keep track of the number of nodes you've visited before it. Once a previously visited node is encountered again, the length of the loop can be determined by subtracting the timer values at the two instances of visiting that particular node.
// It's important to keep track of nodes and the timer value associated with them. This can be implemented using a hashmap with nodes as the key and the timer as the value.
// Initialize a temporary pointer to head which will be used to traverse the list. While traversing, keep track of the Visited nodes and the timer value associated in the map data structure.
// Continue traversing till a node that has already been visited is found. The difference between its timer value in the hashmap and the current timers value will be the length of loop in the linked list.
// If the traversal is completed, and we reach the last point of the linked list which is null, it means there was no loop, hence we return 0.

// Time Complexity: O(N), we traverse the entire linked list atleast once to find the length of the loop.
// Space Complexity: O(N) , we use a map to store the timers for the nodes in the linked list.

// int lengthOfLoop(Node* head) {

//     unordered_map<Node*, int> mpp;
//     Node* temp = head;
//     int timer = 0;

//     while (temp != NULL) {
//         if (mpp.find(temp) != mpp.end()) {
//             int value = mpp[temp];
//             return (timer - value);
//         }

//         mpp[temp] = timer;
//         timer++;
//         temp = temp->next;
//     }
//     return 0;
// }


// Optimal Approach
// Algorithm
// The previous method uses additional memory in order to find length of the loop. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.
// Initialise two pointers, slow and fast, to the head of the linked list. Slow will advance one step at a time, while fast will advance two steps at a time. These pointers will move simultaneously.
// Traverse the linked list with the slow and fast pointers. While traversing, repeatedly move slow one step and fast two steps at a time.
// Continue this traversal until either fast (or next node of fast) reaches null or both the pointers, slow and fast, meet.
// This is the point where the slow and fast have met proving that there is a loop in the linked list. From here onwards we start counting for the length of this loop.
// Initialise a counter with zero and traverse the linked list using the slow pointer again while incrementing the counter with each node visited.
// As the slow pointer reaches back at the fast pointer, the value of the counter will represent the length of the loop.

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return countLoopLength(slow, fast);
    }

    return 0;
}

int countLoopLength(Node* slow, Node* fast) {
    Node* fast = fast->next;
    int cnt = 1;

    while (slow != fast) {
        cnt++;
        fast = fast->next;
    }
    return cnt;
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
    
    int len = lengthOfLoop(head);
    cout<<"lengthOfLoop"<<len<<endl;
    cout<<"null"<<endl;


    return 0;
}