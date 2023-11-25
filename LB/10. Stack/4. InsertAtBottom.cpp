#include<bits/stdc++.h>

using namespace std;

void solve(stack<int>&s, int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, target);
    s.push(temp);
}

void insertTopAtBottom(stack<int> &s){
    if(s.empty()){
        return;
    }
    solve(s, s.top());
    s.pop();
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);

    printStack(s);

    insertTopAtBottom(s);
        
    printStack(s);

    return 0;
}