#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }
    Node*newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }
    Node*newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node*head){
    if(!head){
        return;
    }
    Node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool isCircular(Node*&head){
    Node*temp = head->next;
    while(temp){
        if(temp==head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    Node*head = NULL, *tail = NULL;
    Node*one = new Node(10);
    Node*two = new Node(20);
    Node*three = new Node(30);
    Node*four = new Node(40);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = one;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);    

    if(isCircular(head)){
        cout<<"Circular Linked List\n";
    }
    else{
        cout<<"Linear Linked List\n";
    }
    if(isCircular(one)){
        cout<<"Circular Linked List\n";
    }
    else{
        cout<<"Linear Linked List\n";
    }

    return 0;
}