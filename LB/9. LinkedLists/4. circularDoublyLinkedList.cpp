#include<bits/stdc++.h>

using namespace std;

class Node{
public: 
    int data;
    Node*prev;
    Node*next;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

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

void insertAtHead(Node*&head ,Node*&tail, int data){
    if(!head){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    head->prev = tail;
}

void insertAtTail(Node*&head ,Node*&tail, int data){
    if(!head){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = head;
    head->prev = tail;
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
    while(posi>2){
        temp = temp->next;
        posi--;
    }

    Node*newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp->next->prev;
    temp->next->prev = newNode;
    temp->next = newNode;
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

void printListReverse(Node*head, Node*tail){
    if(!head){
        return;
    }
    if(!tail->prev){
        cout<<tail->data<<endl;
        return;
    }
    cout<<tail->data<<" ";
    Node*temp = tail->prev;
    while(temp!=head->prev){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

void deleteAtHead(Node*&head, Node*&tail){
    Node*temp = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    temp->prev = temp->next = NULL;
    delete temp;
}

void deleteAtTail(Node*&head, Node*&tail){
    Node*temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    temp->prev = temp->next = NULL;
    delete temp;
}
void deleteAtPosition(int posi, Node*&head, Node*&tail){
    if(posi<=1){
        deleteAtHead(head, tail);
        return;
    }
    if(posi>=listLen(head, tail)){
        deleteAtTail(head, tail);
        return;
    }
    Node*curr = head;
    while(posi>2){
        curr = curr->next;
        posi--;
    }
    Node*temp = curr->next;
    Node*nextTemp =  temp->next;
    curr->next = nextTemp;
    nextTemp->prev = curr;
    temp->prev = temp->next = NULL;
    delete temp;
}

int main(){
    Node*head = NULL, *tail = NULL;
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 80);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtPosition(4,head, tail, 101);
    cout<<"Normal: ";printList(head, tail);
    cout<<"Reversed: ";printListReverse(head, tail);
    deleteAtHead(head, tail);
    cout<<"Normal: ";printList(head, tail);
    cout<<"Reversed: ";printListReverse(head, tail);
    deleteAtTail(head, tail);
    cout<<"Normal: ";printList(head, tail);
    cout<<"Reversed: ";printListReverse(head, tail);
    deleteAtPosition(3, head, tail);
    cout<<"Normal: ";printList(head, tail);
    cout<<"Reversed: ";printListReverse(head, tail);
    
    return 0;
}