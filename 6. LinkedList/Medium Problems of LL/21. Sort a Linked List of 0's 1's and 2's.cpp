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

//brute force
// taking 3 variables and storing cnt of 0,1,2
// then replacing the ll->data till cnt reaches 0

// Node* sortZeroOneTwo(Node* head){
//     Node* temp = head;
//     int cnt0=0, cnt1=0, cnt2=0;

//     while(temp != nullptr){
//         if(temp->data == 0) cnt0++;
//         else if(temp->data == 1) cnt1++;
//         else cnt2++;

//         temp = temp->next;
//     }

//     temp = head;

//     while(temp != nullptr){
//         if(cnt0){
//             cnt0--;
//             temp->data = 0;
//         }
//         else if(cnt1){
//             cnt1--;
//             temp->data = 1;
//         }
//         else{
//             cnt2--;
//             temp->data = 2;
//         }

//         temp = temp->next;
//     }

//     return head;
// }

// Approach
// Algorithm
// Instead of sorting by swapping data values, we need to rearrange the actual links. The key insight is to maintain three separate chains for 0's, 1's, and 2's, then connect them at the end.
// We traverse the original list once, and for each node:
// If value is 0, add it to the "zero's" chain
// If value is 1, add it to the "one's" chain
// If value is 2, add it to the "two's" chain
// Finally, we connect zero's chain to one's chain and then one's chain to two's chain
// Handle edge cases where any chain might be empty

// Time Complexity: O(n), We traverse the entire list once.
// Space Complexity: O(1), Only dummy nodes and pointers are used (constant space).

Node* sortZeroOneTwo(Node* head){
    if(head==nullptr || head->next==nullptr) return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while (temp) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node * newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
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

    head = sortZeroOneTwo(head);

    cout << "After Sorting: ";
    printll(head);
    cout << "null\n";

    return 0;
}