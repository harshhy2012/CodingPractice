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

vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    vector<int> criticalPoints;
    if(!head || !head->next || !head->next->next){
        return {-1,-1};
    }
    ListNode*prev = head, *curr = head->next, *forward;
    int len = 1;
    while(forward){
        if(curr->next!=NULL){
            forward = curr->next;
        }
    
        if(curr->next==NULL){
            break;
        }
       
        if(prev && forward){
            if(prev->val < curr->val && forward->val < curr->val)
                criticalPoints.push_back(len);
            else if(prev->val > curr->val && forward->val > curr->val)
                criticalPoints.push_back(len);
        }
        // cout<<"CriticalPoints: ";
        // for(auto i: criticalPoints){
        // cout<<i<<" ";
        // }
        cout<<endl;

        prev = curr;
        curr = forward;
        len++;
    }

  
    
    for(auto i: criticalPoints){
        cout<<"posi: "<<i<<endl;
    }
    
    
    int minDist = INT_MAX, maxDist = INT_MIN;
    if(criticalPoints.size()<2)
        minDist = maxDist = -1;
    
    else if(criticalPoints.size()==2)
        minDist = maxDist = criticalPoints[criticalPoints.size()-1] - criticalPoints[0];
    else{
        vector<int>mins;
        for(int i=0;i<criticalPoints.size()-1;i++)
        mins.push_back(criticalPoints[i+1]-criticalPoints[i]);
        for(int i=0;i<mins.size();i++){
            minDist = min(minDist,mins[i]);
        }
        maxDist = criticalPoints[criticalPoints.size()-1] - criticalPoints[0];
    }
        


    return {minDist, maxDist};
}

int main(){
    ListNode*head = NULL, *tail = NULL;
    // 1,3,2,2,3,2,2,2,7
    // 2,3,3,2
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 5);
    // insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 7);

    printList(head);  
    vector<int> ans = nodesBetweenCriticalPoints(head);
    cout<<"ANS: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}