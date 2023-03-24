#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int d){
            data = d;
            next = NULL;
        }
};


void insertAtHead(node*&head, int data){
    node* n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node*&head, int data){
    if(!head){
        insertAtHead(head, data);
        return;
    }
    node*n = new node(data);
    node*temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
}

int length(node*head){
    int len=0;
    node*temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtMiddle(node*&head, int data, int pos){
    if(pos<=1||!head){
        insertAtHead(head, data);
        return;
    }
    if(pos>length(head)){
        insertAtTail(head, data);
        return;
    }

    node*n = new node(data);
    node*temp = head;
    while(pos>2){
        temp = temp->next;
        pos--;
    }
    node*temp2 = temp->next;
    temp->next = n;
    n->next = temp2;
}

void deleteAtHead(node*&head){
    node*temp = head;
    head = head->next;
    temp->next=NULL;
    delete temp;
}

void deleteAtTail(node*&head){
    if(!head->next){
        deleteAtHead(head);
        return;
    }
    node*temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    node*temp2 = temp->next;
    temp->next = NULL;
    temp2->next = NULL;
    delete temp2;
}

void deleteAtMiddle(node*&head, int pos){
    if(pos<=1){
        deleteAtHead(head);
    }
    if(pos>length(head)){
        deleteAtTail(head);
    }
    node*temp = head;
    while(pos>2){
        temp = temp->next;
        pos--;
    }
    node*temp2 = temp->next->next;
    node*del = temp->next;
    temp->next = temp2;
    delete del;
}
bool searchIter(node*head, int key){
    if(!head){
        return false;
    }
    while(head){
        if(head->data == key)
            return true; 
        head = head->next;
    }
    return false;
}

bool searchRec(node*head, int key){
    if(!head){
        return false;
    }
    if(head->data == key){
        return true;
    }
    return searchRec(head->next, key);
}

void printList(node*head){
    node *temp = head;
    while(temp){
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<"->";
        temp = temp->next;
    }
}

void createList(node*&head){
    int x;
    cin>>x;
    while(x!=-1){
        insertAtTail(head, x);
        cin>>x;
    }
}

istream& operator >>(istream &is, node*&head){
    createList(head);
    return is;
}

ostream& operator <<(ostream &os, node*&head){
    printList(head);
    return os;
}

void reverseListIter(node*&head){

    node*curr,*prev,*next;
    prev=NULL;
    curr = head;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;   
    }
    head = prev;
}

node* findMidpoint(node*head){
    node*slow = head;
    node*fast = head;

    while(fast->next->next && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* reverseListRec(node*head){
    if(!head || !head->next){
        return head;
    }
    node*small = reverseListRec(head->next);
    node*temp = head;
    temp->next->next = temp;
    temp->next = NULL;
    return small;
}

node* findNthFromEnd(node*head, int n){
    node*fast = head;
    node*slow = head;

    while(n>1){
        fast = fast->next;
        n--;
    }
    while(fast->next && fast){
        slow = slow->next;
        fast = fast->next;
        
    }
    return slow;
}




node* mergeLists(node* head1, node* head2){
    
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    node*merged;
    if(head1->data < head2->data){
        merged = head1;
        cout<<merged->data<<endl;
        merged->next = mergeLists(head1->next, head2);
    }
    else{
        merged = head2;
        cout<<merged->data<<endl;
        merged->next = mergeLists(head1, head2->next);
    }
    return merged;
}

node* mergeSort(node*head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*mid = findMidpoint(head);
    node* first = head;
    cout<<"F: "<<first->data;
    node* last = mid->next;
    cout<<"\t|\tL: "<<last->data<<endl;
    mid->next = NULL;

    first = mergeSort(first);
    last = mergeSort(last);

    node* merged = mergeLists(first, last);
    return merged;
}

int main(){
    // node*head1= NULL, *head2 = NULL;
    // cin>>head1>>head2;
    // cout<<head1<<endl;
    // cout<<head2<<endl;
    // cout<<endl;
    // node* merged = mergeLists(head1, head2);
    // cout<<merged;
    // insertAtHead(head, 6);
    // insertAtHead(head, 5);
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtTail(head, 7);
    // insertAtMiddle(head, 10, 7);
    // // deleteAtMiddle(head, 7);
    // cout<<head<<endl;
    // reverseListIter(head);
    // cout<<endl;
    // cout<<head<<endl;
    // cout<<endl;
    // head = reverseListRec(head);
    // cout<<head<<endl;
    // // if(searchIter(head, 1))
    // //     cout<<"\nFOUND\n";
    // // else    
    // //     cout<<"\nNOT FOUND\n";

    // //     if(searchRec(head, 1))
    // //     cout<<"\nFOUND\n";
    // // else    
    // //     cout<<"\nNOT FOUND\n";
    // cout<<"Midpoint: "<<findMidpoint(head)<<endl;
    // cout<<"8th Element from end: "<<findNthFromEnd(head, 8)<<endl;

    node*head = NULL;
    cin>>head;
    cout<<"MIDPOINT: "<<findMidpoint(head)->data<<endl;
    cout<<"SORTED: "<<mergeSort(head);
    return 0;
}