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


// Algorithm
// The goal of this problem is to rearrange the linked list so that all even-valued nodes appear before all odd-valued nodes, while preserving the original relative order within both groups. A common beginner's mistake is to try swapping values or reshuffling nodes manually, which leads to broken links or excessive pointer juggling.

// Instead, the optimal and clean approach is to use two separate lists one for even nodes and another for odd nodes. We iterate through the original list once, appending each node to the appropriate list (even or odd) based on its value. Finally, we link the last node of the even list to the head of the odd list, effectively merging the two while maintaining the required order.
// Initialize two dummy nodes to serve as heads of two separate linked lists one for even and one for odd nodes.
// Keep two pointers that will track the last node in each of these even and odd lists.
// Traverse the original linked list node by node.
// If a node has an even value, append it to the end of the even list using the even pointer.
// If a node has an odd value, append it to the end of the odd list using the odd pointer.
// Move the pointer forward in the original list after each assignment.
// After the traversal ends, connect the last node of the even list to the head of the odd list.
// Make sure the end of the odd list points to null to prevent loops.
// Return the head of the new list, which is the next node after the dummy even head.

// Time Complexity: O(n), We traverse the entire linked list only once to rearrange the nodes. Each node is visited exactly once. No nested traversal or re-traversal occurs. Hence, linear time in terms of the number of nodes n.
// Space Complexity: O(1), We do not use any extra data structures



// Node* SegregatetoOddEVen(Node* head) {
    
//     vector<int> arr;
//     Node* temp = head;

//     while(temp!= nullptr && temp->next != nullptr){
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }

//     if(temp) arr.push_back(temp->data);

//     temp = head->next;
//     while(temp!= nullptr && temp->next != nullptr){
//         arr.push_back(temp->data);
//         temp = temp->next->next;
//     }

//     if(temp) arr.push_back(temp->data);

//     int i=0;
//     temp = head;

//     while(temp!=nullptr){
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }

//     return head;
// }


Node* SegregatetoOddEVen(Node* head) {

    if(head == nullptr || head->next == nullptr) return head;

    Node* odd = head;
    Node* even = head->next;
    
    Node* evenHead = head->next;
    
    while(even != nullptr && even->next != nullptr){
        odd->next  = odd->next->next;
        even->next  = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

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

    head = SegregatetoOddEVen(head);

    cout << "After Segregation: ";
    printll(head);
    cout << "null\n";

    return 0;
}