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

int listLen(Node*head){
    int len = 0;
    Node*temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
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

Node* reverseList(Node*&head){
    if(!head || !head->next){
        return head;
    }
    Node* prev = NULL, *curr = head, *next;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
Node* reverseListRecI(Node*&prev, Node*&curr){
    if(!curr){

    }
    Node*forward = curr->next;
    curr->next = prev;
    prev = curr;
    return  reverseListRecI(curr, forward);
}

Node* reverseListRecII(Node*&head){
    if(!head || !head->next){
        return head;
    }
    Node* smallHead = reverseListRecII(head->next);
    Node* c = head;
    c->next->next = c;
    c->next = NULL;
    return smallHead;
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

Node* sum(Node*num1head, Node*num2head){

    num1head = reverseListRecII(num1head);
    num2head = reverseListRecII(num2head);

    int carry = 0;
    Node* sumHead = NULL, *sumTail = NULL;
    while(num1head && num2head){
        int digSum = num1head->data+num2head->data+carry;
        carry = digSum/10;
        digSum = digSum%10;
        insertAtHead(sumHead, sumTail, digSum);
        num1head = num1head->next;
        num2head = num2head->next;
    }
    while(num1head){
        int digSum = num1head->data+carry;
        carry = digSum/10;
        digSum = digSum%10;
        insertAtHead(sumHead, sumTail, digSum);
        num1head = num1head->next;
    }
    while(num2head){
        int digSum = num2head->data+carry;
        carry = digSum/10;
        digSum = digSum%10;
        insertAtHead(sumHead, sumTail, digSum);
        num2head = num2head->next;
    }
    return sumHead;
}

int main(){
    Node*num1head = NULL, *num1tail = NULL, *num2head = NULL, *num2tail = NULL;
    insertAtTail(num1head, num1tail, 1);
    insertAtTail(num1head, num1tail, 1);
    insertAtTail(num1head, num1tail, 1);
    insertAtTail(num1head, num1tail, 1);
    // num1 =  7998
    insertAtTail(num2head, num2tail, 8);
    insertAtTail(num2head, num2tail, 9);
    insertAtTail(num2head, num2tail, 9);
    // num2 =   899
    Node*ans = sum(num1head, num2head);
    // ans =   8897
    printList(ans);
    return 0;
}