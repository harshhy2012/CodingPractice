#include<bits/stdc++.h>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode*next;

        ListNode(int data){
            this->val = data;
            this->next = NULL;
        }
};

void insertAtHead(ListNode*&root, int data){
    if(!root){
        return;
    }

    ListNode* newHead = new ListNode(data);
    newHead->next = root;
    root = newHead;
    return;
}

void insertAtTail(ListNode*&root, int data){
    if(!root)
        return;

    ListNode*temp = root;
    while(temp->next){
        temp=temp->next;
    }
    ListNode*newTail = new ListNode(data);
    temp->next = newTail;
    newTail->next = NULL;
}

int length(ListNode*root){
    if(!root){
        return 0;
    }
    return 1+length(root->next);
}

void insertAtPosition(ListNode*&root, int data, int pos){
    if(pos <=1 || !root){
        insertAtHead(root, data);
        return;
    }
    if(pos >= length(root)){
        insertAtTail(root, data);
        return;
    }
    ListNode* newNode = new ListNode(data);
    ListNode* temp = root;
    while(pos>2){
        temp = temp->next;
        pos--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromHead(ListNode*&root){
    if(!root){
        return;
    }
    ListNode*delHead = root;
    root = root->next;
    delHead->next = NULL;
    delete(delHead);
}

void deleteFromTail(ListNode*&root){
    if(!root){
        return;
    }
    ListNode* temp = root;
    while(temp->next->next && temp->next){
        temp = temp->next;
    }
    ListNode*delNode = temp->next;
    temp->next = NULL;
    delete(delNode); 
}

void deleteFromPosition(ListNode*&root, int pos){
    if(pos <=1 || !root){
        deleteFromHead(root);
        return;
    }
    if(pos >= length(root)){
        deleteFromTail(root);
        return;
    }
    ListNode*temp = root;
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    ListNode*delNode = temp->next;
    temp->next = delNode->next;
    delNode->next = NULL;
    delete(delNode);
}

ListNode* createList(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    else{
        ListNode* newNode = new ListNode(data);
        newNode->next = createList();
    }
}

void printList(ListNode*root){
    while(root){
        cout<<root->val<<" ";
        root = root->next;
    }
    cout<<endl;
}

class Compare{
    public:
    bool operator()(ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};

ListNode* mergeKLinkedLists(vector<ListNode*>&Lists, int k){
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for(int i=0;i<k;i++){
        minHeap.push(Lists[i]);
        Lists[i] = Lists[i]->next;
    }
    ListNode* finList = new ListNode(-1);
    ListNode*iter = finList;
    while(!minHeap.empty()){
        ListNode*top = minHeap.top();
        minHeap.pop();
        iter->next = top;
        iter = top;
        if(top && top->next){
            minHeap.push(top->next);
        } 
    }
    finList = finList->next;
    return finList;
}

int main(){
    int k;
    cin>>k;
    vector<ListNode*> kList(k);
    for(auto &i: kList){
        i = createList();
    }

    ListNode*Ans = mergeKLinkedLists(kList, k);
    cout<<"MERGED LIST: ";printList(Ans);


    // printList(root);
    // insertAtHead(root, 9);
    // printList(root);
    // insertAtTail(root, 0);
    // printList(root);
    // insertAtPosition(root, 12, 6);
    // printList(root);
    // deleteFromHead(root);
    // printList(root);
    // deleteFromTail(root);
    // printList(root);
    // deleteFromPosition(root, 6);
    return 0;
}