#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    Node(int val, Node* next1, Node* prev1){
        data = val;
        next = next1;
        prev = prev1;
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
        temp->prev = mover;

        mover = temp;
    }

    return head;
}

Node* DeleteHead(Node* head){
    Node* new
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convertToDLL(arr);

    printDLL(head);
    cout << endl;

    cout << "Length is " << lengthDLL(head) << endl;


    return 0;
}