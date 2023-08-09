#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node*next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

bool isLooped(Node*head){
    if(!head || !head->next){
        return false;
    }
    Node* slow = head, *fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
    }
    return false;
}

int main(){
    Node*head = NULL, *tail = NULL;
    Node*one = new Node(10);
    Node*two = new Node(20);
    Node*three = new Node(30);
    Node*four = new Node(40);
    Node*five = new Node(40);
    Node*six = new Node(40);
    Node*seven = new Node(40);
    Node*eight = new Node(40);
    Node*nine = new Node(40);
    Node*ten = new Node(40);
    Node*eleven = new Node(40);
    Node*twelve = new Node(40);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = eleven;
    eleven->next = twelve;

    if(isLooped(one)){
        cout<<"Loop Found!\n";
    }
    else{
        cout<<"No Loops :D\n";
    }

    return 0;
}