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

int lengthLL(Node* head){
    Node* temp = head;
    int cnt=0;

    while(temp){
        cnt++;
        temp = temp->next;    
    }
    return cnt;
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

string Searchele(Node* head, int x){
    Node* temp = head;
    
    while(temp){
        if(temp->data == x) return "Found";
        temp = temp->next;
    }
    return "Not Found";
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

    cout<<"Lenght is "<<lengthLL(head)<<endl;

    cout<<Searchele(head, 2);


    return 0;
}