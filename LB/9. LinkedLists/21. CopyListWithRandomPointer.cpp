#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

void printListRandom(Node* head){
    while(head){
        if(head && head->random)
            cout<<head->random->data<<" ";
        else
            cout<<"NULL ";
        head = head->next;
    }
    cout<<endl;
}


Node* copyRandomList(Node* head) {
    if(!head)
        return head;
    Node* headIter = head;
    Node*newHead = new Node(headIter->data);
    unordered_map<Node*,Node*> bind;
    bind[headIter] =  newHead;
    headIter = headIter->next;
    Node*newTail = newHead;
    while(headIter){
        Node*temp = new Node(headIter->data);
        bind[headIter] = temp;
        newTail->next = temp;
        newTail = newTail->next;
        headIter = headIter->next;
    }
    headIter = head;
    newTail = newHead;
    while(headIter){
        newTail->random = bind[headIter->random];
        headIter = headIter->next;
        newTail = newTail->next; 
    }
    return newHead;
}

Node* copyRandomListII(Node* head) {
    if(!head)
        return head;
    
    Node* It = head;
    Node*newNode = new Node(It->data);
    while(It){
        Node*newNode = new Node(It->data);
        newNode->next = It->next;
        It->next = newNode;
        It = It->next->next;
    }
    It = head;

    while(It){
        Node* cloned = It->next;
        cloned->random = It->random ? It->random->next : nullptr;
        It = It->next->next;
    }

    It = head;
    Node* newList = It->next;
    while(It){
        Node*clone = It->next;
        It->next = It->next->next;
        if(clone->next){
            clone->next = clone->next->next;
        }
        It = It->next;
    }
    return newList;
}

int main(){
    
    Node*one = new Node(7);
    Node*two = new Node(13);
    Node*three = new Node(11);
    Node*four = new Node(10);
    Node*five = new Node(1);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    one->random = five->next;
    two->random = one;
    three->random = five;
    four->random = three;
    five->random = one;

    printList(one);
    printListRandom(one);

    Node*deepCopy = copyRandomList(one);

    printList(deepCopy);
    printListRandom(deepCopy);

    return 0;
}