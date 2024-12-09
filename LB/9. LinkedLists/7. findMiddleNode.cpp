#include<bits/stdc++.h>

using namespace std;

class ListNode{
public:
    int val;
    ListNode*next;

    ListNode(){
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int data){
        this->val = data;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*&head, ListNode*&tail, int val){
    if(!head){
        ListNode *newNode = new ListNode(val);
        head = newNode;
        tail = newNode;
        return;
    }
    ListNode *newNode = new ListNode(val);
    tail->next = newNode;
    tail = newNode;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* middleNode(ListNode* head){
    ListNode*slow = head;
    ListNode*fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

ListNode* middleNode(ListNode* head, int n){
ListNode *temp = head;
    int x = n / 2;
    while (x > 0)
    {
        temp = temp->next;
        x--;
    }
    return temp;
}


int main(){
    ListNode *head = NULL, *tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    // insertAtTail(head, tail, 50);
    // insertAtTail(head, tail, 60);
    // insertAtTail(head, tail, 70);
    // insertAtTail(head, tail, 80);
    printList(head);
    ListNode*mid = middleNode(head);
    cout<<"midNode: "<<mid->val<<endl;
    printList(mid);
    return 0;
}