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

Node* intersection(Node*a, Node*b){
    int lenA = listLen(a);
    int lenB = listLen(b);
    int diff = 0;
    if(lenA>lenB){
        diff = lenA-lenB;
        while(diff){
            a = a->next;
            diff--;
        }
    }
    else{
        diff = lenB-lenA;
         while(diff){
            a = a->next;
            diff--;
        }
    }
    while(a&&b){
        if(a==b){
            return a;
        }
        a = a->next;
        b = b->next;

    }
    return NULL;
}

Node* intersectionII(Node*headA, Node*headB){
    Node*a = headA,*b = headB;
    while(a && b){
        if(!a)
            break;
        a = a->next;
        if(!b)
            break;
        b = b->next;
         
    }
    cout<<"b->data: "<<b->data<<endl;
    if(!a){
        a = headB;
    }else if(!b){
        b = headA;
    }

    while(a&&b){
        if(!a)
            break;
        a = a->next;
        if(!b)
            break;
        b = b->next;  
    }

    if(!a && !b){
        a = headA;
        b = headB;
    }else if(!a){
        a = headA; 
    }
    else{
        b = headB;
    }
    
    while(a&&b){
        cout<<"a->data: "<<a->data<<" || b->data: "<<b->data<<endl;
        if(a==b){
            return a;
        }
        a = a->next;
        b = b->next;

    }
    return NULL;
}

int main(){
    // [4,1,8,4,5]
    // [5,6,1,8,4,5]
    Node*L1One = new Node(0);
    Node*L1Two = new Node(1);
    Node*L1Three = new Node(8);
    Node*L1Four = new Node(4);
    Node*L1Five = new Node(5);

    Node*L2One = new Node(7);
    Node*L2Two = new Node(6);
    Node*L2Three = new Node(3);

    L1One->next = L1Two;
    L1Two->next = L1Three;
    L1Three->next = L1Four;
    L1Four->next = L1Five;
   
    L2One->next = L2Two;
    L2Two->next = L2Three;
    L2Three->next = L1Three;

    Node* inter = intersectionII(L1One, L2One);

    cout<<"Iter->data: "<<inter->data<<endl;

    return 0;
}