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

// Brute-Force Approach
// Algorithm
// A loop in a linked list occurs when there's a node that, when followed, brings you back to it, indicating a closed loop in the list. Hence it's important to keep track of nodes that have already been visited so that loops can be detected. One common way to do this is by using hashing.

// Traverse the entire linked list using a temporary pointer.
// While traversing, keep a track of the visited nodes in the map data structure.
// If a previously visited node is encountered again, that proves that there is a loop in the linked list hence return true.
// If the traversal is completed, and we reach the last point of the list which is null, it means there was no loop, hence we return false.
// Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

// Time Complexity: O(N*LogN), we traverse the entire linked list once and store and retrieve nodes from the hash map. Map operations have a worst time space complexiy of O(LogN).
// Space Complexity: O(N) , additional amount of extra space is used to store nodes in a hash map.

// bool detectLoop(Node* head) {
//     Node* temp = head;

//     unordered_map<Node*, int> nodeMap;

//     while (temp != nullptr) {
//         if (nodeMap.find(temp) != nodeMap.end()) return true;
//         nodeMap[temp] = 1;

//         temp = temp->next;
//     }

//     return false;
// }

// Optimal Approach
// Algorithm
// The earlier approach of using a hash map requires extra memory, which becomes costly when the linked list is very large. To optimize space, we use the Tortoise and Hare Algorithm (Floyd’s Cycle Detection). If the list contains a loop, both pointers will eventually enter the cycle.
// Since the hare is faster, it covers more distance and will eventually overtake the tortoise inside the loop, leading to a meeting point. On the other hand, if the list has no loop, the hare will simply reach the end, and the algorithm terminates without any meeting.
// To detect a cycle using the Tortoise and Hare method, we start by initializing two pointers, slow and fast, at the head of the linked list.
// The slow pointer moves forward one step at a time, while the fast pointer advances two steps at a time.
// If the fast pointer or its next becomes null, it means the end of the linked list has been reached. In this case, there is no loop, and the list is linear.
// If the slow and fast pointers eventually meet at the same node, it confirms that a cycle exists in the linked list.
// Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

// Time Complexity: O(N), we traverse the entire linked list once. The fast pointer either reaches the end of the list or meets the slow pointer in linear time.
// Space Complexity: O(1) , constant amount of extra space is used detect a cycle using Floyd's Cycle Detection Algorithm.

bool detectLoop(Node* head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
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

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head->next;
    
    bool f = detectLoop(head);
    cout << (f ? "true" : "false");
    
    return 0;
}