#include<bits/stdc++.h>

using namespace std;

void print(stack<int> stk){
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> stk,stk2;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    int n = stk.size();

    print(stk);

    for(int i=n-1;i>=0;i--){
        int top = stk.top();
        stk.pop();
        int j = i;
        while(j>0){
            int x = stk.top();
            stk2.push(x);
            stk.pop();
            j--;
        }
        stk.push(top);
        while(!stk2.empty()){
            int x = stk2.top();
            stk.push(x);
            stk2.pop();
        }
    }

    print(stk);

    return 0;
}