#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


int listLen(Node*head){
    int len = 0;
    Node*temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node*&head, Node*&tail, int data){
    if(!head){
        Node*newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node*newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*&head, Node*&tail, int data){
    if(!head){
        Node*newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node*newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(int posi, Node*&head, Node*&tail, int data){
    if(posi<=1){
        insertAtHead(head, tail, data);
        return;
    }
    if(posi>=listLen(head)){
        insertAtTail(head, tail, data);
        return;
    }
    Node *temp = head;
    while(posi>1){
        temp = temp->next;
        posi--;
    }
    Node * newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node*&head){
    Node*temp = head;
    head = head->next;
    temp->next = NULL;

    delete temp;
}

void deleteAtTail(Node*&head, Node*&tail){
    if(!head || !head->next){
        deleteAtHead(head);
        return;
    }
    Node*temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = NULL;
    delete temp;
}

void deleteAtPosition(int posi, Node* head, Node*tail){
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
    Node *temp = curr->next;
    curr->next = curr->next->next;
    temp->next = NULL;
    delete temp;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void deleteNAfterM(Node*&head, int n, int m){
    int len = listLen(head);
    if(!head || !head->next)
        return;
    if(len<=m)
        return;
    Node*curr = head, *del = head;

    while(curr){
        for(int i=1;i<m && curr!=NULL;i++)
            curr = curr->next;
        if(!curr || !curr->next)
            return;
        del = curr->next;   
        for(int i=0;i<n && del!=NULL;i++){
            Node *temp = del;
            curr->next = del->next;
            temp->next = NULL;
            delete temp;
            del = curr->next;
        }
        curr = curr->next;
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    Node *head = NULL, *tail = NULL;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    //insertAtTail(head, tail, 8);
    printList(head);
    deleteNAfterM(head, n, m);
    printList(head);
    return 0;
}