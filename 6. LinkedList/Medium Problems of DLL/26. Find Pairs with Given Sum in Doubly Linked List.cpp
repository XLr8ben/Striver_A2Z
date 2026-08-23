#include <iostream>
#include <vector>
#include <stack>

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

//two pointer approach
//left and right pointer and shrinking them.

void findPairs(Node* head, int sum){
    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    vector<vector<int>> ans;

    Node* left = head;
    Node* right = temp;


    while(left != right && left->back != right){
        if((left->data + right->data) == sum){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < sum) left = left->next;
        else right = right->back;
    }

    for (auto& ele : ans)
    {
        cout << "{ " << ele[0] << ", " << ele[1] << " }" << endl;
    }

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

    int x;
    cin>>x;

    Node *head = convertToDLL(arr);

    cout << endl << "Doubly Linked List Initially: " << endl;
    printDLL(head);

    cout<<endl;

    findPairs(head, x);

    // cout << endl << "Pairs of given sum: " << endl;
    // printDLL(head);


    return 0;
}