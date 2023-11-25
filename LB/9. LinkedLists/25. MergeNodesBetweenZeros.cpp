#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        this->val = data;
        this->next = NULL;
    }
};

int listLen(ListNode*head){
    int len = 0;
    ListNode*temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(ListNode*&head, ListNode*&tail, int data){
    if(!head){
        ListNode*newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
        return;
    }
    ListNode*newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode*&head, ListNode*&tail, int data){
    if(!head){  
        ListNode*newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
        return;
    }

    ListNode*newNode = new ListNode(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(int posi, ListNode*&head, ListNode*&tail, int data){
    if(posi<=1){
        insertAtHead(head, tail, data);
        return;
    }
    if(posi>=listLen(head)){
        insertAtTail(head, tail, data);
        return;
    }
    ListNode *temp = head;
    while(posi>1){
        temp = temp->next;
        posi--;
    }
    ListNode * newNode = new ListNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(ListNode*&head){
    ListNode*temp = head;
    head = head->next;
    temp->next = NULL;

    delete temp;
}

void deleteAtTail(ListNode*&head, ListNode*&tail){
    if(!head || !head->next){
        deleteAtHead(head);
        return;
    }
    ListNode*temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = NULL;
    delete temp;
}

void deleteAtPosition(int posi, ListNode* head, ListNode*tail){
    if(posi<=1){
        deleteAtHead(head);
        return;
    }
    if(posi>=listLen(head)){
        deleteAtTail(head, tail);
        return;
    }
    ListNode*curr = head;
    while(posi>2){
        curr = curr->next;
        posi--;
    }
    ListNode *temp = curr->next;
    curr->next = curr->next->next;
    temp->next = NULL;
    delete temp;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void mergeBetweenZeros(ListNode*&head){
    if(!head){
        return;
    }
    ListNode *slow = head, *fast = head->next;
    ListNode*LastNode;
    int sum = 0;
    while(fast){
        if(fast->val!=0){
            sum+=fast->val;
        } else{
            slow->val = sum;
            LastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    LastNode->next = NULL;
    while(slow){
        deleteAtHead(slow);
    }
}

int main(){
    ListNode *head = NULL, *tail = NULL;
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    return 0;
}