#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node *next1, Node *back1)
    {
        data = val;
        next = next1;
        back = back1;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int lengthDLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *convertToDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);

        mover->next = temp;
        temp->back = mover;

        mover = temp;
    }

    return head;
}

Node *DeleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* newTail = temp->back;
    newTail->next = nullptr;
    temp->back = nullptr;

    delete temp;

    return head;
}

Node* removeKthEle(Node* head, int k){
    if(head==nullptr) return nullptr;

    int cnt=0;
    Node* temp = head;

    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev==nullptr && front==nullptr) return nullptr;

    else if(prev == nullptr) return DeleteHead(head);

    else if(front == nullptr) return deleteTail(head);

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;

    delete temp;

    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front==nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return; 
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;

    delete temp;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = convertToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);
    cout << endl;

    cout << "Length = " << lengthDLL(head) << endl;

    head = DeleteHead(head);
    cout << "After deleting head: ";
    printDLL(head);
    cout << endl;

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printDLL(head);
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = removeKthEle(head, k);
    cout << "After deleting " << k << "th node: ";
    printDLL(head);
    cout << endl;

    deleteNode(head->next);
    cout << "After deleting second node: ";
    printDLL(head);
    cout << endl;


    return 0;
}