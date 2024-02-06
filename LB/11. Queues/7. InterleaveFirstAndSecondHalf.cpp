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

void interleave(queue<int>&q1){
    int n = q1.size();
    if(n<=2){
        return; 
    }
    queue<int> q2;
    int mid = n/2;
    int count = 0;
    bool isOdd = n&1;
    if(isOdd){
        mid++;
    } 
    while(count<mid){
        q2.push(q1.front());
        q1.pop();
        count++;
    }

    if(n==3){
        q1.push(q2.front());
        q2.pop()
    }

    cout<<"Q1 AFTER WHILE ITER "<<count<<": ";printQueue(q1);cout<<endl;
    cout<<"Q2 AFTER WHILE ITER "<<count<<": ";printQueue(q2);cout<<endl;

    int c =  1;
    while(!q1.empty() && !q2.empty()){
        cout<<"COUNT :"<<c<<endl;
        cout<<"Q1 AFTER WHILE ITER "<<count<<": ";printQueue(q1);cout<<endl;
        cout<<"Q2 AFTER WHILE ITER "<<count<<": ";printQueue(q2);cout<<endl;
        int first = q2.front();
        q2.pop();
        q1.push(first);
        int second = q1.front();
        q1.pop();
        q1.push(second);
        if(isOdd && q2.size()==1)
            break;
   }
//    if(n&1){
//         q1.push(q1.front());
//         q1.pop();
   // }
   
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    // q.push(90);
    interleave(q);

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