#include<bits/stdc++.h>

using namespace std;

class Node {

    public:
        int data;
        Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node*&head, Node*&tail, int data){
    Node *newNode = new Node(data);
    if(!head){
        head = newNode;
        head->next = NULL;
        tail = head;
        return;
    }
    newNode->next = head;
    head = newNode;
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

Node* reverseList(Node*& head){
    if(!head || !head->next){
        return head;
    }
    Node*prev = NULL, *curr = head, *forw;

    while(curr){
        forw = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = forw;  
    }
    head = prev;
    return head;
}

void printList(Node*head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

vector<int> nextGreaterElement(Node*head){
    Node* rev = reverseList(head);
    printList(rev);
    stack<int> st;
    st.push(-1);
    vector<int>ans;
    while (rev) {
        while(!st.empty() && st.top()<=rev->data){
            st.pop();
        }

        if(st.empty()){
            st.push(-1);
        }
        //print(st);
        ans.push_back(st.top());
        st.push(rev->data);
        
        // for(auto i: ans){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        rev = rev->next;
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        if(ans[i]==-1){
            ans[i] = 0;
        }
    }
    return ans;    
}
    
int main(){
    Node*head = NULL, *tail = NULL;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 5);
 
    printList(head);
    
    vector<int> ans = nextGreaterElement(head);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}