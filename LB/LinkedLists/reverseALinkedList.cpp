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
        this->data = 0;
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

Node* reverseLinkedList(Node*&head){
    if(!head){
        return NULL;
    }
    Node*temp = head->next;
    head->next = reverseLinkedList(head->next);
    temp->next = head;
    return temp;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL, *tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    printList(head);

    reverseLinkedList(head);

    printList(head);

    return 0;
}