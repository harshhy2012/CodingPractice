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

void insertAtHead(Node*&head ,Node*&tail, int data){
    if(!head){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->next = head;
    head = newNode;
}

int listLen(Node*head, Node*tail){
    if(!head){
        return 0;
    }
    if(!head->next){
        return 1;
    }
    Node*temp = head->next;
    int len = 1;
    while(temp!=tail->next){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtTail(Node*&head ,Node*&tail, int data){
    if(!head){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode = tail;
    tail->next = head;
}

void insertAtPosition(int posi, Node*&head, Node*&tail, int data){

    if(posi<=1){
        insertAtHead(head, tail, data);
        return;
    }
    if(posi>=listLen(head, tail) || !head){
        insertAtTail(head, tail, data);
        return;
    }

    Node*temp = head;
    while(posi>1){
        temp = temp->next;
        posi--;
    }

    Node*newNode = new Node(data);
    temp->next = newNode;
    newNode->next = temp->next->next;
}



void printList(Node*head, Node*tail){
    if(!head){
        return;
    }
    if(!head->next){
        cout<<head->data<<endl;
        return;
    }
    cout<<head->data<<" ";
    Node*temp = head->next;
    while(temp!=tail->next){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}




int main(){
    Node*head = NULL, *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 80);
    printList(head, tail);

    return 0;
}