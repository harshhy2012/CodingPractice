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

Node* midpoint(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node*slow = head,*fast = head->next;
    while(fast){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int listLen(Node*head){
    Node*temp = head;
    int len = 0;
    while(temp){
        temp = temp->next;
        len++;
    }
    return len;
}

Node*sort012(Node*&head){
    if(!head || !head->next){
        return head;
    }
    Node*zeroHead = new Node(-1);
    Node*zeroTail = zeroHead;
    Node*oneHead = new Node(-1);
    Node*oneTail = oneHead;
    Node*twoHead = new Node(-1);
    Node*twoTail = twoHead;
   
    Node*curr = head;
    while(curr){
        if(curr->data == 0){
            Node*temp = curr;
            curr = curr->next;
            temp->next = NULL;
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1){
            Node*temp = curr;
            curr = curr->next;
            temp->next = NULL;
            oneTail->next = temp;
            oneTail = temp;
        }
        else{
            Node*temp = curr;
            curr = curr->next;
            temp->next = NULL;
            twoTail->next = temp;
            twoTail = temp;
        }   
    }
    
    //  join the three lists;
    Node*temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;
    
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead){
        zeroTail->next = oneHead;
        if(twoHead){
            oneTail->next = twoHead;
        }
    }
    else{
        if(twoHead){
            zeroTail->next = twoHead;
        }
    }

    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    head = zeroHead;
    // remove dummy nodes;

    return head;
}



int main(){
    Node*head = NULL, *tail = NULL;
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    cout<<"unsorted: ";printList(head);
    head = sort012(head);
    cout<<"sorted: ";printList(head);
    return 0;
}