#include <iostream>
#include <vector>

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

Node* deleteHead(Node* head){
    if(head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next==nullptr) return nullptr;

    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* removeK(Node* head, int x){
    if(head == nullptr) return nullptr;

    if(x==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;

    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){
        cnt++;
        if(cnt == x){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEle(Node* head, int x){
    if(head == nullptr) return head;

    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){
        if(temp->data == x){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
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

    int x;
    cin>>x;

    Node* head = convettoLL(arr);

    printll(head);
    cout << "null" << endl;

    cout << "\nAfter deleting head\n";
    head = deleteHead(head);
    printll(head);
    cout << "null\n";

    cout << "\nAfter deleting tail\n";
    head = deleteTail(head);
    printll(head);
    cout << "null\n";

    cout << "\nAfter removing K\n";
    head = removeK(head, x);
    printll(head);
    cout << "null\n";

    cout << "\nAfter removing Ele\n";
    head = removeEle(head, x);
    printll(head);
    cout << "null\n";


    return 0;
}