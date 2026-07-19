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

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head == nullptr) return new Node(val);

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}

Node* insertPos(Node* head, int ele, int k){
    if(head == nullptr){
        if(k==1) return new Node(ele);
        else return nullptr;
    }

    if(k==1) return new Node(ele, head);

    int cnt=0;

    Node* temp = head;

    while(head != nullptr){
        cnt++;
        if(cnt==(k-1)){
            Node* x = new Node(ele, temp->next);
            temp->next = x;
            break;
        } 
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head, int ele, int val){
    if(head == nullptr) return nullptr;

    if(head->data == val) return new Node(ele, head);

    Node* temp = head;

    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* x = new Node(ele, temp->next);
            temp->next = x;
            break;
        }
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
    cout<<"null"<<endl;

    cout << "\nAfter inserting head\n";
    head = insertHead(head, x);
    printll(head);
    cout << "null\n";

    cout << "\nAfter inserting tail\n";
    head = insertTail(head, x);
    printll(head);
    cout << "null\n";

    cout << "\nAfter adding K\n";
    head = insertPos(head, x, 3);
    printll(head);
    cout << "null\n";

    cout << "\nAfter adding Ele\n";
    head = insertBeforeVal(head, x, 3);
    printll(head);
    cout << "null\n";


    return 0;
}