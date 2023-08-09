#include<bits/stdc++.h>

using namespace std;

class Node{
    public: 
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int listLen(Node*head){
    Node*temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtPosition(int posi, Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(posi<=1){
        insertAtHead(head, tail, data);
        return;
    }
    if(posi>=listLen(head)){
        insertAtTail(head, tail, data);
        return;
    }
    Node* curr = head;  
    while(posi>1){
        curr = curr->next;
        posi--;
    }
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;
}

void deleteAtHead(Node*&head){
    if(!head){
        return;
    }
    Node*temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node*&head, Node*&tail){
    if(!head || !head->next){
        deleteAtHead(head);
        return;
    }
    Node*temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void deleteAtPosition(int posi, Node*&head, Node*&tail){
    if(!head || !head->next){
        deleteAtHead(head);
        return;
    }
    if(posi<=1){
        deleteAtHead(head);
        return;
    }
    if(posi>=listLen(head)){
        deleteAtTail(head, tail);
        return;
    }
    Node*curr = head;
    while(posi>2){
        curr = curr->next;
        posi--;
    }
    Node*temp = curr->next;
    curr->next = curr->next->next;
    curr->next->next->prev = curr;
    temp->next = NULL;
    temp->prev = NULL;
    
    delete temp;
}


void printList(Node*head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void printListReverse(Node*tail){
    while(tail){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL, *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    
    printList(head);
    printListReverse(tail);
    // insertAtTail(head, tail, 50);
    // insertAtTail(head, tail, 60);
    // insertAtTail(head, tail, 70);
    // insertAtTail(head, tail, 80);

    // printList(head);
    // deleteAtTail(head, tail);
    // // deleteAtPosition(8, head, tail);

    // printList(head);
    // printListReverse(tail);

    return 0;
}