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
// The starting point of a loop of the linked list is the first node we visit twice during its traversal. It's the point where we realise that we are no longer moving forward in the list but rather entering a cycle.
// Traverse through the linked list by assigning a temporary node to the head and moving to the next node repeatedly until reaching null.
// While traversing, keep a record of visited nodes using a map data structure.
// Storing the entire node in the map is necessary to differentiate between nodes with the same value but different positions, ensuring proper detection of cycles instead of just duplicates.
// If a node already exists in the map, this confirms a loop, and we return that node as the starting point of the loop.
// If the traversal reaches the end of the list (null), it means no loop exists, so return null.

// Time Complexity: O(N) where N is the number of nodes in the linked list. Each node is visited only once during traversal. Hashing allows O(1) lookup to check for previously visited nodes.
// Space Complexity: O(N) due to the additional hash set used to store visited nodes. In the worst case (no cycle), all N nodes will be stored in the hash set.

// Node* startingPointLL(Node* head) {
//     Node* temp = head;

//     unordered_map<Node*, int> nodeMap;

//     while (temp != nullptr) {
//         if (nodeMap.find(temp) != nodeMap.end()) return temp;
//         nodeMap[temp] = 1;

//         temp = temp->next;
//     }

//     return nullptr;
// }

// Optimal Approach
// Algorithm
// The previous method uses O(N) additional memory, which can become quite large as the linked list length grows. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.

// The Tortoise and Hare approach has been discussed in this article. The key insight is that when the slow and fast pointers meet inside the loop, the distance travelled by each pointer can be used to calculate the starting point of the loop.
// Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time, while `fast` will advance two steps at a time. These pointers will move simultaneously.
// Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and `fast` two steps at a time.
// Continue this traversal until one of the following conditions is met:
// `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop in the linked list, and the algorithm terminates by returning null.
// `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list.
// Reset the `slow` pointer to the head of the linked list. Move `fast` and `slow` one step at a time until they meet again. The point where they meet again is the starting point of the loop.
// You may be curious about the proof for this algorithm, and it hinges on the idea that the point where the slow and fast pointers converge can be leveraged to determine the starting point of the loop.
// In the "tortoise and hare" algorithm for detecting loops in a linked list, when the slow pointer (tortoise) reaches the starting point of the loop, the fast pointer (hare) is positioned at a point that is twice the distance travelled by the slow pointer. This is because the hare moves at double the speed of the tortoise.
// If slow has travelled distance L1 then fast has travelled 2 x L1. Now that slow and fast have entered the loop, the distance fast will have to cover to catch up to slow is the total length of loop minus L1. Let this distance be d. Distance travelled by slow = L1 Distance travelled by fast = 2 * L1 Total length of loop = L1 + d
// In this configuration, the fast pointer advances toward the slow pointer with two jumps per step, while the slow pointer moves away with one jump per step. As a result, the gap between them decreases by 1 with each step. Given that the initial gap is d, it takes exactly d steps for them to meet.
//                         Total length of loop = L1 + d Distance between slow and fast = d 
// During these d steps, the slow pointer effectively travels d steps from the starting point within the loop and fast travels 2 x d and they meet at a specific point. Based on our previous calculations, the total length of the loop is L1 + d. And since the distance covered by the slow pointer within the loop is d, the remaining distance within the loop is equal to L1.
// Therefore, it is proven that the distance between the starting point of the loop and the point where the two pointers meet is indeed equal to the distance between the starting point and head of the linked list.

// Time Complexity: O(N) where N is the number of nodes in the linked list. In the worst case, we traverse the entire list once with the slow and fast pointers, and then again to find the entry point of the loop.
// Space Complexity: O(1) constant extra space. No additional data structures are used, only two pointers.

Node* startingPointLL(Node* head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
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
    temp->next = head->next->next;
    
    Node* startPoint = startingPointLL(head);
    cout <<"Start Point is "<<startPoint->data;
    
    return 0;
}