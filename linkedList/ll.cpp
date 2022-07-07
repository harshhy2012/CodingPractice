
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

void print(node*head){
    while(head){
        cout<<head->data;
        if(head->next)
            cout<<"->";
        
        head = head->next;
    }
    cout<<endl;
}

void insertAtBeg(int data, node*&head){
    node* n = new node(data);
    n->next = head;
    head = n;
}

void insertAtEnd(int data, node*&head){
    if(!head){
        insertAtBeg(data, head);
        return;
    }
    node*tail = head;
    while(tail->next)
        tail = tail->next;
    tail->next = new node(data);
}

int ListSize(node*head){
    int len = 0;
    while(head){
        head = head->next;
        len++;
    }
    return len;
}

void insertAtMiddle(int data, node*&head, int pos){
    if(pos<=1){
        insertAtBeg(data, head);
        return;
    }
    cout<<ListSize(head)<<endl;
    if(pos>=ListSize(head)){
        insertAtEnd(data, head);
    }
    node*temp = head;
    while(pos-2>0){
        temp = temp->next;
        pos--;
    }
    node*n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

void deleteFromBeg(node*&head){
    node*temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(node*&head){
    node*temp = head;
    while(temp->next->next)
        temp = temp->next;
    
    delete temp->next;
    temp->next = NULL;
}

void deleteFromMiddle(int pos, node*&head){
    if(pos<=1)
        deleteFromBeg(head);
    if(pos>=ListSize(head))
        deleteFromEnd(head);
    
    node*temp = head;
    while(pos-2>0){
        temp = temp->next;
        pos--;
    }
    node* delIt = temp->next;
    temp->next = temp->next->next;
    delete delIt;

}

bool searchList(int key, node*head){
    while(head){
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

bool searchListRec(int key, node*head){
    if(!head)
        return false;
    
    if(head->data == key)
        return true;
    else{
        return searchListRec(key, head->next);
    }
}

void makeList(node*&head){
    int x;
    cin>>x;
    while(x!=-1){
        insertAtEnd(x, head);
        cin>>x;
    }
}

node* reverseList(node*&head){
    if(!head || !head->next)
        return NULL;
    
    node* prev = NULL;
    node* curr = head;
    node* next;

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
    node*smallHead = reverseListRec(head->next);
    node* curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallHead;
}

node* midPoint(node*head){
    if(!head || !head->next || !head->next->next){
        return head;
    }
    node*slow = head, *fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    } 
    return slow;
}

node* KthNodeFromEnd(int k, node*head){
    node*slow,*fast;
    slow = fast = head;
    while(k){
        fast = fast->next;
        k--;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

istream& operator >> (istream&is, node*&head){
    makeList(head);
    return is;
}


ostream& operator << (ostream&is, node*&head){
    print(head);
    return is;
}

node* merge(node* list1, node*list2){
    
    node* newList = NULL;
    
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;

    if(list1->data <= list2->data){
        newList = list1;
        newList->next = merge(list1->next, list2);
    }
    else{
        newList = list2;
        newList->next = merge(list1, list2->next);
    }
    return newList;
}

bool findLoop(node*head){
    node*slow = head;
    node*fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

node* removeLoop(node*&head){
    if(!findLoop(head)){
        cout<<"No loop to remove!\n";
        return head;
    }
    node*temp = NULL;
    node*slow = head;
    node*fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            slow = head;
            break;
        }
    }
    while(fast!=slow){
        fast = fast->next;
        temp = fast;
        slow = slow->next;
    }
    temp->next = NULL;
    return head;
}

node* mergeSort(node*&head){
    if(!head || !head->next)
        return head;

    node* mid = midPoint(head);
    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}

int main(){
    node*head, *sorted;
    head = sorted = NULL;
    cin>>head;
    cout<<head;
    sorted = mergeSort(head);
    cout<<sorted;
    insertAtEnd(1,head);
    insertAtEnd(2,head);
    insertAtEnd(3,head);
    insertAtEnd(4,head);
    insertAtEnd(5,head);
    // insertAtEnd(6,head);
    // insertAtEnd(7,head);
    // insertAtEnd(8,head);
    // // insertAtEnd(9,head);
    // insertAtMiddle(10,head,7);
    // deleteFromMiddle(7,head);
    return 0;
}