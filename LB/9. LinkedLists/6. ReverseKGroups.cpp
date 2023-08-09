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

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

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

Node* reverseLLRecI(Node*&prev, Node*&curr){
           //base case
        if(curr == NULL) 
                return prev;

        Node* forward = curr ->next;
        curr ->next = prev;
        //recursion sambhal lega
        return reverseLLRecI(curr, forward);
}

Node* reverseK(Node*&head, int k){
   if(!head || !head->next){
      return head;
   }
   Node*prev = NULL, *curr = head, *next, *forward;

   while(k>0 && curr){   
      next = curr->next;
      if(k==1){
         forward = next;
         // cout<<"next->next->data: "<<next->next->data<<endl;
         cout<<"forward->data: "<<forward->data<<endl;
      }

      curr->next = prev;
      prev = curr;
      curr = next;
      k--;
   }
   Node* klist = prev;
   while(klist->next){
      klist = klist->next;
   } 
   cout<<"klist->data: "<<klist->data<<endl;
   cout<<"forward->data: "<<forward->data<<endl;
   klist->next = reverseK(forward,k);
   return prev;
}

Node* reverseLLRecII(Node*&head){
    if(!head || !head->next){
        return head;
    }
    Node*smallHead = reverseLLRecII(head->next);
    Node*c = head;
    c->next->next = c;
    c->next = NULL;
    
    return smallHead;
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

int main(){
   Node *head = NULL, *tail = NULL;
   insertAtTail(head, tail, 10);
   insertAtTail(head, tail, 20);
   insertAtTail(head, tail, 30);
   insertAtTail(head, tail, 40);
   // insertAtTail(head, tail, 50);
   // insertAtTail(head, tail, 60);
   // insertAtTail(head, tail, 70);

   printList(head);

   Node* prev = NULL;
   Node* curr = head;

   head = reverseK(head, 3);
   printList(head);

   //  head = reverseLLIter(head);
   //  printList(head);
  
   //  head = reverseLLRecI(prev, head);
   //  printList(head);
   //  head = reverseLLRecII(head);
   //  printList(head);

   //  head = reverseLLRecI(prev, head);
   //  printList(head);
   //  head = reverseLLRecII(head);
   //  printList(head);


    return 0;
}