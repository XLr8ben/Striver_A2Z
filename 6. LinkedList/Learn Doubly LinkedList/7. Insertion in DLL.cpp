#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node* next1, Node* back1){
        data = val;
        next = next1;
        back = back1;
    }
};

void printDLL(Node* head) {
    Node* temp = head;

    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int lengthDLL(Node* head) {
    Node* temp = head;
    int cnt = 0;

    while (temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* convertToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);

        mover->next = temp;
        temp->back = mover;

        mover = temp;
    }

    return head;
}

string searchEle(Node* head, int x) {
    Node* temp = head;

    while (temp) {
        if (temp->data == x)
            return "Found";
        temp = temp->next;
    }

    return "Not Found";
}

Node* insertBeforeHead(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }

    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head == nullptr){
        return new Node(val);
    }

    if(head->next == nullptr){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforeKthEle(Node* head, int k, int val){
    if(head == nullptr) return nullptr;

    if(k == 1){
        return insertBeforeHead(head, val);
    }

    int cnt = 1;
    Node* temp = head;

    while(temp != nullptr && cnt < k){
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr){
        return head;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    if(node == nullptr || node->back == nullptr) return;

    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
}


int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convertToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);
    cout << endl;

    cout << "Length = " << lengthDLL(head) << endl;

    int x;
    cout << "Enter element to search: ";
    cin >> x;
    cout << searchEle(head, x) << endl;

    
    int val;
    cout << "Enter value to insert before head: ";
    cin >> val;
    head = insertBeforeHead(head, val);
    cout << "After inserting before head: ";
    printDLL(head);
    cout << endl;

    
    cout << "Enter value to insert before tail: ";
    cin >> val;
    head = insertBeforeTail(head, val);
    cout << "After inserting before tail: ";
    printDLL(head);
    cout << endl;

    
    int k;
    cout << "Enter k and value to insert before kth node: ";
    cin >> k >> val;
    head = insertBeforeKthEle(head, k, val);
    cout << "After inserting before " << k << "th node: ";
    printDLL(head);
    cout << endl;

    cout << "Inserting 999 before the 3rd node..." << endl;
    insertBeforeNode(head->next->next, 999);

    cout << "After inserting before 3rd node: ";
    printDLL(head);
    cout << endl;


    return 0;
}