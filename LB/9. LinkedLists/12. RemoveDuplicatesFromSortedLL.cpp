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

Node* reverseLLIter(Node*&head){
    if(!head || !head->next){
        return head;
    }

    Node*prev =  NULL;
    Node*curr = head, *next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}


bool isPalindrome(Node*&head){
    if(!head)
        return false;
    if(!head->next)
        return true;

    Node*mid = midpoint(head);
    Node*temp1 = head,*temp2 = mid->next;
    temp2 = reverseLLIter(temp2);
    while(temp2){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

void removeDuplicates(Node*&head){
    // 1st identify if
    if(!head || !head->next){
        return;
    }
    Node*temp = head;

    while(temp->next){
        if(temp->data == temp->next->data){
            Node* dup = temp->next;
            temp->next = dup->next;
            dup->next = NULL;
            delete dup; 
        }
        else{
            temp = temp->next;
        }
    }
}

int main(){
    Node*head = NULL, *tail = NULL;
    Node*one = new Node(10);
    Node*two = new Node(20);
    Node*three = new Node(20);
    Node*four = new Node(30);
    Node*five = new Node(30);
    Node*six = new Node(30);
    Node*seven = new Node(40);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    // Node*mid = midpoint(one);
    // cout<<"mid->data: "<<mid->data<<endl;

    printList(one);
    removeDuplicates(one);
    printList(one);
    if(isPalindrome(one)){
        cout<<"PALINDROME!\n";
    }
    else{
        cout<<"NOT PALINDROME!\n";
    }

    return 0;
}