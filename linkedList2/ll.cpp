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

void insertAtHead(int d, node*&head){
    node* newNode = new node(d);
    newNode->next = head;
    head = newNode;

}

void insertAtTail(int d, node*&head){
    if(!head){
        insertAtHead(d, head);
        return;
    }
    node* newNode = new node(d);
    node* tail = head;
    while(tail->next){
        tail=tail->next;
    }
    tail->next = newNode;
}

int length(node*head){
    int len = 0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

void insertAtMiddle(int d, node*&head, int pos){

    if(pos<=1){
        insertAtHead(d, head);
        return;
    }   
        
    if(pos>=length(head)){
        insertAtTail(d, head);
        return;
    }
        
    node*prev = head;
    while(pos-2 > 0){
        prev = prev->next;
        pos--;
    }
    node* newNode = new node(d);
    newNode->next = prev->next;
    prev->next = newNode;
}

void print(node*head){
    while(head){
        cout<<head->data;
        if(head->next)
            cout<<"->";
        head = head->next;
    }
}

void deleteAtHead(node*&head){
    if(!head){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(node*&head){
    if(!head){
        return;
    }
    if(!head->next){
        deleteAtHead(head);
        return;
    }
    node*temp = head;
    while(temp->next->next){
        temp = temp->next;        
    }
    node*deleteIt = temp->next;
    delete deleteIt;
    temp->next = NULL;
}

void deleteAtMiddle(node*&head, int pos){
    if(pos<=1){
        deleteAtHead(head);
        return;
    }
    if(pos>=length(head)){
        deleteAtTail(head);
        return;
    }

    node*temp = head;
    while(pos-2>0){
        temp = temp->next;
        pos--;
    }
    node*deleteIt=temp->next;
    temp->next = deleteIt->next;
    deleteIt->next = NULL;
    delete deleteIt; 
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

void createList(node*&head){
    int n;
    cin>>n;
    while(n!=-1){
        insertAtTail(n, head);
        cin>>n;
    }
}

istream& operator >> (istream&is, node*&head){
    createList(head);
    return is;
}

ostream& operator << (ostream&os, node*&head){
    print(head);
    return os;
}

node* reverseList(node*&head){
    node*prev = NULL;
    node*curr = head;
    node*next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

node* reverseListRec(node*&head){
    if(!head||!head->next){
        return head;
    }
    node* smallHead = reverseListRec(head->next);
    node* curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallHead; 
}

int midpoint(node*head){
    node*slow = head;
    node*fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;  
    }
    return slow->data;
}

int kthFromEnd(node*head, int k){
    node*slow = head;
    node*fast = head;
    while(k){
        fast = fast->next;
        k--;
    }
    while(fast){
        slow = slow->next;
        fast = fast->next;
        //cout<<slow->data<<"->";
    }
    //cout<<endl;
    return slow->data;
}

node* mergeIter(node*head1, node*head2){
    node*final = NULL;
    if(!head1)
        final = head1;
    
    if(!head2)
        final = head2;
    
    if(head1->data>=head2->data){
        final = head2;
        head2 = head2->next;
    }
    else if(head1->data<=head2->data){
        final = head1;
        head1 = head1->next;
    }
    cout<<final->data<<endl;
    while(head1 && head2){
        cout<<"working\n";
        if(head1->data>=head2->data){
            final->next = new node(head2->data);
            final = final->next;
            head2 = head2->next;
        }
        else if(head1->data<=head2->data){
            final->next = new node(head1->data);
            final = final->next;
            head1 = head1->next;
        }
        cout<<final->data<<endl;
    }
    while(head1){
        final->next = new node(head2->data);
        final = final->next;
        head1->next= head1;
        cout<<final->data<<endl;
    }
    while(head2){
        final->next = new node(head1->data);
        final = final->next;
        head2->next= head2;
        cout<<final->data<<endl;
    }

    return final;
}

node* mergeRec(node* head1, node*head2){    
    node*final = NULL;
    
    if(!head1)
        return head2;
    
    if(!head2)
        return head1;
    
    if(head1->data <= head2->data){
        final = head1;
        final->next = mergeRec(head1->next, head2);
        cout<<final->data<<" ";
    }
    else{
        final = head2;
        final->next = mergeRec(head1, head2->next);
        cout<<final->data<<" ";
    }
    cout<<endl;
    return final;
}


node* mergeSort(node*head){

}

int main(){
    node* head = NULL;
    node* head2 = NULL;
    // insertAtHead(5, head);
    // insertAtHead(4, head);
    // insertAtHead(3, head);
    // insertAtHead(2, head);
    // insertAtHead(1, head);
    cin>>head>>head2;
    cout<<head<<endl<<head2<<endl;
    // insertAtTail(6, head);
    // insertAtTail(7, head);
    // insertAtTail(8, head);
    // insertAtTail(9, head);
    // insertAtTail(10, head);
    // insertAtTail(11, head);
    // insertAtMiddle(20, head, 5);
    // deleteAtMiddle(head, 3);
    // node*temp2 = mergeRec(head, head2);
    // cout<<temp2<<endl;
    node*temp = mergeIter(head, head2);    
    cout<<temp<<endl;
    // head = reverseListRec(head);
    // cout<<head<<endl<<head2<<endl;
    // cout<<"MIDPOINT: "<<midpoint(head)<<endl;
    // int k = 2;
    // cout<<k<<"th from END: "<<kthFromEnd(head, k)<<endl;
    // cout<<length(head)<<endl;
    // if(searchRec(head, -1))
    //     cout<<"Found\n";
    // else
    //     cout<<"Not Found\n";
    return 0;
}

