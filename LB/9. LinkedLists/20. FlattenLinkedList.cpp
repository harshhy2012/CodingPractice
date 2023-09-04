#include<bits/stdc++.h>

using namespace std;

class Node{
    public: 
    int data;
    Node*next;
    Node*bottom;
	

    Node(){
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }

    Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
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

void printListBottom(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->bottom;
    }
    cout<<endl;
}


Node* mergeLists(Node*head1, Node*head2){
    if(!head1 && !head2){
        return NULL;
    }
    Node*newHead = new Node(-1); 
    Node*newTail = newHead;

    if(!head1){
        while(head2){
            newTail->bottom = head2;
            newTail = newTail->bottom;
            head2 = head2->bottom;
        }
        return newHead->bottom;
    }
    if(!head2){
        while(head1){
            newTail->bottom = head1;
            newTail = newTail->bottom;
            head1 = head1->bottom;
        }
        return newHead->bottom;
    }
    while(head1 && head2){
        if(head1->data >= head2->data){
            newTail->bottom = head2;
            newTail = newTail->bottom;
            head2 = head2->bottom;
        } else{
            newTail->bottom = head1;
            newTail = newTail->bottom;
            head1 = head1->bottom;
        }
    }
    while(head1){
        newTail->bottom = head1;
        newTail = newTail->bottom;
        head1 = head1->bottom;
    }
    while(head2){
        newTail->bottom = head2;
        newTail = newTail->bottom;
        head2 = head2->bottom;
    }
    newHead = newHead->bottom; 
    return newHead;
}

Node* flattenList(Node*head){
    Node *flatListHead = NULL;

    if(!head){
        return NULL;
    }
    while(head){
        flatListHead = mergeLists(flatListHead, head);
        printListBottom(flatListHead);
        head = head->next;
    }

    return flatListHead;
}

int main(){
    //Node*head = NULL, *tail =  NULL;
    Node*one = new Node(5);
    Node*two = new Node(10);
    Node*three = new Node(19);
    Node*four = new Node(28);
    
    Node*one1 = new Node(7);
    Node*one2 = new Node(8);
    Node*one3 = new Node(30);

    Node*two1 = new Node(20);

    Node*three1 = new Node(22);
    Node*three2 = new Node(50);

    Node*four1 = new Node(35);
    Node*four2 = new Node(40);
    Node*four3 = new Node(45);

    one->bottom = one1;
    one1->bottom = one2;
    one2->bottom = one3;

    two->bottom = two1;

    three->bottom = three1->bottom;
    three1->bottom = three2;

    four->bottom = four1;
    four1->bottom = four2;
    four2->bottom = four3;

    one->next = two;
    two->next = three;
    three->next = four;

    Node*flatList = flattenList(one);
    printListBottom(flatList);

    return 0;
}