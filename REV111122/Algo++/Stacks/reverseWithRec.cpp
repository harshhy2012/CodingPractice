#include<bits/stdc++.h>

using namespace std;

void arrPush(stack<int> &stk, int x){
    if(stk.empty()){
        stk.push(x);
        return;
    }
    stack<int> temp;
    while(!stk.empty()){
        int t = stk.top();
        temp.push(t);
        stk.pop();
    }

    stk.push(x);

    while(!temp.empty()){
        int t = temp.top();
        stk.push(t);
        temp.pop();
    }

}

void reverseIt(stack<int>&stk){
    if(stk.empty()){
        return;
    }
    int top = stk.top();
    stk.pop();
    reverseIt(stk);
    arrPush(stk, top);
} 

void print(stack<int> stk){
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

int main(){

    stack<int> stk;

    for(int i=1;i<=5;i++){
        stk.push(i);
    }

    print(stk);

    reverseIt(stk);

    print(stk);
    
    return 0;
}
