#include<bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<int>&s, int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, target);
    s.push(temp);
}

void reverseIt(stack<int> &s){

    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();

    reverseIt(s);

    insertAtBottom(s, target);

}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack(s);

    reverseIt(s);

    printStack(s);

    return 0;
}