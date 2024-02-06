#include<bits/stdc++.h>

using namespace std;

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverseKElements(queue<int>&q, int k){
    int n = q.size();
    if(k==0 || k>n)
        return; 
    stack<int> st;
    int count = 0;
    int n = q.size();
    while(count<k){
        int x = q.front();
        st.push(x);
        q.pop();
        count++;
    }

    cout<<"STACK: ";printStack(st);
    cout<<endl;
    cout<<"QUEUE: ";printQueue(q);
    cout<<endl;

    while(!st.empty()){
        int x = st.top();
        q.push(x);
        st.pop();
    }

    cout<<"STACK: ";printStack(st);
    cout<<endl;
    cout<<"QUEUE: ";printQueue(q);
    cout<<endl;

    int leftOver = n-k;
    while(leftOver && !q.empty()){
        int x = q.front();
        q.pop();
        q.push(x);
        leftOver--;
    }

    cout<<"STACK: ";printStack(st);
    cout<<endl;
    cout<<"QUEUE: ";printQueue(q);
    cout<<endl;

}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    int k;
    cin>>k;

    reverseKElements(q, k);

    cout<<"Q After Rev: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    // reverseItRec(q);

    // cout<<"Q After 2nd Rev: ";
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    // cout<<endl;
    return 0;
}