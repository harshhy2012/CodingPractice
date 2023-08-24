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

Node* merge(Node*&head1, Node*&head2){
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    Node*newList, *newHead;
    if(head1->data <= head2->data){
        newList = head1;
        
        head1 = head1->next;
    }
    
    else{
        newList = head2;
        newHead = newList;
        head2 = head2->next;
    }
    
    while(head1 && head2){
        if(head1->data >= head2->data){
            newList->next = head2;
            newList = newList->next;
            head2 = head2->next;
        }
        else{
            newList->next = head1;
            newList = newList->next;
            head1 = head1->next;
        }
    }

    while(head1){
        newList->next = head1;
        newList = newList->next;
        head1 = head1->next;
    }
    while(head2){
        newList->next = head2;
        newList = newList->next;
        head2 = head2->next;
    }
    return newHead;
}

Node* mergeRec(Node*&head1, Node*&head2){
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    Node* newList;

    if(head1->data <= head2->data){
        newList = head1;
        newList->next = mergeRec(head1->next, head2);
    }
    else{
        newList = head2;
        newList->next = mergeRec(head1, head2->next);
    }

    return newList;
}

Node* middleNode(Node* head){
    Node*slow = head;
    Node*fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node* mergeSort(Node*&head){
    if(!head)
        return NULL;    
    if(!head->next)
        return head;

    Node*mid = middleNode(head);
    Node*a = head, *b = mid->next;\
    mid->next = NULL;
    cout<<"a->data: "<<a->data<<" || mid->data: "<<mid->data<<" || b->data: "<<b->data<<endl;
    Node* left = mergeSort(a);
    Node* right = mergeSort(b);
    Node*fin = merge(left,right);
    return fin;
}

int main(){
    Node*head = NULL, *tail = NULL;
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 10);
    cout<<"UnsortedList: ";printList(head);
    head = mergeSort(head);
    cout<<"SortedList: ";printList(head);
    return 0;
}