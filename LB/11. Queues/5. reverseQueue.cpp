#include<bits/stdc++.h>

using namespace std;

void reverseIt(queue<int>&q){
    stack<int> st;
    while(!q.empty()){
        int x = q.front();
        st.push(x);
        q.pop();
    }
    while(!st.empty()){
        int x = st.top();
        q.push(x);
        st.pop();
    }
}

void reverseItRec(queue<int>&q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverseItRec(q);
    q.push(x);
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseItRec(q);

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